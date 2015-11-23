#include "links_tracer.h"

void increment_matching_link(int* links_tab,int tab_size, int index1, int index2){
		int x = (index1 > index2)?index2:index1;
		int y = (index1 > index2)?index1:index2;
		
		int abscisse = (((x-1) * x)/2);
		int index = abscisse + y;
		
		if(index < tab_size){
			links_tab[index] = 	links_tab[index] + 1;
		}
		else{
			printf("Index out of bounds : %d in %d\n",index, tab_size);
		}
}

void print_link(int* tab, int index){
			int sum = 0;
			int increment = 0;
			
			while(sum < index){
				sum += increment;
				increment ++;
			}
			
			int x = increment - 1;
			int y = index - (sum - increment -1);
			
			printf("%d=[%-2d,%-2d] : %d\n",index,y,x,tab[index]);
}
