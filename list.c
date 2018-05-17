#include "list.h"

void list_init(List* list,void (*destroy)(void* data))
{
	list->head = NULL;
	list->size = 0;
	list->tail = NULL;
	list->destroy = destroy;

}

void list_destroy(List* list)
{
	void *data;
	while(list_size(list) > 0)
	{
		if()
		{
			
		}
	}

}

void list_ins_next(List *list, ListElmt* element,const void* data)
{

}

void list_rem_next(List *list, ListElmt* element, void ** data)
{

}