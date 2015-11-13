#ifndef TRACE_LINE_FILE
#define TRACE_LINE_FILE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "global.h"

typedef enum {DEP_SOURCE, ARR_INT, DEP_FILE, ARR_DEST, DEST} packet_type;

struct trace_line {
	float time;
	packet_type p_type;
	int p_id;
	int f_id;
	int n_src;
	int n_dest;
	int n_pos;
};

typedef struct trace_line trace_line;

trace_line extract_line(char* line);

trace_line new_line(char* time,	char* code,char* p_id,char* f_id,char* src_n,char* dest_n,char* pos_n);

void print_line(trace_line line);

int get_node_index(char* not);

#endif
