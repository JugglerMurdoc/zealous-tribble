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

static const float PRECISION = 10.0;
static const char TOTAL_WAITING_PACKETS_FILE[] = "./traces/total_waiting.tr";
static const char ROUTERS_CHARGE_FILE[] = "./traces/routers_traces.tr";
static const char ONE_ROUTER_CHARGE_FILE[] = "./traces/trace_router";

void trace_total_waiting_packets(trace_line line,FILE* total_waiting_file);

void trace_routers_charge(trace_line line,global_stats* stats,int trace_routers_flag);

float truncate(float long_float);

FILE * get_router_trace(int router_id);


#endif
