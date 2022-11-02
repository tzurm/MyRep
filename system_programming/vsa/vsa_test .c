#include <stdio.h>
#include <stddef.h>
#include <stdlib.h> /*		malloc		*/
#include "vsa.h"	/*		fsa			*/

#define END (long)0xBADC0FFEE0DDF00D

static void PrintAlloc(void* mem)
{
	long *runner =NULL;
	runner =(long*)mem;

	while(END != *runner) 
    {
        printf("%p	| %ld\n",runner,*runner);
        runner += 1;
    }
	 printf("%p	| %ld\n",runner,*runner);
}

void Test_Init();
void Test_Init1();
void Test_Defrag();
int main()
{
	printf("*************************\n*   Test_Init		* \n*************************\n");
	Test_Init();

	printf("*************************\n*   Test_Init1		* \n*************************\n");
	Test_Init1();

	printf("*************************\n*   Test_Defrag		* \n*************************\n");
	Test_Defrag();

	return 0;
}

void Test_Init()
{
	void *mem = NULL;
	vsa_t *pool = NULL;
	size_t *runner =NULL;
	size_t pool_size = 24;

	mem = malloc(pool_size);
	pool = Init(pool_size, mem);
	runner =(size_t*)pool;
	printf("pool size:	%ld\n", *runner);
	PrintAlloc(mem);
	free(mem);

}
void Test_Init1()
{

	void *mem = NULL;
	vsa_t *pool = NULL;
	size_t pool_size = 201;
	void *p1 = NULL, *p2 = NULL, *p3 = NULL, *p4 = NULL, *p5 = NULL;
	size_t *runner =NULL;

	mem = malloc(pool_size);
	pool = Init(pool_size, mem);
	runner =(size_t*)pool;
	printf("pool size:	%ld\n", *runner);
	PrintAlloc(mem);
/*
	printf("Largest: %ld\n" ,LargestChunkAvailable(pool));
*/	
	p1 = Alloc(pool, 7);  
	p2 = Alloc(pool, 20); 
	p3 = Alloc(pool, 10); 
/*
	printf("Largest: %ld\n" ,LargestChunkAvailable(pool));
*/
	p4 = Alloc(pool, 40); 
	PrintAlloc(mem);
/*
	printf("Largest: %ld\n" ,LargestChunkAvailable(pool));
*/
	p5 = Alloc(pool, 40); 
	runner =(size_t*)pool;
	Free(p1);
	Free(p2);
	Free(p3);
	Free(p4);
	Free(p5);
	
	PrintAlloc(mem);
	free(mem);
}
void Test_Defrag()
{
	void *mem = NULL;
	vsa_t *pool = NULL;
	size_t pool_size = 85;
	void *p1 = NULL, *p2 = NULL, *p3 = NULL;
	size_t *runner =NULL;

	mem = malloc(pool_size);
	pool = Init(pool_size, mem);
	runner =(size_t*)pool;
	printf("pool size:	%ld\n", *runner);
	p1 = Alloc(pool, 7);  
	p2 = Alloc(pool, 8); 
	p3 = Alloc(pool, 8); 
	PrintAlloc(mem);
	Free(p1);
	Free(p2);
	Free(p3);
	free(mem);
}

