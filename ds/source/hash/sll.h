#include <stddef.h> /*size_t*/
#ifndef __ILRD_CR02_LINKED_LIST_H__
#define __ILRD_CR02_LINKED_LIST_H__

typedef struct sll sll_t;

typedef struct sll_node	sll_node_t;

typedef struct sll_node * sll_iter_t;

typedef int (*FuncIsMatch_t)(const void *data, void *param);

typedef int (*ActionFunc_t)(void *data, void *param);

/****************************************************************************
* Creates linked list and returns pointer to memory address of first node	*
* Parameters:																*
*	node -	pointer to memory address of value of data	
0(1)				*						
*****************************************************************************/

sll_t *SLLCreate();

/****************************************************************************
* Destroy linked list and free the memory address							*
* Parameters:																*
*	node -	pointer to memory address of value of data						*
complexity - O(n)
*****************************************************************************/

void SLLDestroy(sll_t *list);
		
/****************************************************************************
* returns iterator  of first node	O(1)									*
* Parameters:																*
*	node -	pointer to memory address of value of data						*
*****************************************************************************/		
		
sll_iter_t SLLBegin(const sll_t *list);

/****************************************************************************
* returns iterator  of next node	O(1)									*
* Parameters:						
*	iter - 
*	node -	pointer to memory address of value of data						*
*****************************************************************************/		

sll_iter_t SLLNext(sll_iter_t iter);

/****************************************************************************
* returns iterator  of last node	O(n)									*
* Parameters:																*
*	node -	pointer to memory address of value of data						*
*****************************************************************************/

sll_iter_t SLLEnd(const sll_t *list);

void *SLLGetData(sll_iter_t iter);

void SLLSetData(sll_iter_t iter, void *data);

int SLLIsSameIter(sll_iter_t iter1, sll_iter_t iter2);


/*if fails return the end of list */

sll_iter_t SLLInsertBefore(sll_iter_t iter, void *data);  

/*return the iter the removed node pointed to*/

sll_iter_t SLLRemove(sll_iter_t iter);


/* return the node count in list  */

size_t SLLCount(const sll_t *list);


/*if fails return the end of range */

sll_iter_t SLLFind(int FuncIsMatch_t(), sll_iter_t from, sll_iter_t to, void *param);


/*on fail of func return error */

int SLLForEach(int ActionFunc_t(), sll_iter_t from, sll_iter_t to, void *param);

#endif


