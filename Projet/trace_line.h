#ifndef TRACE_LINE_FILE
#define TRACE_LINE_FILE
#include <stdlib.h>
#include <stdio.h>

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

trace_line new_line();

#endif
