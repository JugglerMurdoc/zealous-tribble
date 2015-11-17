#include "global.h"

global_stats init_stats(){
	global_stats stats;
	stats.destr_p = 0;
	stats.diff_p = 0;
	stats.diff_f = 0;
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
	
global_stats run_through(FILE* file){
	int i;
    char line[256];
	global_stats stats;
    FILE* total_waiting_file = fopen(TOTAL_WAITING_PACKETS_FILE, "w");
	while (fgets(line, sizeof(line), file) /* i < SAMPLE*/) {
		 trace_line ex_line;
         ex_line = extract_line(line);
         
         trace_total_waiting_packets(ex_line,total_waiting_file);	         
         trace_global_stats(ex_line, &stats);
         
         i++;
    }
    fclose(file);
    
    return stats;
}


void read_file(char * file_name){
  FILE* file = fopen(file_name, "r");
  global_stats stats;
  if(file == NULL){
	printf("ERROR : couldn't open file : %s\n", file_name);
	}
  else{
		stats = run_through(file);
		printf("DESTRUCTIONS       : %-7d\n",stats.destr_p);
		printf("PAQUETS DIFFERENTS : %-7d\n",stats.diff_p);
    }
}	
	
