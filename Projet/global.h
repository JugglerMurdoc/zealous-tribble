#ifndef GLOBAL_FILE
#define GLOBAL_FILE
#include <stdlib.h>
#include <stdio.h>
#include "trace_line.h"

typedef enum {DEP_SOURCE, ARR_INT, DEP_FILE, ARR_DEST, DEST} packet_type;

struct global_stats {
	int destr_p;
	int diff_p;
	int diff_f;
};

struct trace_line {
	float time;
	packet_type p_type;
	int p_id;
	int f_id;
	int n_src;
	int n_dest;
	int n_pos;
};

typedef struct global_stats global_stats;
typedef struct trace_line trace_line;

void read_file(char * file_name);
trace_line extract_line(char* line);

#endif
