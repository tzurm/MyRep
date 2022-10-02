#include <stddef.h>					/*			size_t				*/
#ifndef __ILRD_CR02_STACK_H__
#define __ILRD_CR02_STACK_H__

typedef struct stack stack_t;


stack_t *Create(size_t capacity , size_t size_of_elemnet);

void Destroy(stack_t *stack);							

void Push(stack_t *stack , const void *value);	

void Pop(stack_t *stack);

void *Peek(stack_t *stack);

int IsEmpty(stack_t *stack);

size_t Size(stack_t *stack);

size_t Capacity(stack_t *stack);


#endif


