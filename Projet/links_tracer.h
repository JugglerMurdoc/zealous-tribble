#ifndef LINKS_TRACER_FILE
#define LINKS_TRACER_FILE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "global.h"
#include "trace_line.h"

void increment_matching_link(int* links_tab,int tab_size, int index1, int index2);
void print_link(int* tab, int index);



#endif
