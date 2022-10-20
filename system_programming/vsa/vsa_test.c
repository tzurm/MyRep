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
	size_t pool_size = 128;
	
	mem = malloc(pool_size);
	pool = Init(pool_size, mem);
	
}