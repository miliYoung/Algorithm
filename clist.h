#ifndef _CLIST_H
#define _CLIST_H

#include <stdlib.h>

typedef struct CListElmt_
{
	void* data;
	struct CListElmt_* next;
}CListElmt;

typedef struct CList_
{
	int size;
	int (*match)(void* key1, void* key2);
	void (*destroy)(void* data);
	ClistElmt* head;
}CList;

void clist_init(CList* list, void (*destroy)(void* data));
void clist_destroy(Clist* list);
void clist_ins_next(CList* list, CListElmt* element, void* data);
void clist_rem_next(CList* list, CLIstElmt* element, void** data);

#define clist_size(list) ((list)->size)
#define clist_head(list) ((list)->head)
#define clist_data(element) ((element)->data)
#define clist_next(element) ((element)->next)


#endif