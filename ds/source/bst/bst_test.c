#include <stdio.h>	/*  printf	    */
#include <stddef.h> /*	size_t		*/
#include <stdlib.h> /*	malloc		*/
#include "bst.h"

int CompareFunc(const void *data, void *param);
void Test_Create();

int main()
{
	printf("\n---------Test_Create-------------------------------\n");
	Test_Create();

	return 0;
}
/*					example tree:						 10
														/ \
													   4   11
													  /		\
													 3	 	 13
													/ \
												   N   7
													  		  		*/
void Test_Create()
{
	bst_t *tree = NULL;
	int arr[] = {10, 4,11, 3, 7, 13};
	size_t len = sizeof(arr) / sizeof(arr[0]);
	size_t i = 0;

	tree = Create(CompareFunc);

	for (i = 0; i < len; ++i)
	{
		Insert(tree, &arr[i]);
	}
	for (i = 0; i < len; ++i)
	{
		if (&arr[i] == Find(tree, &arr[i]))
		{
			printf("good!\n");
		}
		else
		{
			printf("bad!\n");
		}
	}
	printf("CountNodes %ld\n", CountNodes(tree));
	
}

int CompareFunc(const void *data, void *param)
{
	return (*(int *)data - *(int *)param);
}
int CountFunc(const void *data, void *param)
{
	(void)data;
	(void)param;
	return 1;
}
int PrintFunc(const void *data, void *param)
{
	(void)param;
	printf("%d " , *(int*)data);
	return 1;
}