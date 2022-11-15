#include <stdio.h>	/*  printf	    */
#include <stddef.h> /*	size_t		*/
#include <stdlib.h> /*	malloc		*/
#include <ctype.h>	/* 	isupper		*/
#include "sll.h"
#include "hash.h"

#define TABLE_SIZE 150000

int CompareFunc(const void *data, void *param);
size_t Hash(const char *data)

	void Test_Create();

int main()
{
	printf("\n---------Test_Create-------------------------------\n");
	Test_Create();

	return 0;
}

void Test_Create()
{
	hash_t *table = NULL;
	int arr[] = {25, 15, 50, 10, 22, 35, 4, 12, 18, 24, 70, 31, 44, 66, 90};
	size_t len = sizeof(arr) / sizeof(arr[0]);
	size_t table_size = 50000;

	table = Create(table_size, CompareFunc, hash);
}

int CompareFunc(const void *data, void *param)
{
	return (*(int *)data - *(int *)param);
}

size_t Hash(const char *data)
{
	size_t hash = 5381;
	int c = 0;

	while ((c = *data++))
	{
		if (isupper(c))
		{
			c = c + 32;
		}

		hash = ((hash << 5) + hash) + c;
	}
	return hash % TABLE_SIZE;
}