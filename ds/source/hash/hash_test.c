#include <stdio.h>	/*  printf	    */
#include <stddef.h> /*	size_t		*/
#include <stdlib.h> /*	malloc		*/
#include <ctype.h>	/* 	isupper		*/
#include "sll.h"
#include "hash.h"

#define TABLE_SIZE 10

int CompareFunc(const void *data, void *param);
size_t HashFunc(void *data);
void CountCollision(size_t *arr, size_t len);

void Test_Only_Create(void);
void Test_Create(void);
void Test_HashFunc(void);
void Test_Insert(void);

int main()
{
	printf("\n---------Test_Only_Create-------------------------------\n");
	Test_Only_Create();
	printf("\n---------Test_Create-------------------------------\n");
	Test_Create();
	printf("\n---------Test_HashFunc-----------------------------\n");
	Test_HashFunc();
	printf("\n---------Test_Insert-----------------------------\n");
	Test_Insert();

	return 0;
}

void Test_Only_Create(void)
{
	hash_t *table = NULL;
	size_t table_size = 10;
	(void)table;
	table = Create(table_size, CompareFunc, HashFunc);
	(NULL == table) ? printf("table is null") : printf("not null");
}

void Test_Create(void)
{
	size_t arr[] = {25, 15, 50, 10, 786745, 35, 4, 12, 18, 24, 70, 987797, 44, 66, 90};
	size_t len = sizeof(arr) / sizeof(arr[0]);
	size_t i = 0;
	hash_t *table = NULL;
	size_t table_size = 10;
	(void)table;
	table = Create(table_size, CompareFunc, HashFunc);

	for (i = 0; i < len; ++i)
	{
		Insert(table, &arr[i]);
	}
}
void Test_HashFunc(void)
{
	size_t arr[] = {25, 15, 50, 10, 786745, 35, 4, 12, 18, 24, 70, 987797, 44, 66, 90};
	size_t len = sizeof(arr) / sizeof(arr[0]);
	size_t arr_hash[50] = {0};
	size_t i = 0;

	printf("index\tvalue\thash-value\n");
	for (i = 0; i < len; ++i)
	{
		arr_hash[i] = HashFunc(&arr[i]);
		printf("%ld\t%ld\t%ld\n", i, arr[i], HashFunc(&arr[i]));
	}
	printf("Collision-------------\n");
	CountCollision(arr_hash, len);
}
void Test_Insert(void)
{
	FILE *fp = fp;
	char str[60] = "";
	size_t i = 0;

	fp = fopen("words.txt", "r");
	if (NULL == fp)
	{
		perror("Error opening file");
	}
	for (i = 0; i < 10; ++i)
	{
		if (NULL != fgets(str + i, 60, fp))
		{
			puts(str);
		}
	}
	fclose(fp);
}
/******************************************************************/
int CompareFunc(const void *data, void *param)
{
	return (*(int *)data - *(int *)param);
}

size_t HashFunc(void *data)
{
	char *data_char = (char *)data;
	size_t hash = 5381;
	int c = 0;

	while ((c = *data_char++))
	{
		if (isupper(c))
		{
			c = c + 32;
		}

		hash = ((hash << 5) + hash) + c;
	}
	return hash % TABLE_SIZE;
}

void CountCollision(size_t *arr, size_t len)
{
	size_t i = 0;
	size_t j = 0;
	size_t count = 0;

	for (i = 0; i < len; ++i)
	{

		for (i = 1; i < len; ++i)
		{
			if (arr[i] == arr[j])
			{
				++count;
				printf("%ld , %ld \n", i, j);
			}
		}
	}
	printf("Total %ld\n", count);
}
