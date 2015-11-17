#ifndef TRACE_IDS_FILE
#define TRACE_IDS_FILE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "global.h"
#include "trace_line.h"

struct Node {
	int val;
	struct Node * next;
};

typedef struct Node* NODE;

NODE  new_list(int value);

NODE add_id(NODE list, int value);
	
void print_list(NODE list);			

/*
//~ FILE * create_and_open_trace_file(char* file_name);
//~ void remove_trace(char * file_name);
//~ 
//~ void insert_id(int id, FILE* trace_file);
//~ 
//~ void trace_flow_and_packets_ids(struct trace_line line,struct  global_stats* stats,Node flows_list, Node packets_list );*/

#endif
