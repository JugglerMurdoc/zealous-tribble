#include "trace_line.h"


trace_line extract_line(char* line){
	char* time;
	char* code;
	char* p_id;
	char* f_id;
	char* src_n;
	char* dest_n;
	char* pos_n;
	time = strtok(line, " ");
	code = strtok(NULL, " ");
	p_id = strtok(NULL, " ");
	f_id = strtok(NULL, " ");
	strtok(NULL, " ");
	if(atoi(code) != 4)
	{strtok(NULL, " ");}
	src_n = strtok(NULL, " ");
	dest_n = strtok(NULL, " ");
	pos_n = strtok(NULL, " ");
	return new_line(time,code,p_id,f_id,src_n,dest_n,pos_n);
}


trace_line new_line(char* time,	char* p_type,char* p_id,char* f_id,char* src_n,char* dest_n,char* pos_n){

	trace_line result;
	
	result.time = atof(time);
	result.p_type = atoi(p_type);
	result.p_id = atoi(p_id);
	result.f_id = atoi(f_id);
	result.n_src = get_node_index(src_n);
	result.n_dest = get_node_index(dest_n);
	result.n_pos = get_node_index(pos_n);
	return result;
}

void print_line(trace_line line){
	printf("Time : %.3f  type : %d p_id : %d flow_id : %d source_node : %-2d  dest_node : %-2d  node_position : %-2d\n",line.time, line.p_type, line.p_id, line.f_id, line.n_src, line.n_dest, line.n_pos);
}


int get_node_index(char* not){
	char subbuff[3];
	memcpy( subbuff, &not[1], 2 );
	subbuff[3] = '\0';
	return atoi(subbuff);	
}
