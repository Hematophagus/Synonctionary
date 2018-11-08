#ifndef TEXT_H
#define TEXT_H

typedef struct _term{
	char *wrd;
	int oc;
}term;


list *getWords(char *text);

void saveOccurrences(list *l, char *text );


#endif //TEXT_H
