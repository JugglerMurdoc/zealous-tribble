#include "trace_ids.h"

NODE  new_list(int value){
	NODE new_node = (NODE) malloc (sizeof(struct Node));
	new_node -> val = value;
	new_node -> next = NULL;
	return new_node;
}

NODE add_id(NODE list, int value){
	NODE tmp = list;
	NODE new_cell = new_list(value);
	
	if(list -> next == NULL){
			if(new_cell-> val < list -> val){
				new_cell -> next = list;
				return new_cell;
			}
			else{
				list -> next = new_cell;
				return list;
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
		return list;
	}
	
	if(tmp -> val < new_cell -> val){
		tmp->next = new_cell;
		return list;
	}else{
		new_cell->next = tmp;
		return new_cell;
	}
}
void print_list(NODE list)
{
	NODE tmp = list;
	while(tmp -> next != NULL){
			printf("| %-8d", tmp->val);
			tmp = tmp -> next;
	}
	printf("| %-8d\n", tmp->val);
}

/*
//FILE * create_and_open_trace_file(char* file_name){
		//char buffer [50];
		//sprintf(buffer,"touch %s\n", file_name);
		//int return_value = system(buffer);
		//return fopen(buffer,"r+");
//}

//void remove_trace(char * file_name){
		//char buffer [50];
		//sprintf(buffer,"rm %s\n", file_name);
		//system(buffer);
//}

//void trace_flow_and_packets_ids(struct trace_line line,struct  global_stats* stats,struct  Node * flows_list,struct Node * packets_list ){
	//int new_f_id = line.f_id;
	//int new_p_id = line.p_id;
	
	//insert_and_increment_if_new(new_f_id,&(stats->diff_f),flows_list);
	//insert_and_increment_if_new(new_p_id,&(stats->diff_p),packets_list);	
//}

//void insert_and_increment_if_new(int element, int * stats, struct Node* list){
	//if(find_int(element, list) == 0){
		//(*stats)++;
	//}
	//else{
		//InsertAtTail(element,list);
	//}	
//}

//void insert_id(int id, FILE* trace_file){
	//char line[256];
	//int spot_founded = 0;
	
	//while (fgets(line, sizeof(line), trace_file)
			//&& (spot_founded == 0)) {
		 
		 //int extracted_id = atoi(line);
		 //if(id < extracted_id){
			 
			 
			//}	
		 
		//}
	
//} */
