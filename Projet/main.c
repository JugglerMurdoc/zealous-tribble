#include <unistd.h>
#include <getopt.h>
#include "global.h"
#include "trace_line.h"
#include "tracer.h"
#include "trace_ids.h"

void print_help(){
		printf("\nOptions :\n\n-F <flow_id>/'all' : traces the given flow id or, if the option 'all' is used, traces the NUMBER of different flows\n\-f : the name of the file to parse\n-h : get help!\n\n");
			 }



int main (int argc, char* argv[]) {

	clock_t begin, end;
	double time_spent;

	int all_flows_flag = 0;
	char * file_name = NULL;
	char *flow_value = NULL;
	int index;
	int c;
	
	opterr = 0;

	while ((c = getopt (argc, argv, "Ff:hs")) != -1)
    switch (c)
      {
	  /*F : number of flows*/	  
      case 'F':
        all_flows_flag = 1;
        flow_value = optarg;
        break;
       case 'f':
        printf("filename : %s\n",optarg);
        file_name = optarg;
        break;
      /*h : print help*/
      case 'h':
        print_help();
        return 0;
        break;
      /*CASE OF ARGUMENT VALUES  
      case 'c':
        cvalue = optarg;
        break;*/
      case '?':
        if (optopt == 'c')
          fprintf (stderr, "Option -%c requires an argument.\n", 
          optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        printf("For help : type ./read -h\n");
        return 1;
      default:
        abort ();
      }

	
	begin = clock();
	read_file(file_name);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	time_spent = truncate(time_spent);
	printf("Time spent : %0.1f second(s)\n",time_spent);

	
        return 0; 
}
