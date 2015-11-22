#ifndef TRACE_IDS_FILE
#define TRACE_IDS_FILE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "global.h"
#include "trace_line.h"



typedef struct global_stats global_stats;

struct Node {
	int val;
	struct Node * next;
};

typedef struct Node* NODE;

NODE  new_list(int value);

NODE add_flow_id(NODE list, int value, global_stats* stats);

NODE rm_id(NODE list, int value);
	
void print_list(NODE list);		

void remove_list(NODE list);	

void trace_total_flows_amount(trace_line ex_line, global_stats* stats);

#endif
