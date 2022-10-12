#include <assert.h>					/*		assert			*/
#include <stddef.h>					/*		size_t			*/
#include <stdlib.h>					/*		malloc			*/
#include <stdio.h>					/*		printf			*/
#include "ll.h"					/*		ll				*/


struct sll 							/*		linked list 	*/
{
	sll_node_t *head;
	sll_node_t *dummy;
};

struct sll_node						/*		one node 		*/
{
	void *data;
	struct sll_node *next;		
};

/*****************************************************************************/
sll_t *SLLCreate()
{
	
	sll_t *list = (sll_t*)calloc(2,sizeof(sll_t));
	sll_node_t *dummy = (sll_node_t*)calloc(2,sizeof(sll_node_t));
	
	list -> head = dummy;
	list -> dummy = dummy;
	
	dummy -> next = dummy;
	dummy -> data = NULL;
	
	return list;
}
/*****************************************************************************/

void SLLDestroy(sll_t *list)
{
	sll_iter_t current = SLLBegin(list);
		
	while(NULL != SLLNext(current))
	{

		free(current -> data);
		current =  SLLNext(current);
	}
}
/*****************************************************************************/

sll_iter_t SLLBegin(const sll_t *list)
{
	
	return (list -> head);
}
/*****************************************************************************/

sll_iter_t SLLNext(sll_iter_t iter)
{
	
	return (iter -> next);
}

sll_iter_t SLLEnd(const sll_t *list)
{
	return (list -> dummy);
}

/*****************************************************************************/

void *SLLGetData(sll_iter_t iter)
{
	return (iter -> data);
}

/*****************************************************************************/
void SLLSetData(sll_iter_t iter, void *data)
{
	iter -> data = data;
}
/*****************************************************************************/

int SLLIsSameIter(sll_iter_t iter1, sll_iter_t iter2)
{
	return iter1 == iter2;
}

/*****************************************************************************/
/*							iter											*	
* 		*********			*********										*
*		*	A	*	--->	*	C	*										*
*		*********			*********										*
*							iter = new_node									*
*		*********			*********			*********					*
*		*	A	*	--->	*	b	* 	--->	*	c	* 					*
*		*********			*********			*********					*
*																			*	*****************************************************************************/														
sll_iter_t SLLInsertBefore(sll_iter_t iter, void *data)
{
	sll_iter_t new_node = (sll_node_t*)malloc(sizeof(sll_node_t));
	new_node = iter;
	
	iter -> data = data;
	iter -> next = new_node -> next;
	
	return iter;
}

/*****************************************************************************/
/*
sll_iter_t SLLRemove(sll_iter_t iter)
{
	sll_iter_t current = SLLBegin(list);
	
	
	
}
*/
/*****************************************************************************/

size_t SLLCount(const sll_t *list)
{
	size_t count = 0;
	sll_iter_t iter = SLLBegin(list);
	while (NULL != iter -> data)
	{
		++count;
		iter = SLLNext(iter);
	}
	
	return count;
}

/*****************************************************************************/
/*
sll_iter_t SLLFind(FuncIsMatch_t match, sll_iter_t from, sll_iter_t to, void *param);
	
*/
/*****************************************************************************/
/*
int SLLForEach(ActionFunc_t action, sll_iter_t from, sll_iter_t to, void *param);
*/


