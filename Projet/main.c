#include "global.h"

int main (int argc, char* argv[]) {
	char * file_name;
	if(argc != 2){
		printf("Erreur nombre d'arguments\n");		
		return -1;
	}
	file_name = argv[1];
	read_file(file_name);
        return 0; 
}
