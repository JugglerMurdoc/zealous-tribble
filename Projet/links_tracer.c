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

void write_end_to_end_charge(int* tab,int nb_routers){
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

void trace_end_to_end_charge(trace_line ex_line,global_stats* stats){
	
	
}

NODE2 add_p(links_charge link, int id, float begin){
	NODE2 tmp = link.p_list;
	NODE2 new_cell = new_p_list(id,begin);
	NODE2 list = link.p_list;
	
	/*Cas où la liste ne contient qu'un élément*/
	
	/*On ne rajoute rien si l'élément est déjà là*/
	if(tmp -> next == NULL){
			if(tmp -> id == new_cell -> id){
			return tmp;
	}
	else{
		if(new_cell-> id < list -> id){
				new_cell -> next = list;
				return new_cell;
			}
			else{
				list -> next = new_cell;
				return list;
			}
		}
	}
	
	
	while(tmp -> next != NULL && (tmp -> next->id) <= id){
			tmp = tmp -> next;
			}
	
	if(tmp -> next != NULL){
		new_cell -> next = tmp -> next;
	}
	else{
		tmp -> next = new_cell;
		return list;
	}
	if(tmp -> id == new_cell -> id){
			return list;
	}
	else{
		if(tmp -> id < new_cell -> id){
			tmp->next = new_cell;
			return list;
		}else{
			new_cell->next = tmp;
			return new_cell;
	}
}
}

NODE2 rm_p(links_charge* link, int id, float end){
	NODE2 list = link->p_list;
	NODE2 tmp;
	if(list->id == id){
		tmp = list -> next;
		float time_span = list -> begin - end;
		link->total_time += time_span;
		link->diff_p++;
		free(list);
		return tmp;
	}
	else{
		while(tmp->next != NULL && tmp->next->id != id){
			tmp = tmp -> next;
		}		
		
		if(tmp -> next == NULL){
			if(tmp->id == id){
				float time_span = tmp -> begin - end;
				link->total_time += time_span;
				link->diff_p++;
				free(tmp);
			}
			return list;
		}else{
			NODE2 tmp2 = tmp -> next;
			tmp -> next = tmp -> next -> next;			
			float time_span = tmp2 -> begin - end;
			link->total_time += time_span;
			link->diff_p++;
			free(tmp2);
			return list;
		}		
		
	}
}

NODE2  new_p_list(int id,float begin){
	NODE2 new_NODE2 = (NODE2) malloc (sizeof(struct Node2));
	new_NODE2 -> id = id;
	new_NODE2 -> begin = begin;
	new_NODE2 -> end = -1;
	new_NODE2 -> next = NULL;
	return new_NODE2;
}
