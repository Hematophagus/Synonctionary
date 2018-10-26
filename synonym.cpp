#include <cstring>
#include <iostream>
#include "sll.h"
#include "synonym.h"

using namespace std;

dic *newWord(char *word, Remove remSyn, Compare compSyn, Print printSyn){
	dic *newW = NULL;
	
	newW = new dic;
	
	if(newW != NULL){
		newW -> word = word;
		
		newW -> l = createList(remSyn, compSyn, printSyn);
		
		if(newW -> l == NULL){
			delete newW;
			newW = NULL;
		}	 
	}
	
	return newW;
}

int registerSynonym(dic *word, char *syn){
	if(word != NULL)
		return addInOrder(word -> l, (void *)syn);
}

void printSynonyms(dic *word){
	if(word != NULL){
		cout << "Sinonimos de \"" << word -> word << "\" :\n";
		printList(word -> l);
	}
}

void destroyDic(dic **word){
	dic *temp = *word;
	
	destroyList(temp -> l);
	delete []temp -> word;
	
	delete (*word);
}

