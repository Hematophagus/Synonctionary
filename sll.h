#ifndef SLL_H
#define SLL_H

typedef void (*Remove) (void *a);

typedef int (*Compare)(void *a, void *b);

typedef void (*Print)(void *a);

typedef struct _node{
	void *data;
	struct _node *next;	
}node;

typedef struct _list{
	node *head;
	
	Remove rem;
	Compare comp;
	Print print;
	
	int size;
	
	node *tail;	
}list;

list *createList(Remove rem, Compare comp, Print print);

node *newNode(void *data);

int addToBegin(list *l, void *data);

int addToEnd(list *l, void *data);

int addBefore(list *l, node *ref, void *data);

int addInOrder(list *l, void *data);

void *searchNode(list *l, void *key);

void removeNode(list *l, void *key);

int sizeOfList(list *l);

void printList(list *l);

void destroyList(list *l);

#endif //SLL_H
