#include <cstdlib>
#include <cstring>
#include <iostream>
#include "sll.h"
#include "synonym.h"

using namespace std;

void rem(void *a){
	char *a1 = (char *)a; 	
	
	delete a1;
}

int comp(void *a, void *b){
	char *a1 = (char *)a; 	
	char *b1 = (char *)b; 
	
	return strcmp(a1, b1);
}

void print(void *a){
	char *a1 = (char *)a; 	
	
	cout << a1 << "\n";
}

int main(){
	dic *word;
	char *palavra = new char[10];
	
	cin >> palavra;
	
	word = newWord(palavra, rem, comp, print);
	
	for(int i = 0; i < 3; i++){
		palavra = new char[10];
		
		cin >> palavra;
		
		registerSynonym(word, palavra);
	}
	system("cls");
	
	printSynonyms(word);
	
	destroyDic(&word);
	return 0;
}
