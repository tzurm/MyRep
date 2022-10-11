#include <stddef.h>
#include <stdio.h>
#include "stack.h"

void Test_1();
void Test_2_EmptyStack();

int main() 
{
   
	printf("\n***********	Test_1		************************ \n\n");
	
	Test_1();
	
	
	printf("\n***********	Test_2_EmptyStack ************************ \n\n");
	
	Test_2_EmptyStack();
	
	
	
	
	return 0;
}



void Test_1()
{

	stack_t *my_stack = Create(4 ,4);
	float value[] ={3.2,6,9,278};
	
	Push(my_stack , &value[0]);
	printf("current top:	%.2f\n",*(float*)Peek(my_stack));
	
	Push(my_stack , &value[1]);
	printf("current top:	%.2f\n",*(float*)Peek(my_stack));
	
	Push(my_stack , &value[2]);
	printf("current top:	%.2f\n",*(float*)Peek(my_stack));
	
	Push(my_stack , &value[3]);
	printf("current top:	%.2f\n",*(float*)Peek(my_stack));
	/* test for push when limit
	Push(my_stack , &value[3]);
	printf("current top:	%.2f\n",*(float*)Peek(my_stack));
	*/
	Pop(my_stack);
	printf("current top:	%.2f\n",*(float*)Peek(my_stack));
	
	IsEmpty(my_stack) ? 
	printf("STATUS:		Empty stack\n") : printf("STATUS:		Not empty\n");
	printf("Size:		%ld\n",Size(my_stack));
	printf("Capacity:	%ld\n",Capacity(my_stack));
	Destroy(my_stack);

}

void Test_2_EmptyStack()
{
	stack_t *empty_stack = Create(6 ,1);
	
	printf("current top:	%d\n",*(int*)Peek(empty_stack));								
	IsEmpty(empty_stack) ? 
	printf("STATUS:		Empty stack\n") : printf("STATUS:		Not empty\n");
	printf("Current Size:	%ld\n",Size(empty_stack));
	printf("Capacity:	%ld\n",Capacity(empty_stack));
	Pop(empty_stack);						
	
	
	Destroy(empty_stack);
}




