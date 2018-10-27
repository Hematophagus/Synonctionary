#include <cstring>
#include <fstream>
#include <iostream>
#include "sll.h"
#include "synonym.h"

using namespace std;

list *loadDic(Remove remWord, Remove remSyn, Compare compWord, Compare compSyn, Print printWord, Print printSyn){
	list *l = createList(remWord, compWord, printWord);
	
	fstream file("words"); 					
    
	char *palavra; 							
    
	if(file.is_open()){ 
        
		while(!file.eof()){ 				
            palavra = new char[51];			
            
			file.getline(palavra, 50);
            if(strlen(palavra) != 0){ //se o nome não estiver vazio...
            	dic *word = newWord(palavra, remSyn, compSyn, printSyn);
                
				loadSynonyms(word);
				
				word -> index = sizeOfList(l);
				
				addInOrder(l, (void *)word);
            }
        }
   
   		file.close(); // fechando o arquivo
    }
    
    return l;
}

void loadSynonyms(dic *word){	
	fstream file(word -> word); 
    
	char *palavra; 							
    
	if(file.is_open()){ 
        
		while(!file.eof()){ 
            palavra = new char[51];
            
			file.getline(palavra, 50); 
	        if(strlen(palavra) != 0){ 	
				addInOrder(word -> l, (void *)palavra);
	        }
        }
   
   		file.close(); 
    }
	
}

void registerWord(list *l, Remove remSyn, Compare compSyn, Print printSyn){
	dic *word;
	char *palavra = new char[50];
	
	system("cls");
	
	cout << "Digite a nova palavra:\n";
	cin >> palavra;
	
	word = newWord(palavra, remSyn, compSyn, printSyn);
	addInOrder(l, (void*)word);
	sortIndex(l);
}

void addSynToWord(list *l){
	system("cls");
	cout << "Selecione a palavra a qual o sinonimo sera associada [0 - " << sizeOfList(l)-1 << "]\n" ;
	printList(l);
	int a, op;
	cin >> a;
	
	dic *b = (dic *)getByIndex(l, a);  
	if(b != NULL){
		do{
			cout << "Digite o sinonimo:\n";
			
			char *entrada = new char[51];
			
			cin >> entrada;
			
			if(registerSynonym(b, entrada))
				cout << "Sinonimo Registrado\n";
			else 
				cout << "Sinonimo Nao Registrado\n";
			cout << "Cadastrar Novo Sinonimo para " << b -> word << "? [0/1]\n";
			cin >> op;
		}while(op != 0);
	}else
		cout << "Opção invalida\n";
}

void saveDic(list *Dic){
    ofstream file("words"); 
    
    if(file.is_open()){ 
    	for(int i = 0; i < sizeOfList(Dic); i++){
    		
			dic *temp = (dic *) getByIndex(Dic, i);
			
    		saveSyn(temp);
    		file << temp -> word << "\n";
		
		}
		
		file.close();
        
		return ;
    }
    cout << "Erro ao salvar o dicionario\n";
}

void saveSyn(dic *word){
	ofstream file(word -> word);
	
	if(file.is_open()){
		
		char *temp = new char[51];
		for(int i = 0; i < sizeOfList(word -> l); i++){
    		strcpy(temp, ((char *)getByIndex(word -> l, i)));
    		file << temp << "\n";
		}
		
		file.close();
	}
}

void sortIndex(list *l){
	for(int i = 0; i < sizeOfList(l); i++){
    	dic *temp = (dic *)getByIndex(l, i);
    	temp -> index = i;	
	}
}
