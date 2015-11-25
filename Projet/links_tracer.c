#include "links_tracer.h"

int get_hash(int index1, int index2){
		int x = (index1 > index2)?index2:index1;
		int y = (index1 > index2)?index1:index2;
		int abscisse = (y * y+1)/2;
		int index = abscisse + x;
		
		return index;
}

void write_end_to_end_charge(global_stats stats){
			int i,j;
			int graph_index = 0;
			int index = 0;
			int line_size = 0;
			FILE* end_to_end_delay_file = fopen(END_TO_END_DELAY_FILE,"w");
			char line[50];
			int total_packets = 0;
			for(i = 0; i < ROUTERS_NB ; i++){
				for(j = 0; j < line_size; j++){
					links_charge link = stats.end_to_end_charge[index];
					if(link.diff_p > 0){
					graph_index++;
					total_packets += (link.diff_p+link.diff_d);
					double mean_delay = (link.total_time / ((double)link.diff_p))*1000.0;
					printf("%d[%-2d --> %-2d] %-9d packets (%-4d detruits) Total time : %-15lf Mean delay : %lfms\n",index,i,j,link.diff_p,link.diff_d,link.total_time,mean_delay);
					sprintf(line,"%d %lf\n",graph_index,mean_delay);
					fputs(line,end_to_end_delay_file);
					}
					index++;
				}			
				line_size++;
			}
			fclose(end_to_end_delay_file);
		
			
}

void trace_end_to_end_charge(trace_line ex_line,global_stats* stats){
	int src = ex_line.n_src;
	int  dest = ex_line.n_dest;
	if((ex_line.p_type == DEP_SOURCE ||  ex_line.p_type == DEST || ex_line.p_type == ARR_DEST)){
		int index = get_hash(src-1,dest-1);
		links_charge* link = &(stats->end_to_end_charge[index]);
		if(ex_line.p_type == DEP_SOURCE){
		link->p_list = add_p(*link,ex_line.p_id,ex_line.time);}
		else{
			if(ex_line.p_type == DEST || ex_line.p_type == ARR_DEST){
				int is_not_dest = (ex_line.p_type == ARR_DEST);
				link->p_list = rm_p(link,ex_line.p_id,ex_line.time,is_not_dest);
			}
		}
	}
	
}

NODE2 add_p(links_charge link, int id, double begin){
	NODE2 tmp = link.p_list;
	NODE2 new_cell = new_p_list(id,begin);
	NODE2 list = link.p_list;
	if(tmp == NULL){
		return new_cell;		
	}
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

NODE2 rm_p(links_charge* link, int id, float end,int is_not_dest){
	NODE2 list = link->p_list;
	NODE2 tmp = list;
	/*Premier élément de la liste à supprimer*/
	if(list->id == id){
		tmp = list -> next;
		if(is_not_dest){
		float time_span = end- list -> begin;
		link->total_time += time_span;
		link->diff_p++;
		}else{
		link->diff_d++;		
		}
		free(list);
		return tmp;
	}
	
	else{
		while(tmp->next != NULL && tmp->next->id != id){
			tmp = tmp -> next;
		}		
		/*Dernier élément de la liste PEUT-ETRE a supprimer*/
		if(tmp -> next == NULL){
			if(tmp->id == id){
				float time_span = end - tmp -> begin;
				if(is_not_dest){
				link->total_time += time_span;
				link->diff_p++;
				}else{
				link->diff_d++;		
				}
				free(tmp);
			}
			return list;
		/*Element de milieu de liste concerné*/
		}else{
			NODE2 tmp2 = tmp -> next;
			tmp -> next = tmp -> next -> next;			
			float time_span = end - tmp2 -> begin;
			if(is_not_dest){
			link->total_time += time_span;
			link->diff_p++;
			}else{
			link->diff_d++;		
			}
			free(tmp2);
			return list;
		}		
		
	}
}

void print_link_charge(NODE2 list)
{
	if(list != NULL){
	NODE2 tmp = list;
	while(tmp -> next != NULL){
			printf("| %d ", tmp->id);
			tmp = tmp -> next;
	}
	printf("| %d \n", tmp->id);
}
	else{
		printf("\n");
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
