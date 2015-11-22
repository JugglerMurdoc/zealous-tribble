#include "global.h"

	

void print_routeurs_charge(int* routeurs)
{		
			FILE* routeurs_file = fopen(ROUTERS_CHARGE_FILE, "w");
			int i;
			for( i = 0; i < ROUTERS_NB; i++){
				char buffer [50];
				sprintf(buffer,"%d %d\n", i, routeurs[i]);
				fputs(buffer,routeurs_file);
			}
			fclose(routeurs_file);
			printf("\n");	
}

global_stats init_stats(){
	global_stats stats;
	int i;
	stats.destr_p = 0;
	stats.diff_p = 0;
	stats.diff_f = 0;
	stats.flow_ids_list = new_list(-1);
	stats.routers = (int*)malloc(ROUTERS_NB*sizeof(int));
	for(i = 0; i < ROUTERS_NB; i++){
		stats.routers[i] = 0;
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
	
global_stats run_through(FILE* file,int flow_id,int trace_routers_flag){
	int i;
    char line[256];
	global_stats stats = init_stats();
    FILE* total_waiting_file = fopen(TOTAL_WAITING_PACKETS_FILE, "w");
    FILE* router_file = (trace_routers_flag <= -1)?NULL:get_router_trace(trace_routers_flag);	
	while (fgets(line, sizeof(line), file)  /*&& i < SAMPLE*/) {
		 trace_line ex_line;
         ex_line = extract_line(line);
         
         trace_total_waiting_packets(ex_line,total_waiting_file);	         
         trace_global_stats(ex_line, &stats);
	 if(flow_id == -1){
		trace_total_flows_amount(ex_line, &stats);
	 }
	 if(trace_routers_flag != -2){
		 trace_routers_charge(ex_line,&stats,trace_routers_flag, router_file);
	 }
         
         i++;
    }
    fclose(file);
    if(router_file != NULL) {fclose(router_file);}
    
    return stats;
}


void read_file(char * file_name,int flow_id,int trace_routers_flag){
  FILE* file = fopen(file_name, "r");
  global_stats stats;
  if(file == NULL){
	printf("ERROR : couldn't open file : %s\n", file_name);
	}
  else{
		stats = run_through(file,flow_id,trace_routers_flag);
		printf("DESTRUCTIONS       : %-7d\n",stats.destr_p);
		printf("PAQUETS DIFFERENTS : %-7d\n",stats.diff_p);
		if(flow_id == -1){printf("FLUX DIFFERENTS : %-7d\n",stats.diff_f);}
		
		if(trace_routers_flag == -1){
			print_routeurs_charge(stats.routers);
			system("gnuplot < plot/routers_charge.gp && mv routers.png ./png && display ./png/routers.png ");
		}
		else{
			if(trace_routers_flag != -2){
				char buf[256];
				sprintf(buf,"gnuplot < plot/one_router.gp && mv router%d.png png/ && display png/router%d.png",trace_routers_flag,trace_routers_flag);
				system(buf);
			}
		}
		
		remove_list(stats.flow_ids_list);
    }
}
	
