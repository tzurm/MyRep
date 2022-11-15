#include <stdio.h>	/*  printf	    */
#include <stddef.h> /*	size_t		*/
#include <stdlib.h> /*	malloc		*/
#include "bst.h"

int CompareFunc(const void *data, void *param);
int CountFunc(void *data, void *param);
int PrintFunc(void *data, void *param);
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
	int arr[] = {25, 15, 50, 10, 22, 35, 4, 12, 18, 24, 70, 31, 44, 66, 90};
	size_t len = sizeof(arr) / sizeof(arr[0]);
	size_t i = 0;
	int a = 10;

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
	printf("\n-----post------------------------------------\n");
	i = ForEach(tree, PrintFunc, &a, POST_ORDER);
	printf("\n-----in--------------------------------------\n");
	i = ForEach(tree, PrintFunc, &a, IN_ORDER);
	printf("\n-----pre--------------------------------------\n");
	i = ForEach(tree, PrintFunc, &a, PRE_ORDER);
	printf("\n");

	printf("min: %d\n", *(int *)FindMin(tree));

	Destroy(tree);

	Remove(tree, &a);
	i = ForEach(tree, PrintFunc, &a, PRE_ORDER);
	printf("\n");
}

int CompareFunc(const void *data, void *param)
{
	return (*(int *)data - *(int *)param);
}

int PrintFunc(void *data, void *param)
{
	(void)param;
	printf("%d ", *(int *)data);
	return 1;
}
