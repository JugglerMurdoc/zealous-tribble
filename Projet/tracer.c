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

void trace_total_waiting_packets(trace_line line, FILE* total_waiting_file){
	static float precedent_time = 0;
	static int current_queue_size = 0;
		if(total_waiting_file == NULL){
			printf("ERROR : Couldn't open trace file\n");	
		}
		else{
			 float new_time = truncate(line.time);
			 if(new_time == precedent_time){
				 current_queue_size++;
			 }else{
			 char buffer [50];
			 sprintf(buffer,"%f %d\n", new_time, current_queue_size);
			 fputs(buffer,total_waiting_file);
			 current_queue_size = 0;
			 precedent_time = new_time;
		 }
	}
}

void trace_routers_charge(trace_line line,global_stats* stats,int trace_routers_flag,FILE* router_file){
	 if(trace_routers_flag != -2){		
		if(trace_routers_flag == -1){	
			
			if(line.p_type == ARR_INT){
					int result = stats->routers[line.n_src-1] + 1;
					stats->routers[line.n_src-1] = result;		}
			}else{
		/*Trace de la charge de TOUS les routeurs*/
			if((line.p_type == ARR_INT || line.p_type == ARR_DEST) && line.n_src == trace_routers_flag) {
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
	}
}
}



	
