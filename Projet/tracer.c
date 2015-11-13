#include "tracer.h"

float truncate(float long_float){
	float new_time = long_float;
    new_time = new_time*PRECISION;
	new_time = (new_time > (floor(new_time)+0.5f)) ? ceil(new_time) : floor(new_time);
	new_time = new_time/PRECISION;
	
	return new_time;
		
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
	
	
