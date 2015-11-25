#include "global.h"

	

void print_routeurs_charge(int** routeurs)
{		
			FILE* routeurs_file = fopen(ROUTERS_CHARGE_FILE, "w");
			int i;
			for( i = 0; i < ROUTERS_NB; i++){
				char buffer [50];
				sprintf(buffer,"%d %d %d\n", i, routeurs[i][0],routeurs[i][1]);
				fputs(buffer,routeurs_file);
			}
			fclose(routeurs_file);
			printf("\n");	
}

global_stats init_stats(int links_flag){
	global_stats stats;
	int i,j;
	stats.destr_p = 0;
	stats.diff_p = 0;
	stats.diff_f = 0;
	stats.flow_ids_list = new_list(-1);
	stats.routers = (int**)malloc(ROUTERS_NB*sizeof(int*));
	for(i = 0; i < ROUTERS_NB; i++){
		stats.routers[i] = (int*) malloc (2 * sizeof(int));
		for(j = 0; j < 2; j++){	
		stats.routers[i][j] = 0;
		}
	}
	if(links_flag){
	int nb_links = ((ROUTERS_NB* (ROUTERS_NB -1))/2);
	stats.nb_links = nb_links;
	stats.end_to_end_charge = (links_charge*)malloc( nb_links * sizeof(links_charge));
	for(i = 0; i < nb_links; i++){
		stats.end_to_end_charge[i].diff_p = 0;
		stats.end_to_end_charge[i].diff_d = 0;
		stats.end_to_end_charge[i].total_time = 0.0;
		stats.end_to_end_charge[i].p_list = NULL;
	}
	}
	
	return stats;
}
	
void trace_global_stats(trace_line line, global_stats* stats){
	if(line.p_type == DEST){
		stats->destr_p++;
	}
	if(line.p_type == DEP_SOURCE){
		stats-> diff_p ++;
	}
}
	
global_stats run_through(FILE* file,int flow_id,int trace_routers_flag, int packet_id,int link_id){
	int i;
	float percent =  (STEP_SIZE_PERCENT/100.0);
	float step_size = percent * NB_LINES;
    char line[256];
    global_stats stats = init_stats(link_id);
	flow_stats f_stats;
	if(flow_id > -1){
		f_stats = init_flow_stats(flow_id);
	}
    FILE* total_waiting_file = fopen(TOTAL_WAITING_PACKETS_FILE, "w");
    FILE* router_file = (trace_routers_flag <= -1)?NULL:get_router_trace(trace_routers_flag);	
	while (fgets(line, sizeof(line), file) /* && i < SAMPLE*/) {
		 trace_line ex_line;
         ex_line = extract_line(line);
         
         trace_total_waiting_packets(ex_line,total_waiting_file);	         
         trace_global_stats(ex_line, &stats);
	 if(flow_id == -1){
		trace_total_flows_amount(ex_line, &stats);
	 }
		else{
			if(flow_id > -1){
				trace_flow(ex_line,&f_stats);
			}
		}
	 if(packet_id != -1){
		 int result = trace_packet(ex_line,packet_id);
		 if(result == -1){
			 break;
		 }
		}
	 if(trace_routers_flag != -2){
		 trace_routers_charge(ex_line,&stats,trace_routers_flag, router_file);
	 }
	 if(link_id == -1){
		 trace_end_to_end_charge(ex_line,&stats);
		 
	 }
         
         i++;
         if(i % ((int)step_size) == 0){
			 			 float progress = ((float)i)/((float)NB_LINES)*100.0;
			 			 printf("\n%0.0f%% ...",progress);
		 }
    
    }
    printf("\n");
    fclose(file);
    if(router_file != NULL) {fclose(router_file);}
    if(flow_id > -1){
		print_flow_stats(f_stats);		
	}
    return stats;
}


void read_file(char * file_name,int flow_id,int trace_routers_flag,int packet_id,int link_id){
  FILE* file = fopen(file_name, "r");
  global_stats stats;
  if(file == NULL){
	printf("ERROR : couldn't open file : %s\n", file_name);
	}
  else{
		stats = run_through(file,flow_id,trace_routers_flag,packet_id,link_id);
		printf("Destructions lues       : %-7d\n",stats.destr_p);
		printf("Paquets differents lus : %-7d\n",stats.diff_p);
		if(flow_id == -1){printf("FLUX DIFFERENTS : %-7d\n",stats.diff_f);
							}
		
		if(trace_routers_flag == -1){
			print_routeurs_charge(stats.routers);
			system("gnuplot < plot/routers_charge.gp && mv routers.png ./png && display ./png/routers.png ");
		}
		else{
		}
		if(link_id == -1){
			write_end_to_end_charge(stats);
		}
		
		remove_list(stats.flow_ids_list);
		printf("\n");
    }
}
	
