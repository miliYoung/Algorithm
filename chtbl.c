#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "chtbl.h"


int chtbl_init(CHTbl *htbl, int buckets, int(*h)(const void* key), int(*match)(const void* key1, const void* key2), void (*destroy)(void *data))
{
	int i;

	if((htbl->table = (List*)malloc(buckets * sizeof(List))) ==  NULL)
	{
		return -1;
	}

	htbl->buckets = buckets;
	for( i = 0; i < htbl->buckets; ++i)
	{
		list_init(&htbl->table[i],destroy);
	}

	htbl-> = h;
	htbl->match = match;
	htbl->destroy = destroy;

	htbl->size = 0;

	return 0;
}


void chtbl_destroy(CHTbl *htbl)
{
	int i = 0;

	if(i = 0; i < htbl->buckets; ++i)
	{
		list_destroy(&htbl->table[i]);
	}

	free(htbl->table);

	memset(htbl, 0,sizeof(htbl));

	return ;
}

int chtbl_insert(CHTbl* htbl, const void* data)
{
	void *temp = NULL;
	int bucket = 0;
	int retval = 0;

	temp = data;
	if(chtbl_lookup(htbl,data) == 0)
	{
		return -1;
	}

	bucket = htbl->h(data) % htbl->buckets;

	if((retval = list_ins_next(&htbl->table[bucket],NULL, data)) == 0)
		htbl->size++;

	return retval;
}

int chtbl_remove(CHTbl* htbl,void ** data)
{
	ListElmt *element;
	ListElmt *prev;

	int bucket;

	bucket = htbl->h(*data) % htbl->buckets;

	for(element = list_head(&htbl->table[bucket]); element != NULL; element = list_next(element))
	{
		if(htbl->match(*data,list_data(element)))
		{
			if(list_rem_next(&htbl->table[bucket], prev, data) == 0)
			{
				htbl->size--;
				return 0;
			}
			else
			{
				return -1;
			}
		}
		
		prev = element;
	}

	return -1;
}

int chtbl_lookup(const CHtbl *htbl, void ** data)
{
	ListElmt* element;
	int bucket;

	bucket = htbl->h(*data) % htbl->buckets;

	for(element = list_head(&htbl->table[bucket]); element != NULL; element = list_next(element))
	{
		if(htbl->match(*data,list_data(element)))
		{
			*data = list_data(element);
			return 0;
		}
	}

	return -1;
}