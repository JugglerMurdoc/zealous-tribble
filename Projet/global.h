#ifndef GLOBAL_FILE
#define GLOBAL_FILE
#include <stdlib.h>
#include <stdio.h>
#include "trace_line.h"
#include "tracer.h"
#include "trace_ids.h"

#define SAMPLE 1000

typedef struct Node* NODE;

struct global_stats {
	int destr_p;
	int diff_p;
	int diff_f;
	NODE flow_ids_list;
};

typedef struct global_stats global_stats;

void read_file(char * file_name);

global_stats run_through(FILE* file);
global_stats init_stats();


void trace_global_stats(trace_line line, global_stats* stats);

#endif
