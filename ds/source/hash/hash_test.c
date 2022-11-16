#include<stdio.h>/*printf()*/
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "hash.h"
#define ARRAY_LEN 9

int CompareFunction(const void * data, void * param)
{
    return !strcmp(data, param);
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
	return hash % ARRAY_LEN;
}

typedef struct student
{
    char name[8];
    size_t age;
    size_t id;
}student_t;

void InsertTest()
{
    hash_t * table = NULL;
    student_t class[ARRAY_LEN];
    size_t i = 0;
    size_t j = 0;


    char Mark[8]   = "Mark";
    char Tzur[8]   = "Tzur";
    char Alex[8]   = "Alex";
    char Pinhas[8] = "Pinhas";
    char Ziv[8]    = "Ziv";
    char Andrey[8] = "Andrey";
    char Slava[8]  = "Slava";
    char Roman[8]  = "Roman";
    char Arie[8]   = "Arie";
    char * runner = Mark;
    (void)Tzur;
    (void)Alex;
    (void)Pinhas;
    (void)Ziv;
    (void)Andrey;
    (void)Slava;
    (void)Roman;
    (void)Arie;

    table = Create(ARRAY_LEN, CompareFunction, HashFunc);

    for (i = 0; i < ARRAY_LEN; ++i)
    {
        class[i].id = i * 123;
        class[i].age = i * 3;
        for (j = 0; j < 8; ++j)
        {
            class[i].name[j] = *runner;
            ++runner;
        }
    }
    for (i = 0; i < ARRAY_LEN; ++i)
    {
        Insert(table, &class[i]);
    }

    if (ARRAY_LEN != Count(table))
    {
        printf("FAILED insert or count\n");
    }
    else
    {
        printf("PASS insert and count\n");
    }

    if ((void*)&class[0] == Find(table, Mark)    &&
        (void*)&class[1] == Find(table, Tzur)    &&
        (void*)&class[2] == Find(table, Alex)    &&
        (void*)&class[3] == Find(table, Pinhas)  &&
        (void*)&class[4] == Find(table, Ziv)     &&
        (void*)&class[5] == Find(table, Andrey)  &&
        (void*)&class[6] == Find(table, Slava)   &&
        (void*)&class[7] == Find(table, Roman)   &&
        (void*)&class[8] == Find(table, Arie))
                                                            
    {
        printf("PASS find\n");
    }
    else
    {
        printf("FAILED find\n");
    }
    
    Remove(table, Mark);
    Remove(table, Tzur);
    Remove(table, Alex);
    Remove(table, Pinhas);
    Remove(table, Ziv);
    Remove(table, Andrey);
    Remove(table, Slava);
    Remove(table, Roman);
    Remove(table, Arie);
    
    if (0 != Count(table))
    {
        printf("FAILED insert or count\n");
    }
    else
    {
        printf("PASS insert and count\n");
    }

    Destroy(table);    
}

int main()
{
    InsertTest();

    return 0;
}
