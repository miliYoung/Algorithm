#ifndef _DLIST_H
#define _DLIST_H

#include <stdlib>


typedef struct  DListElmt_
{
	void* data;
	struct DListElmt_ *prev;
	struct DLIstElmt_ *next;
}DListElmt;


typedef struct DList_ 
{
	int size;
	int (*match)(const void *key1, const void *key2);
	void (*destroy)(void* data);
	DListElmt *head;
	DLsitElmt *tail;
}DList;

void dlist_init(DList* dlist, void (*destory)(void* data));
void dlist_destroy(DList* list);
int dlist_ins_next(DList* list, DListElmt* element, const void* data);
int dlist_ins_prev(DList* list, DListElmt* element, const void* data);
int dlist_remove(DList* list,DListElmt* element, void** data);
#define dlist_size(list) (list)->size
#define dlist_head(list) (list)->head
#define dlist_tail(list) (list)->tail
#define dlist_is_tail(element) ((element)->next == NULL?1:0)
#define dlist_is_head(element) ((element)->prev == NULL?1:0)
#define dlist_data(element) ((element)->data)
#define dlist_next(element) ((element)->next)
#define dlist_prev(element) ((element)->prev)

#endif