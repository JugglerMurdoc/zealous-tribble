#ifndef GLOBAL_FILE
#define GLOBAL_FILE
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "trace_line.h"
#include "tracer.h"
#include "trace_ids.h"

#define SAMPLE 1000
#define ROUTERS_NB 26

typedef struct Node* NODE;

struct global_stats {
	int destr_p;
	int diff_p;
	int diff_f;
	NODE flow_ids_list;
	int** routers;
};

typedef struct global_stats global_stats;

void read_file(char * file_name,int flow_id,int trace_routers_flag,int packet_id);

global_stats run_through(FILE* file, int flow_id,int trace_routers_flag,int packet_id);
global_stats init_stats();
void print_routeurs_charge(int** routeurs);

void trace_global_stats(trace_line line, global_stats* stats);

#endif
