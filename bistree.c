#include <stdlib.h>
#include <string.h>
#include "bistree.h"


static void destroy_right(BisTree* tree, BiTreeNode* node);
static void destroy_left(BisTree* tree, BiTreeNode* node);

static void rotate_left(BiTreeNode **node)
{
	BiTreeNode *left, *grandchild;

	left = bitree_left(*node);
	if(((AvlNode*)bitree_data(left))->factor == AVL_LFT_HEAVY)
	{
		bitree_left(*node) = bitree_right(left);
		bitree_right(left) = *node;
		((AvlNode*)bitree_data(*node))->factor = AVL_BALANCED;
		((AvlNode*)bitree_data(left))->factor = AVL_BALANCED;
		*node = left;
	}
	else
	{
		grandchild = bitree_right(left);
		bitree_right(left) = bitree_left(grandchild);
		bitree_left(grandchild) = left;
		bitree_left(*node) = bitree_right(grandchild);
		bitree_right(grandchild) = *node;

		switch(((AvlNode*)bitree_data(grandchild))->factor)
		{
			case AVL_LFT_HEAVY:
				((AvlNode*)bitree_data(*node))->factor = AAVL_RGT_HEAVY;
				((AvlNode*)bitree_data(left))->factor = AVL_BALANCED;
				break;

			case AVL_BALANCED:
				((AvlNode*)bitree_data(*node))->factor = AVL_BALANCED;
				((AvlNode*)bitree_data(left))->factor = AVL_BALANCED;
				break;

			case AAVL_RGT_HEAVY:
				((AvlNode*)bitree_data(*node))->factor = AVL_BALANCED;
				((AvlNode*)bitree_data(left))->factor = AVL_LFT_HEAVY;
				break;
			default:
				break;
		}
		((AvlNode*)bitree_data(grandchild))->factor = AVL_BALANCED;
		*node = grandchild;
	}

}

static void rotate_right(BiTreeNode** node)
{
	BiTreeNode *right, *grandchild;

	right = bitree_right(*node);
	if(((AvlNode*)bitree_data(right))->factor == AVL_RGT_HEAVY)
	{
		bitree_right(*node) = bitree_left(right);
		bitree_left(right) = *node;
		((AvlNode*)bitree_data(*node))->factor = AVL_BALANCED;
		((AvlNode*)bitree_data(right))->factor = AVL_BALANCED;
		*node = right;
	}
	else
	{
		grandchild = bitree_left(right);
		bitree_ldft(right) = bitree_right(grandchild);
		bitree_right(grandchild) = right;
		bitree_right(*node) = bitree_left(grandchild);
		bitree_left(grandchild) = *node;

		switch(((AvlNode*)bitree_data(grandchild))->factor)
		{
			case AVL_LFT_HEAVY:
				((AvlNode*)bitree_data(*node))->factor = AAVL_RGT_HEAVY;
				((AvlNode*)bitree_data(right))->factor = AVL_BALANCED;
				break;

			case AVL_BALANCED:
				((AvlNode*)bitree_data(*node))->factor = AVL_BALANCED;
				((AvlNode*)bitree_data(right))->factor = AVL_BALANCED;
				break;

			case AAVL_RGT_HEAVY:
				((AvlNode*)bitree_data(*node))->factor = AVL_BALANCED;
				((AvlNode*)bitree_data(right))->factor = AVL_LFT_HEAVY;
				break;
			default:
				break;
		}
		((AvlNode*)bitree_data(grandchild))->factor = AVL_BALANCED;
		*node = grandchild;
	}
}

static void destroy_right(BisTree* tree, BiTreeNode* node)
{
	BiTreeNode **position;

	if(bitree_size(tree) == 0)
	{
		return;
	}

	if(node == NULL)
	{
		position = &tree->root;
	}
	else
	{
		position = &node->right;
	}

	if(*pistion != NULL)
	{
		destroy_left(tree,*position);
		destroy_right(tree,*position);

		if(tree->destroy != NULL)
		{
			tree->destory(((AvlNode*)(*position)->data)->data);
		}


		free((*position)->data);
		free(*position);
		*position = NULL;

		tree->size--;
	}

	return ;
}

static void destroy_left(BisTree* tree, BiTreeNode* node)
{
	BiTreeNode **position;

	if(bitree_size(tree) == 0)
	{
		return;
	}

	if(node == NULL)
	{
		position = &tree->root;
	}
	else
	{
		position = &node->left;
	}

	if(*pistion != NULL)
	{
		destroy_left(tree,*position);
		destroy_right(tree,*position);

		if(tree->destroy != NULL)
		{
			tree->destory(((AvlNode*)(*position)->data)->data);
		}


		free((*position)->data);
		free(*position);
		*position = NULL;

		tree->size--;
	}

	return ;
}


void bistree_init(BisTree* tree, void (*compare)(void* key1, void* key2), void (*destroy)(void *data))
{

}

void destroy(BisTree* tree)
{

}

int bistree_insert(BisTree* tree, const void* data)
{

}

int bistree_remove(BisTree* tree, void** data)
{

}

int bistree_lookup(const BisTree *tree, const void* data)
{

}
