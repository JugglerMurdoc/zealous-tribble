#include "tracer.h"

float truncate(float long_float){
	float new_time = long_float;
    new_time = new_time*PRECISION;
	new_time = (new_time > (floor(new_time)+0.5f)) ? ceil(new_time) : floor(new_time);
	new_time = new_time/PRECISION;
	
	return new_time;
		
}	
	
FILE * get_router_trace(int router_id){
	char buf[50];
	sprintf(buf,"%s%d.tr",ONE_ROUTER_CHARGE_FILE,router_id);
	FILE* one_router_charge_trace = fopen(buf,"w+");
	if(one_router_charge_trace == NULL){
	char buf2[50];
	sprintf(buf2,"touch %s",buf);
	one_router_charge_trace = fopen(buf,"w+");
	}
	return one_router_charge_trace;			
}	

void trace_total_waiting_packets(trace_line line, FILE* total_waiting_file,FILE* total_destroyed_file){
	
	static float precedent_time = 0;
	static int current_queue_size = 0;
	static int destroyed_size = 0;
		if(total_waiting_file == NULL){
			printf("ERROR : Couldn't open trace file\n");	
		}
		else{
			 if(line.p_type == DEP_SOURCE || line.p_type == ARR_DEST || line.p_type == DEST ){
			 float new_time = truncate(line.time);
			 if(new_time == precedent_time){
				 if(line.p_type == DEP_SOURCE){
					 current_queue_size++;
				 }else{
				 if(line.p_type == DEP_SOURCE){
					destroyed_size++;
					}
				 else{
					 
				 }
				 }
			 }else{
			 char buffer [50];
			 char buffer2 [50];
			 int test = (current_queue_size > 0)?current_queue_size:0;
			 sprintf(buffer,"%f %d\n", new_time, test);
			 fputs(buffer,total_waiting_file);
			 sprintf(buffer2,"%f %d\n", new_time, destroyed_size);
			 fputs(buffer2,total_destroyed_file);
			 current_queue_size = 0;
			 precedent_time = new_time;
		 }
		}
	}
}

void trace_routers_charge(trace_line line,global_stats* stats,int trace_routers_flag,FILE* router_file){
	 if(trace_routers_flag != -2){		
		if(trace_routers_flag == -1){	
		/*Trace de la charge de TOUS les routeurs*/			
			if(line.p_type == ARR_INT){
					int result = stats->routers[line.n_pos-1][0] + 1;
					stats->routers[line.n_pos-1][0] = result;		}
			if(line.p_type == DEST){
					int result = stats->routers[line.n_pos-1][1] + 1;
					stats->routers[line.n_pos-1][1] = result;		}
			}
			if(line.p_type == ARR_DEST){
					int result = stats->routers[line.n_src-1][2] + 1;
					stats->routers[line.n_src-1][2] = result;		}
			if(line.p_type == DEP_SOURCE){
					int result = stats->routers[line.n_src-1][3] + 1;
					stats->routers[line.n_src-1][3] = result;		}
			else{
			if((line.p_type == DEP_SOURCE) && line.n_pos == trace_routers_flag) {
				 	static float time_before = 0;
					static int current_queue_size = 0;
					float new_time = truncate(line.time);
					
					if(new_time == time_before){
						current_queue_size++;
					}else
					{
						if(router_file == NULL){
							printf("ERROR : Couldn't open trace file for single router\n");
						}else
						{
						 char buffer [50];
						 sprintf(buffer,"%f %d\n", new_time, current_queue_size);
						 fputs(buffer,router_file);
						 current_queue_size = 0;
						 time_before = new_time;
					}
			}			
			}
	}}
}



/*{DEP_SOURCE, ARR_INT, DEP_FILE, ARR_DEST, DEST}*/
int trace_packet(trace_line ex_line,int packet_id){
	static float departure_time;
	static int nb_jumps;
	float delay;
	int ex_id = ex_line.p_id;
	if(ex_id == packet_id){
		switch(ex_line.p_type){
				case(DEP_SOURCE) :
					nb_jumps = 0;
					departure_time = 0;
					departure_time = ex_line.time;
					printf("============================\n");
					printf("PACKET N° %-17d|\n",packet_id);
					printf("Source      %-15d|\n",ex_line.n_src);
					printf("Destination %-15d|\n",ex_line.n_dest);
					printf("============================\n\n");
					printf("%-4f [%d] : Departure from %d\n",departure_time,ex_line.p_type,ex_line.n_src);
					break;
				case(ARR_INT) :
					nb_jumps++;
					printf("%-4f [%d] : Entering queue in %-2d\n",ex_line.time,ex_line.p_type,ex_line.n_pos);
					break;
				case(DEP_FILE) :
					printf("%-4f [%d] : Going to %d\n",ex_line.time,ex_line.p_type,ex_line.n_pos);
					break;
				case(ARR_DEST) :
					delay = (ex_line.time - departure_time)*1000;
					printf("\n=========================\n");
					printf("%-4f: Reaches %-2d   |\n",ex_line.time,ex_line.n_dest);
					printf("Delay : %-8fms       |\n",delay);
					printf("Jumps : %-2d              |\n",nb_jumps);
					printf("=========================\n");
					return -1;
					break;
				case(DEST) :
					printf("\n============================\n");
					printf("%-4f: DESTRUCTION  in %-2d|\n",ex_line.time,ex_line.n_src);
					printf("Time : %-8fs            |\n",ex_line.time - departure_time);
					printf("%d jump(s)\n",nb_jumps);
					printf("============================\n");
					return -1;
					break;
			
		}	
	}

		return 0;
	
}

flow_stats init_flow_stats(int flow_id){
		flow_stats result;
		result.id = flow_id;
		result.destr_p = 0;
		result.diff_p = 0;
		result.begin_time = -1.0;
		return result;
}

void print_flow_stats(flow_stats f_stats){
	int not_found = ((f_stats.diff_p == 0) && (f_stats.destr_p == 0));
	printf("\n======================\n");
	printf("FLOW N°%d\n",f_stats.id);
	printf("======================\n");
	if(not_found){
	printf("NOT FOUND\n");
	}else{
	float rate = (((float)f_stats.destr_p) / (((float)f_stats.diff_p)+((float)f_stats.destr_p))) * 100.0;
	printf("Arrived   packets : %d\n",f_stats.diff_p);
	printf("Destroyed packets : %d\n",f_stats.destr_p);	
	printf("Loss rate         : %0.2f%%\n",rate);
	printf("Start time  	  : %0.4f\n",f_stats.begin_time);
	printf("End time    	  : %0.4f\n",f_stats.end_time);
	printf("Duration          : %0.4fs\n",f_stats.end_time - f_stats.begin_time);
	}
	printf("======================\n\n");
}
	
void trace_flow(trace_line line, flow_stats* stats){
	if(stats->id == line.f_id){
		if(stats->begin_time < 0){
			stats->begin_time = line.time;
		}
		if(line.p_type == DEST){
			stats->destr_p++;
			stats->end_time = line.time;
		}
		if(line.p_type == ARR_DEST){
			stats->diff_p++;
			stats->end_time = line.time;
		}
		
	}
}

int count_routers(char * file_name){
	char buf[1024];
	 FILE* file = fopen(file_name, "r");
	 int result = 0;
	 
	 
	 while(fgets(buf, sizeof(buf), file) != NULL){
		result++; 
	 }	
	 
	 if(result == 1){
		 return -1;
	 }
	 else{
		 return result;
	 }
	 
}
