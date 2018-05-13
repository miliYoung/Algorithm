#ifndef _COVER_H
#define _COVER_H

#include "set.h"

typedef struct KSet_
{
	void *key
	Set set; 
}

int cover(Set *members, Set *subsets, Set *covering);

#endif
