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

/* Approved by Andrey 14.11.2022*/
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

static void DestroyLeaves(bst_t *bst)
{
	node_t *old_tree = bst->root;

	if (NULL != bst->root->children[Left])
	{
		bst->root = bst->root->children[Left];
		DestroyLeaves(bst);
		bst->root = old_tree;
	}
	if (NULL != bst->root->children[Right])
	{
		bst->root = bst->root->children[Right];
		DestroyLeaves(bst);
		bst->root = old_tree;
	}
	free(bst->root);
}

void Destroy(bst_t *bst)
{
	assert(bst);
	if (NULL != bst->root)
	{
		DestroyLeaves(bst);
	}
	free(bst);
}

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
		if (NULL == bst->root)
		{
			return FAIL_MALLOC;
		}

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

void *Find(bst_t *bst, void *data)
{
	node_t *old_root = NULL;
	node_t *child = NULL;
	int result = 0;

	assert(NULL != bst);
	assert(NULL != data);

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
 *	if you null return 0 , return +1 and check your children		*/

size_t CountNodes(bst_t *bst)
{
	size_t count = 0;
	node_t *old_root = NULL;
	assert(NULL != bst);

	old_root = bst->root;

	if (NULL == bst->root)
	{
		return 0;
	}

	bst->root = old_root->children[Left];
	count += CountNodes(bst);
	bst->root = old_root;

	bst->root = old_root->children[Right];
	count += CountNodes(bst);
	bst->root = old_root;

	return 1 + count;
}

/* Approved by Ziv 14.11.2022*/

int ForEach(bst_t *bst, ActionFunc_t ActionFunc, void *param, int traversal_type)
{
	switch (traversal_type)
	{
	case PRE_ORDER:
		ForEachPre(bst, ActionFunc, param, traversal_type);
		break;

	case IN_ORDER:
		ForEachIn(bst, ActionFunc, param, traversal_type);
		break;

	case POST_ORDER:
		ForEachPost(bst, ActionFunc, param, traversal_type);
		break;
	}
	return SUCCESS;
}

int ForEachIn(bst_t *bst, ActionFunc_t ActionFunc, void *param, int traversal_type)
{
	node_t *root = NULL;

	assert(NULL != bst);
	assert(NULL != param);
	
	root = bst->root;

	if (NULL != root->children[Left])
	{
		bst->root = root->children[Left];
		ForEachIn(bst, ActionFunc, param, traversal_type);
		bst->root = root;
	}

	ActionFunc(root->data, param);

	if (NULL != root->children[Right])
	{
		bst->root = root->children[Right];
		ForEachIn(bst, ActionFunc, param, traversal_type);
		bst->root = root;
	}

	return SUCCESS;
}

/*working*/
int ForEachPre(bst_t *bst, ActionFunc_t ActionFunc, void *param, int traversal_type)
{
	node_t *root = NULL;

	assert(NULL != bst);
	assert(NULL != param);

	root = bst->root;

	ActionFunc(root->data, param);

	if (NULL != root->children[Left])
	{
		bst->root = root->children[Left];
		ForEachPre(bst, ActionFunc, param, traversal_type);
		bst->root = root;
	}
	if (NULL != root->children[Right])
	{
		bst->root = root->children[Right];
		ForEachPre(bst, ActionFunc, param, traversal_type);
		bst->root = root;
	}

	return SUCCESS;
}

int ForEachPost(bst_t *bst, ActionFunc_t ActionFunc, void *param, int traversal_type)
{
	node_t *root = NULL;

	assert(NULL != bst);
	assert(NULL != param);

	root = bst->root;
	if (NULL != root->children[Left])
	{
		bst->root = root->children[Left];
		ForEachPost(bst, ActionFunc, param, traversal_type);
		bst->root = root;
	}
	if (NULL != root->children[Right])
	{
		bst->root = root->children[Right];
		ForEachPost(bst, ActionFunc, param, traversal_type);
		bst->root = root;
	}
	ActionFunc(root->data, param);

	return SUCCESS;
}
/*
static int DestroyLeaf(bst_t *leaf)
{
	if (NULL == leaf)
	{
		return NULL;
	}
	if (NULL == leaf->root->children[Right] && NULL == leaf->root->children[Left])
	{
		free(leaf);
	}
	return NULL;
}
*/

void *FindMin(bst_t *bst)
{
	node_t *root = NULL;

	assert(NULL != bst->root);

	root = bst->root;

	while (NULL != root && NULL != root->children[Left])
	{
		root = root->children[Left];
	}
	return root;
}

bst_t *Remove(bst_t *bst, void *key)
{
	node_t *root = NULL;
	node_t *temp2 = NULL;

	if (NULL == bst->root)
	{
		return NULL;
	}
	root = bst->root;
	/*	if the key is smaller than the current root, go left	*/
	if (key < root->data)
	{
		bst->root = root->children[Left];
		root->children[Left] = Remove(bst, key)->root;
	}
	/*	if the key is bigger than the current root, go right	*/
	else if (key > root->data)
	{
		bst->root = root->children[Right];
		root->children[Right] = Remove(bst, key)->root;
	}
	/* found*/
	else
	{ /*	if one child or no child	*/
		if (NULL == root->children[Left])
		{
			node_t *temp = root->children[Right];
			free(root);
			return temp; /* PROBELM HERE!!*/
		}
		else if (NULL == root->children[Right])
		{
			node_t *temp = root->children[Left];
			free(root);
			return temp; /* PROBELM HERE!!*/
		}
		/*	case with two child	, find min
			find the min in the right subtree	*/
		bst->root = root->children[Right];
		temp2 = FindMin(bst);
		root->data = temp2->data; 
		root->children[Right] = Remove(bst, temp2->data)->root;
	}
	return bst;
}
