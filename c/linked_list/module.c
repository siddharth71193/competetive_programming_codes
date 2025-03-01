/*
Project name : linked_list
Module name  : {module}
Created on : Wed Aug  6 17:59:06 2014
Author : Anant Pushkar
Linked list library basd on stanford text
*/
#include "module.h"
node *new_node(int val){
	node *ptr = (node *)malloc(sizeof(node));
	ptr->val = val;
	ptr->next= NULL;
	
	return ptr;
}
list *new_list(){
	list *ptr = (list*)malloc(sizeof(list));
	ptr->head = NULL;
	ptr->tail = NULL;
	ptr->size = 0;
	
	return ptr;
}
node* push(node** parent , int val){
	node *ptr = new_node(val);
	if(*parent==NULL){
		*parent = ptr;
		return ptr;
	}
	ptr->next = (*parent)->next;
	(*parent)->next = ptr;
	return ptr;
}
void init_list(list *l , int val){
	node* ptr = new_node(val);
	l->head = ptr;
	l->tail = ptr;
	l->size = 1;
	return;
}
void push_to_head(list* l , int val){
	if(l->size==0){
		init_list(l , val);
		return;
	}
	push(&(l->head) , val);
	++l->size;
}
void push_to_tail(list* l , int val){
	if(l->size==0){
		init_list(l , val);
		return;
	}
	node* ptr = new_node(val);
	l->tail->next = ptr;
	l->tail   = ptr;
	++l->size;
}
list* create_list(int n){
	list* l = new_list();
	
	init_list(l , 1);
	for(int i=2;i<n;++i){
		push_to_tail(l,i);
	}
	
	return l;
}
void print_list(list *l){
	node* ptr = l->head;
	while(ptr!=NULL){
		printf("%d->",ptr->val);
		ptr = ptr->next;
	}
	printf("#\n");
}
int get_length(list *l){
	int count=0;
	node*ptr = l->head;
	while(ptr!=NULL){
		++count;
		ptr = ptr->next;
	}
	return count;
}
node* find_node(list *l , int val){
	node* ptr = l->head;
	while(ptr!=NULL){
		if(ptr->val == val){
			return ptr;
		}
		ptr = ptr->next;
	}
	return ptr;
}
int get_count(list *l , int val){
	int count=0;
	node *ptr=l->head;
	while(ptr!=NULL){
		if(ptr->val == val){
			++count;
		}
		ptr = ptr->next;
	}
	return count;
}
node* get_nth(list*l , int n){
	node* ptr = l->head;
	while(ptr!=NULL && n--){
		ptr = ptr->next;
	}
	return ptr;
}
void delete_node(node* ptr){
	if(ptr==NULL){
		return;
	}
	delete_node(ptr->next);
	//printf("Freeing %d\n",ptr->val);
	free(ptr);
}
void delete_list(list* l){
	delete_node(l->head);
	//printf("freeing list\n");
	free(l);
}
int pop_from_head(list *l ){
	int val = l->head->val;
	
	node* ptr = l->head;
	l->head = ptr->next;
	--l->size;
	free(ptr);
	
	return val;
}
int pop_from_tail(list *l){
	int val = l->tail->val;
	
	node* ptr = l->tail , *it = l->head;
	while(it->next!=ptr){
		it = it->next;
	}
	l->tail = it;
	it->next= NULL;
	--l->size;
	free(ptr);
	
	return val;
}
void insert_nth(list* l, int n , int val){
	if(n==0){
		node* ptr = new_node(val);
		ptr->next = l->head;
		l->head   = ptr;
		++l->size;
		return;
	}
	node *nth = get_nth(l , n-1) , *ptr=new_node(val);
	ptr->next = nth->next;
	nth->next = ptr;
	++l->size;
}
void reverse_node(node* ptr){
	if(ptr->next==NULL){
		return;
	}
	reverse_node(ptr->next);
	ptr->next->next = ptr;
}
void reverse(list*l){
	reverse_node(l->head);
	l->head->next = NULL;
	node* ptr = l->head;
	l->head = l->tail;
	l->tail = ptr;
}

void quicksort(list *l){
	if(l->size<2){
		return ;
	}
	node* pivot = l->head , *ptr = l->head->next , *temp;
	list *smaller = new_list() , *greater = new_list();
	while(ptr!=NULL){
		if(ptr->val<pivot->val){
			push_to_tail(smaller , ptr->val);
		}else{
			push_to_tail(greater , ptr->val);
		}
		temp = ptr;
		ptr  = ptr->next;
		free(temp);
	}
	quicksort(smaller);
	quicksort(greater);
	
	push_to_tail(smaller , pivot->val);
	free(pivot);
	ptr = greater->head;
	while(ptr!=NULL){
		push_to_tail(smaller , ptr->val);
		ptr = ptr->next;
	}
	delete_list(greater);
	l->head = smaller->head;
	l->tail = smaller->tail;
	free(smaller);
}
void remove_duplicates(list* l){
	node* ptr = l->head , *temp;
	while(ptr!=NULL && ptr->next!=NULL){
		while(ptr!=NULL && ptr->next!=NULL && ptr->val == ptr->next->val){
			temp = ptr->next;
			ptr->next = ptr->next->next;
			free(temp);
		}
		ptr = ptr->next;
	}
}

