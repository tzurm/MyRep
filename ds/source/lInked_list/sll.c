#include <assert.h>					/*		assert			*/
#include <stddef.h>					/*		size_t			*/
#include <stdlib.h>					/*		malloc			*/
#include "sll.h"					/*		sll				*/

#define TRUE 1
#define FALSE 0

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

/*******************approved by Andrey 12.10.22*******************************/
/*****************************************************************************/
sll_t *SLLCreate()
{
	
	sll_t *list = (sll_t*)malloc(sizeof(sll_t));
	sll_node_t *dummy = (sll_node_t*)malloc(sizeof(sll_node_t));
	
	list -> head = dummy;
	list -> dummy = dummy;
	
	dummy -> next = NULL;
	dummy -> data = (void*)list;
	
	return list;
}

/*******************approved by Andrey 12.10.22*******************************/
/*****************************************************************************/

void SLLDestroy(sll_t *list)
{
	sll_iter_t current = list -> head;
	sll_iter_t runner = NULL;
	
	while(list -> dummy != current)
	{
		runner = current -> next;
		free(current);
		current = runner;
	}
	
	free(list -> dummy);
	free(list);

}
/*******************approved by Arie 12.10.22*********************************/
/*****************************************************************************/

sll_iter_t SLLBegin(const sll_t *list)
{
	assert(NULL != list);
	
	return (list -> head);
}

/*******************approved by Arie 12.10.22*********************************/
/*****************************************************************************/

sll_iter_t SLLNext(sll_iter_t iter)
{
	assert(NULL != iter);
	
	return (iter -> next);
}

sll_iter_t SLLEnd(const sll_t *list)
{
	assert(NULL != list);
	
	return (list -> dummy);
}

/*******************approved by Arie 12.10.22*********************************/
/*****************************************************************************/

void *SLLGetData(sll_iter_t iter)
{
	assert(NULL != iter);
	
	return (iter -> data);
}

/*******************approved by Arie 12.10.22*********************************/
/*****************************************************************************/
void SLLSetData(sll_iter_t iter, void *data)
{
	assert(NULL != iter);
	
	iter -> data = data;
}
/*******************approved by Arie 12.10.22*********************************/
/*****************************************************************************/

int SLLIsSameIter(sll_iter_t iter1, sll_iter_t iter2)
{
	assert(NULL != iter1);
	assert(NULL != iter2);
	
	return iter1 == iter2;
}

/******************approved by Andrey 12.10.22*******************************/
/****************************************************************************
* InsertBefore																*
*							iter											*	
* 		*********			*********										*
*		*	A	*	--->	*	C	*	--->	...							*
*		*********			*********										*
*							iter = new_node									*
*		*********			*********			*********					*
*		*	A	*	--->	*	B	* 	--->	*	C	*	--->	...		*
*		*********			*********			*********					*
*																			*
*****************************************************************************/
													
sll_iter_t SLLInsertBefore(sll_iter_t iter, void *data)
{
	sll_iter_t new_node = (sll_node_t*)malloc(sizeof(sll_node_t));
	sll_t *sll = iter -> data;
	
	assert(NULL != iter);
	
	new_node -> next = iter -> next;
	new_node -> data = iter -> data;
	
	iter -> next = new_node;
	iter -> data = data;
	
	if(sll -> dummy == iter)
	{
		sll -> dummy = new_node;
	}
	
	return iter;
}
/******************approved by Andery 12.10.22******************************/
/****************************************************************************
* SLLRemove																	*
*						iter to remove										*	
* 	*********			*********			*********			*********	*
*	*	A	*	--->	*	B	* 	--->	*	C	*	--->	*	D	*	*
*	*********			*********			*********			*********	*
*																			*
	**********			*********											*
*	*REM NODE*	  =		*	B	* 											*
*	**********			*********											*
*																			*
*	*********			*********			*********						*
*	*	A	*	--->	*	C	* 	--->	*	D	*	--->	...			*
*	*********			*********			*********						*
*																			*
*****************************************************************************/

sll_iter_t SLLRemove(sll_iter_t iter)
{
	sll_t *temp = iter -> next -> data;  
	sll_iter_t temp_iter = iter -> next; 
	
	assert(NULL != iter);
	
	if(NULL == iter -> next -> next)
	{
		temp -> dummy = iter;
	}
	
	iter -> data = iter -> next -> data;
	iter -> next = iter -> next -> next;
	
	free(temp_iter);
	
	return iter;
}
/******************approved by Arie 12.10.22**********************************/	
/*****************************************************************************/

size_t SLLCount(const sll_t *list)
{
	size_t count = 0;
	sll_iter_t iter = SLLBegin(list);
	
	assert(NULL != list);
	
	while (NULL != iter -> next)
	{
		++count;
		iter = SLLNext(iter);
	}
	
	return count;
}


/******************approved by Alex 12.10.22**********************************/	
/*****************************************************************************/

sll_iter_t SLLFind
			(FuncIsMatch_t match, sll_iter_t from, sll_iter_t to, void *param)
{
	while(from != to)
	{
		if(TRUE == match(from , param))
		{
			return from;	
		}
		from = from -> next;
	}
	
	return to;
}	


/******************approved by Alex 12.10.22**********************************/	
/*****************************************************************************/

int SLLForEach(ActionFunc_t action, sll_iter_t from, sll_iter_t to, void *param)
{
	while(from != to)
	{
		if(TRUE == action(from , param))
		{
			return TRUE;	
		}
		from = from -> next;
	}
	
	return FALSE;
}



