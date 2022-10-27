#include <stdio.h>
#include <stddef.h>
#include <stdlib.h> /*		malloc		*/
#include "vsa.h"	/*		fsa			*/

void Test_Init();
void Test_Defrag();
int main()
{

	printf("*************************\n*   Test_Init		* \n*************************\n");
	Test_Init();

	printf("*************************\n*   Test_Defrag		* \n*************************\n");
	Test_Defrag();

	return 0;
}

void Test_Init()
{

	void *mem = NULL;
	vsa_t *pool = NULL;
	size_t pool_size = 200;
	void *p1 = NULL, *p2 = NULL, *p3 = NULL, *p4 = NULL, *p5 = NULL;

	size_t i = 0;
	size_t *runner =NULL;

	mem = malloc(pool_size);
	pool = Init(pool_size, mem);
	runner =(size_t*)pool;

	printf("Largest: %ld\n" ,LargestChunkAvailable(pool));
	
	p1 = Alloc(pool, 7);  
	p2 = Alloc(pool, 20); 
	p3 = Alloc(pool, 10); 
	
	printf("Largest: %ld\n" ,LargestChunkAvailable(pool));
	p4 = Alloc(pool, 40); 
	while(24 > i) 
    {
        printf("runner:	%ld\n",*runner);
        runner += 1;
        ++i;
    }
	printf("Largest: %ld\n" ,LargestChunkAvailable(pool));
	p5 = Alloc(pool, 40); 

	i = 0;
	runner =(size_t*)pool;
	Free(p1);
	Free(p2);
	Free(p3);
	Free(p4);
	Free(p5);
	
	while(24 > i) 
    {
        printf("runner:	%ld \n",*runner);
        runner += 1;
        ++i;
    }
	free(mem);
}
void Test_Defrag()
{
	void *mem = NULL;
	vsa_t *pool = NULL;
	size_t pool_size = 85;
	void *p1 = NULL, *p2 = NULL, *p3 = NULL;
	size_t i = 0;
	size_t *runner =NULL;

	mem = malloc(pool_size);
	pool = Init(pool_size, mem);
	runner =(size_t*)pool;

	p1 = Alloc(pool, 7);  
	p2 = Alloc(pool, 8); 
	p3 = Alloc(pool, 8); 
	/*free(p3);*/
	while(10 > i) 
    {
        printf("runner:	%ld\n",*runner);
        runner += 1;
        ++i;
    }
}

