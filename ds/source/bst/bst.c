#include <stdlib.h> /*		malloc			*/
#include <assert.h> /*		assert			*/
#include <stddef.h> /*		size_t			*/
#include <stdio.h>	/*		printf			*/
#include "bst.h"

struct node
{
	void *data;
	node_t *children[2];
};

struct bst
{
	node_t *root;
	CompareFunc_t CompareFunc;
};

bst_t *Create(CompareFunc_t CompareFunc)
{
	bst_t *bst = malloc(sizeof(bst_t));

	if (NULL == bst)
	{
		return (NULL);
	}

	bst->root = NULL;
	bst->CompareFunc = CompareFunc;

	return (bst);
}

void Destroy(bst_t *bst)
{

	(void)bst;
}

/*					example tree:						 10
														/ \
													   4   11
													  /		\
													 3	 	 13
													/ \
												   N   7
													  / \
													 6	 N 		  		*/
/* Approved by 13.11.2022*/
status_t Insert(bst_t *bst, void *data)
{
	node_t *root = NULL;
	node_t *new_node = NULL;
	int result = 0;
	assert(NULL != bst);

	root = bst->root;

	if (NULL == root)
	{
		bst->root = (node_t *)malloc(sizeof(node_t));
		bst->root->data = data;
		bst->root->children[Left] = NULL;
		bst->root->children[Right] = NULL;
		return SUCCESS;
	}

	result = bst->CompareFunc(bst->root->data, data);
	assert(result != 0);
	result = (result > 0) ? Left : Right;

	bst->root = bst->root->children[result];
	Insert(bst, data);
	new_node = bst->root;
	bst->root = root;
	bst->root->children[result] = new_node;
	return SUCCESS;
}

/*
status_t Insert(bst_t *bst, void *data)
{

	node_t *new_node = NULL;
	int right_left = -0xFF;

	if (bst->root == NULL)
	{
		new_node = (node_t *)malloc(sizeof(node_t));
		new_node->data = data;
		new_node->children[Right] = NULL;
		new_node->children[Left] = NULL;
		bst->root = new_node;
		return SUCCESS;
	}
	else
	{

		right_left = (bst->CompareFunc)(bst->root->data, data);
		if (right_left > 0)
		{
			right_left = Left;
		}
		if (right_left < 0)
		{
			right_left = Right;
		}
	}

	assert(bst->root->data != data);

	if (NULL != bst->root->children[right_left])
	{
		bst->root = bst->root->children[right_left];
		Insert(bst, data);
	}
	else
	{
		new_node = (node_t *)malloc(sizeof(node_t));
		new_node->data = data;
		bst->root->children[right_left] = new_node;
		return SUCCESS;
	}

	return FAIL;
}
*/

/* Approved by 13.11.2022*/
void *Find(bst_t *bst, void *data)
{
	node_t *old_root = NULL;
	node_t *child = NULL;
	int result = 0;

	assert(NULL != bst);

	old_root = bst->root;

	result = bst->CompareFunc(old_root->data, data);

	if (0 == result)
	{
		return old_root->data;
	}

	result = (result > 0) ? Left : Right;

	if ((NULL != old_root->children[result]))
	{
		bst->root = old_root->children[result];
		child = Find(bst, data);
		bst->root = old_root;
		return child;
	}
	return NULL;
}

/* pseudo															*
 *	if you null return 0 , if your children both null return 1		*
 *	else repeat send your left and right children					*/

size_t CountNodes(bst_t *bst)
{
	size_t count = 0;
	node_t *old_root = NULL;
	assert(NULL != bst);

	old_root = bst -> root;

	if(NULL == bst -> root)
	{
		return 0;
	}
	
	bst -> root = old_root -> children[Left];
	count +=  CountNodes(bst);
	bst -> root = old_root;
	
	bst -> root = old_root -> children[Right];
	count += CountNodes(bst);
	bst -> root = old_root;
	
	return 1 + count;
}

/*
int ForEach(bst_t *bst, int ActionFunc_t(), void *param, int traversal_type)
{

}
*/

/*static void Postorder(bst_t bst)
{
	if (bst->root == NULL)
		return;

	Postorder(bst->root->children[Left]);
	Postorder(bst->root->children[Right]);
}
*/