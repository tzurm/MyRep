#include <stddef.h>
#include <stdio.h>

#include "../include/stack.h"
#include "../source/stack.c"

void CreateTest();

int main() 
{
   
	printf("\n*********** TESTS CreateTest ************************ \n\n");
	
	CreateTest();
	
	
	printf("\n*********** TESTS Destroy ************************ \n\n");
	
	return 0;
}

void CreateTest()
{
	stack_t mystack = Create(6 ,3);
}





