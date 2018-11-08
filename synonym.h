#ifndef SYNONYM_H
#define SYNONYM_H

typedef struct _dic{
	char *word;
	int index;
	list *l;
}dic;

//sinonimos
dic *newWord(char*word, Remove remSyn, Compare compSyn, Print printSyn);

void loadSynonyms(dic *word); 											//check

int registerSynonym(dic *word, char *syn);								//check

void printSynonyms(dic *word);											//check

void printDictionary(list *l);

void insertIndex(list *l, dic *word);									//check

void destroyWord(dic **word);											//check

void sortIndex(list *l);

//palavras em separado
list *loadDic(Remove remWord, Remove remSyn, Compare compWord, Compare compSyn, Print printWord, Print printSyn);	//check

void registerWord(list *l, Remove remSyn, Compare compSyn, Print printSyn);		//check

void saveDic(list *Dic);												//check

void saveSyn(dic *Word);												//check

void addSynToWord(list *l);												//check


#endif //SYNONYM_H
