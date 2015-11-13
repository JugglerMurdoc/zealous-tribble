#include "trace_line.h"




trace_line extract_line(char* line){
	
	char *saveptr;
	char* time;
	char* code;
	char* p_id;
	char* f_id;
	char* tos;
	char* bif;
	char* src_n;
	char* dest_n;
	char* pos_n;

	time = strtok_r(str, " ", &saveptr);
	code = strtok_r(NULL, " ", &saveptr);
	p_id = strtok_r(NULL, " ", &saveptr);
	f_id = strtok_r(NULL, " ", &saveptr);
	tos  = strtok_r(NULL, " ", &saveptr);
	bif  = (strcmp(code,"4"))?strtok_r(NULL, " ", &saveptr):"0";
	src_n = strtok_r(NULL, " ", &saveptr);
	dest_n = strtok_r(NULL, " ", &saveptr);
	pos_n = strtok_r(NULL, " ", &saveptr);
}


trace_line new_line(char* time,	char* code,char* p_id,char* f_id,char* tos,char* bif,char* src_n,char* dest_n,char* pos_n){
trace_line result;
}
