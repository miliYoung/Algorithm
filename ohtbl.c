#include <stdlib.h>
#include <string.h>

#include "ohtbl.h"

static char vacated;

int ohtbl_init(OHTbl *htbl, int postions, int(*h1)(const void* key), int(*h1)(const void* key),int(*match)(const void* key1, const void* key2), void (*destroy)(void *data))
{

}

void ohtbl_destroy(OHTbl *htbl)
{

}

int ohtbl_insert(OHTbl* htbl, const void* data);
{

}

int ohtbl_remove(OHTbl* htbl,void ** data)
{

}

int ohtbl_lookup(const OHTbl *htbl,void ** data)
{
	
}