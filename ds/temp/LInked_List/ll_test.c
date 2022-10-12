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
   
	
	Test_Create();
	
	
	return 0;
}


void Test_Create()
{
	
	sll_t *list = SLLCreate();
	sll_iter_t node = SLLBegin(list);
	int a = 4;
	printf("count nodes:	%ld\n" , SLLCount(list)); 
	node = SLLInsertBefore(node, &a);
	
	SLLDestroy(list); 
}





