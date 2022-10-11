#include <stddef.h>					/*		size_t			*/
#ifndef __ILRD_CR02_LINKED_LIST_H__
#define __ILRD_CR02_LINKED_LIST_H__


typedef struct sll_t sll_t;

struct sll_t
{
	void *first;
	sll_t dummy;
	
}

struct sll_node
{
	void *data;
	sll_iter *next; /* address to next node*/
}

typedef sll_iter *ptr_node;



enum status {SUCCESS , REALLOC_ERROR};
typedef enum status status;



sll_t *SLLCreate(sll_t *node);

/****************************************************************************
* Creates linked list and returns pointer to memory address of first node	*
* Parameters:																*
*	node -	pointer to memory address of value of data						*												*****************************************************************************/

status *SLLDestroy(sll_t *node);
		להחזיר איטרטור של האיבר הראשון o1
sll_t *SLLBegin(sll_t *node);

sll_t *SLLNext(sll_t *node , iterator_t *it);
		להחזיר איטרטור של האיבר האחרון 0n
sll_t *SLLEnd(sll_t *node , sll_t *next);

void *SLLGetData(sll_t *node , sll_t *next);

void *SLLSetData(sll_t *node , sll_t *next);

status *SLLIsEqual(sll_t *node , sll_t *node);

iterator_t *SLLInsertBefore(sll_t *node, iterator_t *it);  מקבל איטרטור ולמכניס אחריו

status *SLLRemove(sll_t *node);

size_t *SLLCount(sll_t *node);

void *SLLFind(sll_t *node);

void *SLLForEach(sll_t *node);



#endif


