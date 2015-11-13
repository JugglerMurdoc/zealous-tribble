#ifndef GLOBAL_FILE
#define GLOBAL_FILE
#include <stdlib.h>
#include <stdio.h>
#include "trace_line.h"

#define SAMPLE 10

struct global_stats {
	int destr_p;
	int diff_p;
	int diff_f;
};

typedef struct global_stats global_stats;

void read_file(char * file_name);

#endif
