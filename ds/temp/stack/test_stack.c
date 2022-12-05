#include <stddef.h>
#include <stdio.h>
#include "stack.h"

void Test_1();

int main()
{

	printf("\n***********	Test_1		************************ \n\n");

	Test_1();

	return 0;
}

void Test_1()
{

	stack_t *my_stack = Create(5, 4);
	int value[] = {3, -1, 9, 278, 13};

	Push(my_stack, &value[0]);
	printf("current top:	%d\n", *(int *)Peek(my_stack));

	Push(my_stack, &value[1]);
	printf("current top:	%d\n", *(int *)Peek(my_stack));

	Push(my_stack, &value[2]);
	printf("current top:	%d\n", *(int *)Peek(my_stack));

	Push(my_stack, &value[3]);
	printf("current top:	%d\n", *(int *)Peek(my_stack));

	Push(my_stack, &value[4]);
	printf("current top:	%d\n", *(int *)Peek(my_stack));
	
	/*Pop(my_stack);
	printf("current top:	%.1f\n", *(float *)Peek(my_stack));

	IsEmpty(my_stack) ? printf("STATUS:		Empty stack\n") : printf("STATUS:		Not empty\n");
	printf("Size:		%ld\n", Size(my_stack));
	printf("Capacity:	%ld\n", Capacity(my_stack));

	printf("current top:	%.1f\n", *(float *)Peek(my_stack));*/
	printf("\n");
	SortStack(my_stack);
	printf("current top:	%d\n", *(int *)Peek(my_stack));
	Pop(my_stack);
	printf("current top:	%d\n", *(int *)Peek(my_stack));
	Pop(my_stack);
	printf("current top:	%d\n", *(int *)Peek(my_stack));
	Pop(my_stack);
	printf("current top:	%d\n", *(int *)Peek(my_stack));
	Pop(my_stack);
	printf("current top:	%d\n", *(int *)Peek(my_stack));
	
	
	Destroy(my_stack);
}
