#include <cstdlib>
#include <cstring>
#include <iostream>
#include "sll.h"
#include "synonym.h"
#include "callback.h"
#include "text.h"


using namespace std;

int main(){	
	list *Dic = loadDic(remWord, remSym, compWord, compSym, printWord, printSym);
	int op;
	
	do{
		system("cls");
		
		cout << "===========================\n       SYNONCTIONARY\n===========================\n";
		
		cout << "[1] Cadastrar Nova Palavra\n[2] Cadastrar Novos Sinonimos\n[3] Imprimir Dicionario\n[0] Sair\n===========================\n";
		
		cin >> op;
		
		switch(op){
			case 1:
				registerWord(Dic, remSym, compSym, printSym);
				break;
			case 2:
				addSynToWord(Dic);
				break;
			case 3:
				printDictionary(Dic);
				break;
			case 4:{
				char *buffer = new char [100];
				cin.ignore();
				cin.getline(buffer, 99);
				list *ll = getWords(buffer); 
				saveOccurrences(ll, buffer);
				printList(ll);
				
				delete []buffer;
				destroyList(ll);
				break;
			}case 0:
				break;
			default:
				cout << "Opcao Invalida\n";
		}
		system("pause");
	}while(op != 0);
	
	
	saveDic(Dic);
		
	destroyList(Dic);
	
	return 0;
}
