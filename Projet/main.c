#include "global.h"
#include "trace_line.h"
#include "tracer.h"
#include "trace_ids.h"


int main (int argc, char* argv[]) {
	clock_t begin, end;
	double time_spent;

	begin = clock();
	
	char * file_name;
	if(argc != 2){
		printf("Erreur nombre d'arguments\n");		
		return -1;
	}
	file_name = argv[1];
	read_file(file_name);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	time_spent = truncate(time_spent);
	printf("Time spent : %0.1f second(s)\n",time_spent);

	
        return 0; 
}
