#include <assert.h>					/*		assert			*/
#include <stddef.h>					/*		size_t			*/
#include <stdlib.h>					/*		malloc			*/
#include <stdio.h>					/*		printf			*/
#include <string.h>					/*		memcpy			*/
#include "stack.h"					/*		my_stack		*/

#define MALLOC_CHECK(ptr) if(NULL == ptr) {return NULL;}

struct stack
{
	char *stack_ptr;				/*	point to stack		*/
	size_t size;					/*	current size 		*/
	size_t capacity;				/*	max of the stack	*/
	size_t size_of_element;			/*	size of the element	*/

};

/* approved by roman 2.9 */

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
	assert(NULL != stack);
	
	free(stack -> stack_ptr);
	free(stack);
}


/*	pseudo										*
 *	check if the capacity is full				*
 *	push the value by memcpy for int value		*
 *	set the size to size +1						*/
 

void Push(stack_t *stack, const void *value)
{
	assert(((stack -> size) / stack -> size_of_element) < (stack -> capacity)); 
		
	memcpy((stack -> stack_ptr) + (stack -> size),
	 value, stack -> size_of_element);
    stack -> size += stack -> size_of_element;   
}

/*	pseudo							*
 *	check if the capacity is empty	*
 *	set the size to size -1			*/
 	
 
void Pop(stack_t *stack)
{
/*	assert((stack -> size) > 0);	*/
	
	if(0 == stack -> size)
	{
		printf("ERROR:		Empty stack, can't pop from empty stack\n");
	}
	else
	{	
		stack -> size -= stack -> size_of_element;
	}

}

void *Peek(stack_t *stack)
{
	assert(NULL != stack);	
	
    return (void*)
    (stack -> stack_ptr + stack -> size - stack -> size_of_element);
}

int IsEmpty(stack_t *stack)
{
	assert(NULL != stack);	
	
	return (stack -> size == 0);
}
size_t Size(stack_t *stack)
{
	assert(NULL != stack);	
	
	return stack -> size / stack -> size_of_element;
}
size_t Capacity(stack_t *stack)
{
	assert(NULL != stack);
	
	return stack -> capacity;
}

