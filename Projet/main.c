#include <unistd.h>
#include <getopt.h>
#include "global.h"
#include "trace_line.h"
#include "tracer.h"
#include "trace_ids.h"
#include "links_tracer.h"

int ROUTERS_NB = -1;

void print_help(){
		printf("\n-Options :\n\n\
-F <flow_id>/'all'   : traces the given \
flow id or, if the option 'all' is used, traces the NUMBER of different \
flows\
-f <file name>       : the name of the file to parse\n\
-h                   : get help! \
\n\
-l 'all'             : traces all the end to end communications of the traces. \
\n\
-m <matrix name>     : the name of the file to containing the matrice\
\n\
-h                   : get help!\
\n\
-p <flow_id>/'all'   : traces the given \
packet id or, if the option 'all' is used, traces the NUMBER of different \
packets\
\n\
-r <router_id>/'all' : traces the given \
router or, if the option 'all' is used, traces the NUMBER of total packets \
transiting through each router.\
\n\n\
-Exemple :\n\
\n./read -f trace2650.txt -m res26.txt  -r all\
\n\n");
			 }



int main (int argc, char* argv[]) {
	clock_t begin, end;
	double time_spent;
	int trace_routers = -2;
	int trace_packet = -1;
	char * file_name;
	int flow_value = -2;
	int link_id = -2;
	int c;
	int routers = -1;
	
	opterr = 0;

	while ((c = getopt (argc, argv, "F:f:hsr:p:l:m:")) != -1)
    switch (c)
      {
		  
	  case 'l':
			if(strcmp(optarg,"all") == 0){
				link_id = -1;
			}
			break;
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
	   case 'm':
			printf("matrix : %s\n",optarg);
			ROUTERS_NB = count_routers(optarg);
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
	
	if(ROUTERS_NB == -1){
		printf("ERREUR : Prière d'indiquer la matrice d'adjacence (option -m)\n");
		return 0;
	}
	begin = clock();
	read_file(file_name,flow_value,trace_routers, trace_packet,link_id);
	
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	time_spent = truncate(time_spent);
	printf("Time spent : %0.1f second(s)\n",time_spent);
	
	
	
	
        return 0; 
}
