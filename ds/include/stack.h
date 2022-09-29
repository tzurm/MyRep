#include <stddef.h>
#ifndef __ILRD_CR02_STACK_H__
#define __ILRD_CR02_STACK_H__

typedef struct  stack stack_t;
			
stack_t *Create(size_t capacity , size_t size_of_elemnet);

void Destroy(stack_t* this_stack);							

void Push(stack_t* this_stack , const void *value);	

void Pop(stack_t* this_stack);

void *Peek(stack_t* this_stack);

int IsEmpty(stack_t* this_stack);

size_t Size(stack_t* this_stack);

size_t Capacity(stack_t* this_stack);


#endif


