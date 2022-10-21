#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>					/*		malloc		*/
#include "vsa.h"					/*		fsa			*/


void Test_Init();


int main() 
{
   
	
	printf("*************************\n*   Test Init		* \n*************************\n");
	
	Test_Init();
	
	return 0;
}


void Test_Init()
{
	
	void * mem = NULL;
	vsa_t *pool = NULL;
	size_t pool_size = 85;
	void *p1 = NULL;

	mem = malloc(pool_size);
	pool = Init(pool_size, mem);
	printf("max_chunk:	%ld\n",  LargestChunkAvailable(pool));
/*
	p1 = Alloc(pool,7);
	p1 = Alloc(pool,20);
	p1 = Alloc(pool,35);
*/
	(void)p1;


}