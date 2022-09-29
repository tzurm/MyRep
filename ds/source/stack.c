#include <assert.h>					/*	assert	*/
#include <stddef.h>					/*	size_t	*/
#include "../include/stack.h"


struct stack
{
	char *head;						/*	point to top of the stack	*/
	size_t size;					/*	current size 				*/
	size_t capacity;				/*	capacity of the stack		*/
	size_t size_of_elemnet;			/*	size of the elemnet			*/

};


stack_t *Create(size_t capacity , size_t size_of_elemnet);
{
	stack my_stack ;
	my_stack.size = 0;
	my_stack.capacity = capacity
	my_stack.size_of_elemnets = size_of_elemnets;
	
	return my_stack;
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
{
}
int IsEmpty(stack_t* this_stack)
{
}
size_t Size(stack_t* this_stack)
{
}
size_t Capacity(stack_t* this_stack)
{
}

