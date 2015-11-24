#ifndef LINKS_TRACER_FILE
#define LINKS_TRACER_FILE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "global.h"
#include "trace_line.h"
#include "tracer.h"
#include "trace_ids.h"

typedef struct global_stats global_stats;
typedef struct trace_line trace_line;

typedef struct global_stats global_stats;

struct Node2 {
	int id;
	float begin;
	float end;
	struct Node2 * next;
};

typedef struct Node2* NODE2;

	struct links_charge {
	int diff_p;
	float total_time;
	NODE2 p_list; 	
};

typedef struct links_charge links_charge;

NODE2  new_p_list(int value,float begin);

NODE2 add_p(links_charge link, int id, float begin);

NODE2 rm_p(links_charge* link, int id, float end);

void print_used_links_stats(global_stats stats);

void print_link_charge(NODE2 list);

int get_hash(int index1, int index2);
void write_end_to_end_charge(global_stats stats);
void trace_end_to_end_charge(trace_line ex_line,global_stats* stats);


#endif
