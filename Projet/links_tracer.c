#include "links_tracer.h"

void increment_matching_link(int* links_tab,int tab_size, int index1, int index2){
		int x = (index1 > index2)?index2:index1;
		int y = (index1 > index2)?index1:index2;
		
		int abscisse = (y * (y+1))/2;
		int index = abscisse + x;
		
		if(index < tab_size){
			links_tab[index] = 	links_tab[index] + 1;
		}
		else{
			printf("Index out of bounds : %d in %d\n",index, tab_size);
		}
}

void print_tab(int* tab,int nb_routers){
			int i,j;
			int index = 0;
			int line_size = 0;
			
			for(i = 0; i < nb_routers ; i++){
				for(j = 0; j <= line_size; j++){
					printf(" %-2d |",tab[index]);
					index++;
				}			
				printf("\n");
				line_size++;
			}
}
