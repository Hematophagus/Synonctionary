#include "sll.h"
#include <iostream>

using namespace std;

list *createList(Remove rem, Compare comp, Print print){
	list *newL  = NULL;
	
	newL = new list;
	
	if(newL != NULL){
		newL -> head = NULL;
		newL -> tail = NULL;
		
		newL -> rem = rem;
		newL -> comp = comp;
		newL -> print = print;
		
		newL -> size = 0;
	}
	
	return newL;
}

node *newNode(void *data){
	node *newN = NULL;
	
	newN = new node;
	
	if(newN != NULL)
		newN -> data = data;
	
	return newN;
}

int addToBegin(list *l, void *data){
	
	if(l != NULL){
		node *newN = newNode(data);
		
		if(newN != NULL){
			
			if(l -> tail == NULL)
				l -> tail = newN;
			
			newN -> next = l -> head;		
			l -> head = newN;
			l -> size++;
			
			return 1;
		}
	}
		
	return 0;
}

int addToEnd(list *l, void *data){
	if(l != NULL){
		node *newN = newNode(data);
		
		if(newN != NULL){
			
			if(l -> tail != NULL){
				node *prev = l -> tail;
			 	prev -> next = newN;
					
			}
			
			newN -> next = NULL;
			l -> tail = newN;
			l -> size++;
			
			return 1;
		}
	}
		
	return 0;
}

int sizeOfList(list *l){
	return l -> size;
}

int addBefore(list *l, node *ref, void *data){
	node *newN = newNode(data);
	
	if(newN != NULL){
		if (l -> head == ref)
			l -> head = newN;
		else{
			node *temp = l -> head;
			while(temp -> next != ref){
				temp = temp -> next;
			}
			temp -> next = newN;
		}
		
		newN -> next = ref;
		
		l -> size++;
		
		return 1;
	}
	
	return 0;
}

int addInOrder(list *l, void *data){
	node *temp = l -> head;
	
	if(temp == NULL)
		return addToBegin(l, data);
	else{
		while(temp != NULL){
			int r = l -> comp(temp -> data, data);
			
			if(r == 0)
				return 0;

			if(r > 0)
				return addBefore(l, temp, data);
			
			temp = temp -> next;
		}
		
		return addToEnd(l, data);
	}
	
	return 0;
}

void *searchNode(list *l, void *key){	
	if(l != NULL && l -> head != NULL){
		node *temp = l -> head;
		
		while(temp != NULL){
			if(l -> comp(temp -> data, key) == 0)
				return temp;
			temp = temp -> next;
		}
	}
		
	return NULL;	
}

void removeNode(list *l, void *key){
	if(l != NULL && l -> head != NULL){
		node *temp = l -> head;
		
		if(l -> comp(temp -> data, key) == 0){	
			
			l -> rem(temp -> data);
			l -> head = temp -> next;
			delete temp;
			
			return ;
		}
			
		
		while(temp -> next != NULL){
			node *prev = temp;
			temp = temp -> next;
			if(l -> comp(temp -> data, key) == 0){	
				l -> rem(temp -> data);
				
				if(l -> tail == temp)
					l -> tail = prev;
				
				prev -> next = temp -> next;
				delete temp;
				
				return ;		
			}
		}
	}
	
}

void printList(list *l){
	node *temp = l -> head;
	
	while(temp != NULL){
		l -> print(temp -> data);
		temp = temp -> next;
	}
}

void destroyList(list *l){
	node *temp = l -> head;
	
	while(temp != NULL){
		node *tmp = temp;
		l -> rem(temp -> data);
		temp = temp -> next;
		delete tmp;
	}
}
