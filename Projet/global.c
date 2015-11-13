#include "global.h"

void read_file(char * file_name){
  FILE* file = fopen(file_name, "r"); /* should check the result */
  if(file == NULL){
	printf("ERROR : couldn't open file : %s\n", file_name);
	}
  else{
    int i;
    char line[256];

    while (fgets(line, sizeof(line), file) && i < SAMPLE) {
		 trace_line ex_line;
         ex_line = extract_line(line);
         print_line(ex_line);
         printf("----------------\n");
         i++;
    }
    fclose(file);
}
}	
