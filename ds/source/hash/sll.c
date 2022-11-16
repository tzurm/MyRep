#include <stdlib.h> /*malloc*/
#include <assert.h> /*assert*/
#include <string.h> /*memcpy*/
#include "sll.h"

/*#include <stdio.h>*/

#define NODE_DATA node -> data 
#define NODE_NEXT node -> next 

#define LIST_HEAD list -> head
#define LIST_DUMMY list -> dummy 
       
#define FAILED 1
#define SUCCESS 0   
        

struct sll 		
{
	sll_node_t *head;
	sll_node_t *dummy;
};

struct sll_node	
{
	void *data;
	struct sll_node *next;
};

/*
date: 
writer: mark
reviwer: ziv
status: approved
*/

sll_t *SLLCreate()
{
    sll_node_t * node = NULL; 
    sll_t * list = (sll_t *)malloc(sizeof(sll_t)); 
    if(NULL == list)
    {
        return NULL;
    }
    
    node = (sll_node_t *)malloc(sizeof(sll_node_t));   
    if(NULL == node)
    {
        free(list);
        return NULL;
    }
    
    LIST_HEAD = node;
    LIST_DUMMY = node;
    
    NODE_DATA = (void*)list;
    NODE_NEXT = NULL;
    
    return list;
}

/*
date: 
writer: mark
reviwer: ziv
status: approved
*/

void SLLDestroy(sll_t *list)
{
    sll_node_t * next_one = NULL;
    assert(list);
    do
    {
        next_one = LIST_HEAD -> next;
        free(LIST_HEAD);    
        LIST_HEAD = next_one;
    }
    while(NULL != LIST_HEAD);
    free(list);
}

/*
date: 
writer: mark
reviwer: ziv
status: approved
*/

sll_iter_t SLLBegin(const sll_t *list)
{
    return LIST_HEAD;
}

/*
date: 
writer: mark
reviwer: ziv
status: approved
*/

sll_iter_t SLLNext(sll_iter_t iter)
{
    return iter -> next;
}

/*
date: 
writer: mark
reviwer: ziv
status: approved
*/

sll_iter_t SLLEnd(const sll_t *list)
{
    return LIST_DUMMY;
}

/*
date: 
writer: mark
reviwer: ziv
status: approved
*/

void *SLLGetData(sll_iter_t iter)
{
    return iter -> data;
}

/*
date: 
writer: mark
reviwer: ziv
status: approved
*/

void SLLSetData(sll_iter_t iter, void *data)
{
    iter -> data = data;
}

/*
date: 
writer: mark
reviwer: ziv
status: approved
*/

int SLLIsSameIter(sll_iter_t iter1, sll_iter_t iter2)
{
    return(iter1 == iter2);
}

/*
date: 
writer: mark
reviwer: ziv
status: approved
*/

sll_iter_t SLLInsertBefore(sll_iter_t iter, void *data)
{
    
    sll_node_t *new_node = (sll_node_t *)malloc(sizeof(sll_node_t)); 
    if(NULL == new_node)
    {
        while(NULL != iter -> next)
        {
            iter = iter -> next;
        }
        return iter;
    }    
    
    memcpy((void*)new_node, (void*)iter, sizeof(sll_node_t));
    iter -> data = data;
    iter -> next = new_node;
    
    if(NULL == new_node -> next)
    {
        (((sll_t *)(new_node -> data)) -> dummy) = new_node;
    }
    return iter;
}

/*
date: 
writer: mark
reviwer: ziv
status: approved
*/

sll_iter_t SLLRemove(sll_iter_t iter)
{
    /* very intresting*/
    void * next = (void*)iter -> next;
    
    /*check if the user sent the dummy node*/
    assert(NULL != iter -> next);
    
    memcpy((void*)iter, (void*)iter -> next, sizeof(sll_node_t));
    free(next);

    /*update the dummey address is nessery*/
    if(NULL == iter -> next)
    {
        (((sll_t *)(iter -> data)) -> dummy) = iter;
    }    
    return iter;
}

/*
date: 
writer: mark
reviwer: ziv
status: approved
*/

size_t SLLCount(const sll_t *list)
{
    size_t i = 1;
    sll_iter_t iterator = LIST_HEAD;
    while(NULL != iterator -> next)
    {
        iterator = iterator -> next;
        ++i;
    }
    return i;
}

/*
date: 
writer: mark
reviwer: ziv
status: approved
*/

sll_iter_t SLLFind(int FuncIsMatch_t(), sll_iter_t from, sll_iter_t to, void *param)
{
    while(from != to)
    {
        if((*FuncIsMatch_t)(((void*)from -> data), param))
        {
            return from;
        }        
        from = from -> next;
    }
    return to;
}

/*
date: 
writer: mark
reviwer: ziv
status: approved
*/

int SLLForEach(int ActionFunc_t(), sll_iter_t from, sll_iter_t to, void *param)
{
    while(from != to)
    {
        if((*ActionFunc_t)(((void*)from -> data), param))
        {
            return FAILED;
        }        
        from = from -> next;
    }
    return SUCCESS;
}

/*
void print_all(sll_t *list, sll_iter_t iter)
{
    sll_node_t * runner = LIST_HEAD;
    size_t i = 0;
    printf("\ncointainer:\n");  
    printf("----------------------\n");
    printf("|list head: %p |\n", LIST_HEAD);
    printf("|list tail: %p |\n", LIST_DUMMY);
    printf("|iter: %p |\n", iter);
    printf("----------------------\n");
    
    printf("######################\n");
    do
    {
        printf("----------------------\n");
        printf("|address: %p|\n",(void*)LIST_HEAD);
        printf("|next: %p|\n",(void*)LIST_HEAD -> next);
        printf("|n: %lu  data: %d|\n",i ,*(int*)LIST_HEAD -> data);
        printf("----------------------\n");
        printf("######################\n");
        LIST_HEAD = LIST_HEAD -> next;
        ++i;
    }
    while(NULL != LIST_HEAD);
    LIST_HEAD = runner;
}
*/


