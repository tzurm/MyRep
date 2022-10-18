#include <stdio.h>
#include <stddef.h>
#include "sll.h"					/*		sll			*/


void Test_Create();
void Test_Same_Iter();
void Test_Get_Set();
void Test_Count_Remove();
int main() 
{
   
	printf("*************************\n*   Test Create		* \n*************************\n");
	Test_Create();
	
	printf("*************************\n*   Test Same Iter	* \n*************************\n");
	Test_Same_Iter();
	
	
	printf("*************************\n*   Test Get&Set	* \n*************************\n");
	Test_Get_Set();
	
	printf("*************************\n*   Test CountRemove	*	\n*************************\n");
	Test_Count_Remove();
	
	
	return 0;
}


void Test_Create()
{
	
	sll_t *list = SLLCreate();
	sll_iter_t node = SLLBegin(list);
	int a = 4 , b=8;
	printf("Create:		success\n"); 		
	node = SLLInsertBefore(node, &a);
	node = SLLInsertBefore(node, &b);
	printf("Count nodes:	%ld\n" , SLLCount(list)); 	
	SLLDestroy(list);
	printf("Destroy:	success\n"); 	
	
}

void Test_Same_Iter()
{
	sll_t *list = SLLCreate();
	sll_iter_t node_begin = SLLBegin(list);	
	int a = 4;
	printf("Count nodes:	%ld\n" , SLLCount(list)); 
	SLLIsSameIter(node_begin,SLLNext(node_begin)) ?
		printf("Same iter:	yes\n") : printf("Same iter:	no\n");
		
	node_begin = SLLInsertBefore(node_begin, &a);
	printf("Count nodes:	%ld\n" , SLLCount(list)); 
	SLLIsSameIter(node_begin,node_begin) ?
		printf("Same iter:	yes\n") : printf("Same iter:	no\n");
	SLLIsSameIter(node_begin,SLLNext(node_begin)) ?
		printf("Same iter:	yes\n") : printf("Same iter:	no\n");
	
	SLLDestroy(list);
}

void Test_Get_Set()
{
	sll_t *list = SLLCreate();
	sll_iter_t node_begin = SLLBegin(list);	
	int a = 4 , b = 8;
	node_begin = SLLInsertBefore(node_begin, &a);
	
	printf("Value:		%d\n" , *(int*)SLLGetData(node_begin));
	SLLSetData(node_begin, &b);
	printf("Set to:		%d\n" , *(int*)SLLGetData(node_begin));
	
	SLLDestroy(list);
}

void Test_Count_Remove()
{
	sll_t *list = SLLCreate();
	
	sll_iter_t node_begin = SLLBegin(list);
	int a = 4;
	
	printf("Count nodes:	%ld\n" , SLLCount(list)); 
	
	node_begin = SLLInsertBefore(node_begin, &a);
	node_begin = SLLInsertBefore(node_begin, &a);
	printf("Count nodes:	%ld\n" , SLLCount(list)); 
	
	node_begin = SLLRemove(node_begin);
	printf("Count nodes:	%ld\n" , SLLCount(list));
	node_begin = SLLRemove(node_begin);
	printf("Count nodes:	%ld\n" , SLLCount(list));
	
	SLLDestroy(list);
	
}
