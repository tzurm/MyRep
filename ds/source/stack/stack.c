#include <assert.h>					/*	assert	*/
#include <stddef.h>					/*	size_t	*/
#include "../include/bit_arr.h"


struct  stack
{
	char *head;
	size_t size;
	size_t capacity;
	size_t size_of_elemnets;
	
};


stack_t *Create(size_t capacity , size_t size_of_elemnets);
{
	stack my_stack ;
	my_stack.index = 0;
	my_stack.
}



void Destroy(stack_t* this_stack)
{
	

}

void Push(stack_t* this_stack , const void *value)	
{


}
void Pop(stack_t* this_stack)
{


}
void *Peek(stack_t* this_stack)

int IsEmpty(stack_t* this_stack)

size_t Size(stack_t* this_stack)

size_t Capacity(stack_t* this_stack)


