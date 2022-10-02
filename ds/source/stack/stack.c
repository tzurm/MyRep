#include <assert.h>					/*		assert			*/
#include <stddef.h>					/*		size_t			*/
#include <stdlib.h>					/*		malloc			*/
#include <stdio.h>					/*		printf			*/
#include <string.h>					/*		printf			*/

#include "stack.h"

#define MALLOC_CHECK(ptr) if(NULL == ptr) {return NULL;}

struct stack
{
	char *stack_ptr;				/*	point to stack		*/
	size_t size;					/*	current size 		*/
	size_t capacity;				/*	max of the stack	*/
	size_t size_of_element;			/*	size of the element	*/

};


stack_t *Create(size_t capacity, size_t size_of_element)
{
	stack_t *hold_stack = (stack_t*)malloc(capacity*size_of_element);
	stack_t *hold_struct = (stack_t*)malloc(sizeof(stack_t));
	MALLOC_CHECK(hold_struct);
	MALLOC_CHECK(hold_struct);
	
	hold_struct -> stack_ptr = (char*)hold_stack;
	hold_struct -> size = 0;
	hold_struct -> capacity = capacity;
	hold_struct -> size_of_element = size_of_element;
	
	return hold_struct;
}


void Destroy(stack_t *stack)
{
	free(stack);
	
}

/*	pseudo							*
 *	check if the capacity is full	*
 	go to last address				*
 *	set the value					*
 *	set the size to size +1			*/
 

void Push(stack_t *stack, const void *value)
{
    if((stack -> size) < (stack -> capacity))
	{
	    *((stack -> stack_ptr) + (stack -> size)) = *(char*)value;
	    ++stack -> size;
	}
	else 
    {
		printf("ERROR:		Stack is full, can't add value\n");
    }
    
}

/*	pseudo							*
 *	check if the capacity is empty	*
 *	set the size to size -1			*/

void Pop(stack_t *stack)
{
	if(0 == stack -> size)
	{
		printf("ERROR:		Empty stack, can't pop from empty stack\n");
	}
	else
	{	/*
		--stack -> size;
		--stack -> size_of_element;
		--stack -> stack_ptr;
		*/
		stack -> size -= stack -> size_of_element;
	}

}

void *Peek(stack_t *stack)
{
    return (void*)(stack -> stack_ptr + stack -> size - stack -> size_of_element);
}

int IsEmpty(stack_t *stack)
{
	return (stack -> size == 0);
}
size_t Size(stack_t *stack)
{
	return stack -> size;
}
size_t Capacity(stack_t *stack)
{
	return stack -> capacity;
}

