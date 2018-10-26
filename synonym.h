#ifndef SYNONYM_H
#define SYNONYM_H

typedef struct _dic{
	char *word;
	list *l;
}dic;

dic *newWord(char*word, Remove remSyn, Compare compSyn, Print printSyn);

int registerSynonym(dic *word, char *syn);

void printSynonyms(dic *word);

void destroyDic(dic **word);

#endif //SYNONYM_H
