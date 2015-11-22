#include "trace_ids.h"

NODE  new_list(int value){
	NODE new_node = (NODE) malloc (sizeof(struct Node));
	new_node -> val = value;
	new_node -> next = NULL;
	return new_node;
}

NODE add_flow_id(NODE list, int value, global_stats* stats){
	NODE tmp = list;
	NODE new_cell = new_list(value);
	
	/*Cas où la liste ne contient qu'un élément*/
	
	/*On ne rejoute rien si l'élément est déjà là*/
	if(list -> next == NULL){
			if(tmp -> val == new_cell -> val){
			return list;
	}
	else{
		if(new_cell-> val < list -> val){
				new_cell -> next = list;
				return new_cell;
			}
			else{
				list -> next = new_cell;
				return list;
			}
		}
	}
	
	
	while(tmp -> next != NULL && (tmp -> next->val) <= value){
			tmp = tmp -> next;
			}
	
	if(tmp -> next != NULL){
		new_cell -> next = tmp -> next;
	}
	else{
		tmp -> next = new_cell;
		if(stats != NULL){
			stats->diff_f++;
		}
		return list;
	}
	if(tmp -> val == new_cell -> val){
			return list;
	}
	else{
		if(tmp -> val < new_cell -> val){
			
		if(stats != NULL){
			stats->diff_f++;
		}
			tmp->next = new_cell;
			return list;
		}else{
			new_cell->next = tmp;
			
		if(stats != NULL){
			stats->diff_f++;
		}
			return new_cell;
	}
}
}

void print_list(NODE list)
{
	if(list != NULL){
	NODE tmp = list;
	while(tmp -> next != NULL){
			printf("| %-8d", tmp->val);
			tmp = tmp -> next;
	}
	printf("| %-8d\n", tmp->val);
}
}


void remove_list(NODE list){
	if(list != NULL && list -> next != NULL){
		remove_list(list->next);
	}	
	free(list);
}

void trace_total_flows_amount(trace_line ex_line, global_stats* stats){
	int flow_id = ex_line.f_id;
	if(stats->diff_f == 0){
			stats->flow_ids_list->val = flow_id;
			stats->diff_f++;
	}else{
	stats -> flow_ids_list = add_flow_id(stats->flow_ids_list,flow_id,stats);
	}
	
}

NODE rm_id(NODE list, int value){
	NODE tmp = list;
	if(tmp->val == value){
		tmp = tmp -> next;
		free(list);
		return tmp;
	}
	else{
		while(tmp->next != NULL && tmp->next->val != value){
			tmp = tmp -> next;
		}		
		
		if(tmp -> next == NULL){
			if(tmp->val == value){
				free(tmp);
			}
			return list;
		}else{
			NODE tmp2 = tmp -> next;
			tmp -> next = tmp -> next -> next;
			free(tmp2);
			return list;
		}		
		
	}
}
