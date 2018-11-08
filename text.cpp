#include <cstring>
#include <iostream>
#include "callback.h"
#include "sll.h"
#include "text.h"
#include "synonym.h"

using namespace std;

list *getWords(char *text){
	list *l = createList(remTerm, compTerm, printTerm);
	if(l != NULL){
		char *str1 = text, *str2;
		term *buffer;
		int ret;
		
		while(str1 != NULL){
		
			str2 = strstr(str1, " ");
			
			buffer = new term;
			buffer -> wrd = new char[51];
			if(str2 != NULL){
				strncpy(buffer -> wrd, str1, str2 - str1);
				ret = addInOrder(l, buffer);
				str1 = &str2[1];
			}
			else{
				strcpy(buffer -> wrd, str1);
				ret = addInOrder(l, buffer);
				str1 = str2;
			}
			
			if(!ret){
				delete []buffer -> wrd;
				delete []buffer;
			}else
				buffer -> oc = 0;
			
		}
		//delete []buffer;
	}
	
	return l;
}

void saveOccurrences(list *l, char *text ){
	for(int i = 0; i < sizeOfList(l); i++){
		term *temp = (term *)getByIndex(l, i);
		char *str = text;
		while(str != NULL){
			str = strstr(str, temp -> wrd);
			if(str != NULL){
				temp -> oc++;
				str = &str[1];
			}
		}
	}
}
