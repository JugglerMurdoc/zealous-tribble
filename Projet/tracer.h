#ifndef TRACER_FILE
#define TRACER_FILE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "global.h"
#include "trace_line.h"
typedef struct global_stats global_stats;
typedef struct trace_line trace_line;
typedef struct Node* NODE;
typedef struct links_charge links_charge;

struct flow_stats {
	int id;
	int destr_p;
	int diff_p;
	float begin_time;
	float end_time;
};

typedef struct flow_stats flow_stats;

static const float PRECISION = 10.0;
static const char TOTAL_WAITING_PACKETS_FILE[] = "./traces/total_waiting.tr";
static const char ROUTERS_CHARGE_FILE[] = "./traces/routers_traces.tr";
static const char ONE_ROUTER_CHARGE_FILE[] = "./traces/trace_router";
static const char END_TO_END_DELAY_FILE[] = "./traces/trace_delay.tr";
static const char LINK_CHARGE_FILE[] = "./traces/links_charge.tr";

flow_stats init_flow_stats(int flow_id);
void print_flow_stats(flow_stats f_stats);

void trace_total_waiting_packets(trace_line line,FILE* total_waiting_file);
int trace_packet(trace_line ex_line,int packet_id);
void trace_flow(trace_line line, flow_stats* stats);
void trace_routers_charge(trace_line line,global_stats* stats,int trace_routers_flag, FILE* router_file);

float truncate(float long_float);

FILE * get_router_trace(int router_id);


#endif
