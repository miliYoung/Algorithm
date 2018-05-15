#ifndef _BISTREE_H
#define _BISTREE_H

#include "bitree.h"

#define AVL_LFT_HEAVY	1
#define AVL_BALANCED	0
#define AVL_RGT_HEAVY	-1

typedef struct AvlNode_
{
	void *data;
	int hidden;
	int factor;
}AvlNode;


#define BiTree BisTree;

void bistree_init(BisTree* tree, void (*compare)(void* key1, void* key2), void (*destroy)(void *data));

void destroy(BisTree* tree);

int bistree_insert(BisTree* tree, const void* data);

int bistree_remove(BisTree* tree, void** data);

int bistree_lookup(const BisTree *tree, const void* data);

#define bistree_size(tree) ((tree)->size)

#endif