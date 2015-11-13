#include "global.h"

void read_file(char * file_name){
  FILE* file = fopen(file_name, "r"); /* should check the result */
  if(file == NULL){
	printf("ERROR : couldn't open file : %s\n", file_name);
	}
  else{
    
    char line[256];

    while (fgets(line, sizeof(line), file)) {
         printf("%s", line); 
    }
    fclose(file);
}
}	
