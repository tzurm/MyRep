#include <stdio.h>
#include <stddef.h>
#include "ll.h"					/*		lls				*/


void Test_Create();
/*void Test_Reserve();
void Test_Shrink();
void Test_ShrinkByPop();
void PrintVector(vector_t *vector);
*/
int main() 
{
   
	printf("\n\n****************	Test_Create&insert	**************\n");
	Test_Create();
	
	
	return 0;
}


void Test_Create()
{
	sll_t *list = SLLCreate();
	
	printf("count nodes:	%ld" , SLLCount(list));
	SLLDestroy(list); 
}
/*
void Test_Reserve()
{
	r_t *vector)
{
	size_t i = 0;	*/
	/*
	for(i = 0 ; i < VectorCapacity(vector) ; ++i)
	{
		printf("%d | ", *(int*)VectorAccessElement(vector,i));
	}*/
	/*
	printf("\n");
	for(i = 0 ; i < VectorSize(vector) ; ++i)
	{
		printf("%d | ", *(int*)VectorAccessElement(vector,i));
	}
}

*/


