#include <stdlib.h>
#include <string.h>

#include "ohtbl.h"

static char vacated;

int ohtbl_init(OHTbl *htbl, int postions, int(*h1)(const void* key), int(*h2)(const void* key), int(*match)(const void* key1, const void* key2), void (*destroy)(void *data))
{
	int i;

	if((htbl->table = (void **)malloc(postions* sizeof(void*))) ==  NULL)
	{
		return -1;
	}

	htbl->postions = postions;

	for(i = 0; i < htbl->postions; ++i)
	{
		htbl->table[i] = NULL;
	}

	htbl->vacated = &vacated;	

	htbl->h1 = h1;
	htbl->h2 = h2;
	htbl->match = match;
	htbl->destroy = destroy;

	htbl->size = 0;

}

void ohtbl_destroy(OHTbl *htbl)
{
	int i = 0;

	if(htbl->destroy != NULL)
	{
		for(i = 0; i < htbl->postions; ++i)
		{
			if(htbl->table[i] != NULL && htbl->table[i] != htbl->vacated)
			{
				htbl->destroy(htbl->table[i]);
			}
		}
	}

	free(htbl->table);


	return ;
}

int ohtbl_insert(OHTbl* htbl, const void* data);
{
	void *temp;
	int position = 0,i = 0;

	if(htbl->size == htbl->positions)//这个判断没有弄清楚
		return -1;

	temp = (void*)data;
	if(ohtbl_lookup(htbl,&temp) == 0)
	{
		return 1;
	}

	for( i = 0; i < htbl->positions; ++i)
	{
		position = (htbl->h1(data) + (i*htbl->h2(data))) % htbl->positions;
		if(htbl->table[positon] == NULL || htbl->table[position]== htbl->vacated)
		{
			htbl->table[position] = (void*)data;
			htbl->size++;
			return 0;
		}
	}

	return -1;
}

int ohtbl_remove(OHTbl* htbl,void ** data)
{
	int position = 0;
	int i = 0;

	for(i = 0; i < htbl->positions; ++i)
	{
		position = (htbl->h1(*data) + (i*htbl->h2(*data))) % htbl->positions;

		if(htbl->table[position] == NULL)
		{
			return -1;
		}
		else if(htbl->table[position] == htbl->vacated)
		{
			continue;
		}
		else if(htbl->match(htbl->table[position],*data))
		{
			*data = htbl->table[position];
			htbl->table[position] = htbl->vacated;
			htbl->size--;
			return 0;
		}
	}

	return -1;
}

int ohtbl_lookup(const OHTbl *htbl,void ** data)
{
	int position = 0, i = 0;

	for(i = 0; i < htbl->positions; ++i)
	{
		position = (htbl->h1(*data) + (i*htbl->h2(*data))) % htbl->positions;

		if(htbl->table[position] == NULL)
		{
			return -1;
		}
		else if(htbl->match(htbl->table[position],*data))
		{
			*data = htbl->table[position];
			return 0;
		}
	}
	return -1;
	
}