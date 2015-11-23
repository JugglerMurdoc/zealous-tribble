#include <unistd.h>
#include <getopt.h>
#include "global.h"
#include "trace_line.h"
#include "tracer.h"
#include "trace_ids.h"

void print_help(){
		printf("\nOptions :\n\n-F <flow_id>/'all' : traces the given \
flow id or, if the option 'all' is used, traces the NUMBER of different \
flows\n-f : the name of the file to parse\n-h : get help! \
\n-r <router_id>/'all' : traces the given \
router or, if the option 'all' is used, traces the NUMBER of total packets \
transiting through each router.\n\n");
			 }



int main (int argc, char* argv[]) {
	int i;
	int eight_routers[28];
	for(i = 0; i < 28; i++){
		eight_routers[i] = 0;
	}
	
	
	increment_matching_link(eight_routers,28,1,2);
	increment_matching_link(eight_routers,28,2,1);
	increment_matching_link(eight_routers,28,0,0);
	increment_matching_link(eight_routers,28,7,6);
	printf("[0,0]=1\n[1,2]=2\n[6,7]=1\n");
	
	
	for(i =0; i < 28; i++){
		if(eight_routers[i] > 0){
			print_link(eight_routers,i);
		}
	}


	/*clock_t begin, end;
	double time_spent;
	int trace_routers = -2;
	int trace_packet = -1;
	char * file_name = NULL;
	int flow_value = -2;
	int c;
	
	opterr = 0;

	while ((c = getopt (argc, argv, "F:f:hsr:p:")) != -1)
    switch (c)
      {
	  case 'F':
			if(strcmp(optarg,"all") == 0){
				flow_value = -1;
			}else{	
				flow_value = atoi(optarg);
			}
			break;
       case 'f':
			printf("filename : %s\n",optarg);
			file_name = optarg;
			break;
	   case 'p':
			trace_packet = atoi(optarg);
			break;
		case 'r':
			if(strcmp(optarg,"all") == 0){
			trace_routers = -1;
			}else{	
				trace_routers = atoi(optarg);
			}
        break;
      case 'h':
			print_help();
			return 0;
			break;
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
	read_file(file_name,flow_value,trace_routers, trace_packet);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	time_spent = truncate(time_spent);
	printf("Time spent : %0.1f second(s)\n",time_spent);
	*/
	
	
	
        return 0; 
}
