#include "dlist.h"

void dlist_init(DList* dlist, void (*destory)(void* data))
{
	list->size = 0;
	list->tail = NULL;
	list->head = NULL;
	list->destory = destroy;

}


void dlist_destroy(DList* list)
{
	void *data;
	while(dlist_size(list) > 0)
	{
		if(dlist_remove(list,element,(void**)&data) == 0 && list->destroy != NULL)
		{
			list->destroy(*data);
		}
	}

	memset(list,0,sizeof(list));

	return 0;
}

int dlist_ins_next(DList* list, DListElmt* element, const void* data)
{
	DListElmt *new_element;

	if(dlist_size(list) != 0 && element != NULL)
		return -1;

	if((new_element = malloc(sizeof(DListElmt))) == NULL)
	{
		return -1;
	}

	if(dlist_size(list) = 0)
	{
		list->head = new_element;
		list->head->prev = NULL;
		list->head->next = NULL;
		list->tail = new_element;
	}
	else
	{
		new_element->next = element->next;
		new_element->prev = element;

		if(element->next == NULL)
		{
			list->tail = new_element;
		}
		else
		{
			element->next->prev = new_element;
		}

		element->next = new_element;

	}
	list->size++;

	return 0;
}

int dlist_ins_prev(DList* list, DListElmt* element, const void* data)
{
	DListElmt *new_element;

	if(dlist_size(list) != 0 && element != NULL)
		return -1;

	if((new_element = malloc(sizeof(DListElmt))) == NULL)
	{
		return -1;
	}

	if(dlist_size(list) = 0)
	{
		list->head = new_element;
		list->head->prev = NULL;
		list->head->next = NULL;
		list->tail = new_element;
	}
	else
	{
		new_element->prev = element->next;
		new_element->next = element;

		if(element->prev == NULL)
		{
			list->head = new_element;
		}
		else
		{
			element->prev->next = new_element;
		}

		element->prev = new_element;
	}

	list->size++;

	return 0;
}

int dlist_remove(DList* list,DListElmt* element, void** data)
{
	if(dlist_size(list) == 0 || element == NULL)
	{
		return -1;
	}

	*data = element->data;

	if(element == list->head)
	{
		list->head = element->next;

		if(list->head == NULL)
		{
			list->tail = NULL;
		}	
		else
		{
			element->next->prev = NULL;
		}

	}
	else
	{
		element->prev->next = element->next;
		if(element->next == NULL)
		{
			list->tail = element->prev;
		}
		else
		{
			element->next->prev = element->prev;
		}
	}

	free(element);
	list->size--;

	return 0;


}