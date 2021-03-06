#include <cstdlib>
#include <cstring>
#include <iostream>
#include "sll.h"
#include "synonym.h"
#include "text.h"
#include "callback.h"

using namespace std;

void remSym(void *a){
	char *a1 = (char *)a; 	
	
	delete []a1;
}

int compSym(void *a, void *b){
	char *a1 = (char *)a; 	
	char *b1 = (char *)b; 
	
	return strcmp(a1, b1);
}

void printSym(void *a){
	char *a1 = (char *)a; 	
	
	cout << "   - " << a1 << "\n";
}

void remWord(void *a){
	dic *a1 = (dic *)a; 	
	
	destroyList(a1 -> l);
	
	delete []a1 -> word;	
	delete a1;
}

int compWord(void *a, void *b){
	dic *a1 = (dic *)a; 	
	dic *b1 = (dic *)b; 
	
	return strcmp(a1 -> word, b1 -> word);
}

void printWord(void *a){
	dic *a1 = (dic *)a; 	
	
	cout << "[" << a1 -> index << "] " << a1 -> word << "\n";
//	printSynonyms(a1);
	
}

void remTerm(void *a){
	term *a1 = (term *)a; 	
	
	delete []a1 -> wrd;
	delete []a1;
}

int compTerm(void *a, void *b){
	term *a1 = (term *)a; 	
	term *b1 = (term *)b; 
	
	return strcmp(a1 -> wrd, b1 -> wrd);
}

void printTerm(void *a){
	term *a1 = (term *)a; 	
	
	cout << a1 -> oc << "   - " << a1 -> wrd << "\n";
}
