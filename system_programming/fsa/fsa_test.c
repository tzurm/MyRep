#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>					/*		malloc		*/
#include "fsa.h"					/*		fsa			*/


void Test_SuggestSize();
void Test_Init();


int main() 
{
   
	printf("*************************\n*   Test SuggestSize	* \n*************************\n");
	Test_SuggestSize();
	printf("*************************\n*   Test Init		* \n*************************\n");
	Test_Init();
	
	return 0;
}


void Test_SuggestSize()
{

	printf("Send:	11*3	SuggestSize:	%ld\n", SuggestSize(11,3));
	printf("Send:	7*12	SuggestSize:	%ld\n", SuggestSize(7,12));
	printf("Send:	8*1	SuggestSize:	%ld\n", SuggestSize(8,1));
	printf("Send:	21*5	SuggestSize:	%ld\n", SuggestSize(21,5));

}

void Test_Init()
{
	void * mem = NULL;
	fsa_t *pool = NULL;
	size_t block_size = 21;
	size_t num_of_blocks = 5;

	void * mem2 = NULL;
	fsa_t *pool2 = NULL;
	size_t block_size2 = 9;
	size_t num_of_blocks2 = 4;
	printf("\nTEST 1\n");
	mem = malloc(SuggestSize(block_size, num_of_blocks));
	pool = Init((SuggestSize(block_size, num_of_blocks)), block_size, mem);
	
	printf("\nTEST 2\n");
	mem2 = malloc(SuggestSize(block_size2, num_of_blocks2));
	pool2 = Init((SuggestSize(block_size2, num_of_blocks2)), block_size2, mem2);
	

	printf("STATUS:	%ld / %ld\n" ,CountFree(pool), num_of_blocks);
	printf("STATUS:	%ld / %ld\n" ,CountFree(pool2), num_of_blocks2);
	/*
	mem = Alloc(pool);
	mem = Alloc(pool);

	mem2 = Alloc(pool2);

	printf("STATUS:	%ld / %ld\n" ,CountFree(pool), num_of_blocks);
	printf("STATUS:	%ld / %ld\n" ,CountFree(pool2), num_of_blocks2);
	
	free(pool);
	free(pool2);
	*/
}
