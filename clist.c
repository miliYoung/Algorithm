#include "clist.h"


void clist_init(CList* list, void (*destroy)(void* data))
{
	list->size = 0;
	list->destroy = destroy;
	list->head = NULL;

	return ;
}
void clist_destroy(Clist* list)
{
	void * data;

	while(clist_size(list) > 0)
	{
		if(clist_rem_next(list,list->head,(void**)&data) == 0 && list->destroy != NULL)
		{
			list->destroy(data);
		}
	}

	return 0;

}
void clist_ins_next(CList* list, CListElmt* element, void* data)
{
	CListElmt* new_element;

	if((new_element = malloc(sizeof(CListElmt)) )== NULL)
	{
		return -1;
	}

	if(clist_size(list) == 0)
	{
		list->head = new_element;
		new_element->next = new_element;
	}
	else
	{
		new_element->next = element->next;
		element->next =new_element;
	}

	list->size++;

	return 0;
}


void clist_rem_next(CList* list, CLIstElmt* element, void** data)
{
	CListElmt* old_element;

	if(list_size(list) == 0)
	{
		return -1;
	}

	*data = element->next->data;
	if(element->next == element)
	{
		old_element = element->next;
		list->head = NULL;
	}
	else
	{
		old_element = element->next;
		element->next = element->next->next;
		if(old_element = list_head(list))
		{
			list->head = old_element->next;
		}
	}

	free(old_element);
	list->size--;

	return 0;
}