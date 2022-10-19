#include <assert.h>					/*		assert			*/
#include <stddef.h>					/*		size_t			*/
#include <stdlib.h>					/*		malloc			*/
#include <stdio.h>					/*		printf			*/
#include "fsa.h"					/*		fsa				*/


#define WORD 8
#define DUMMY 1

struct pool							/*copy struct to c file	*/
{
	size_t next_free;
};



/*******************approved by  				******************************/
/*****************************************************************************/
size_t SuggestSize(size_t block_size, size_t num_of_blocks)
{
	size_t fixed_size_block = 0;
	size_t suggest_size = 0;

	if(0 == (num_of_blocks * block_size) % WORD)
	{
		return (num_of_blocks * block_size) + WORD;
	}
	fixed_size_block = (((block_size) / WORD) + DUMMY) * WORD;
	suggest_size = fixed_size_block * num_of_blocks + WORD;

	return suggest_size;
}

fsa_t *Init(size_t pool_size, size_t block_size, void *mem)
{

	size_t num_of_blocks = 0;
	size_t i = 0;
	size_t *runner = (size_t*)mem;

	if(0 != block_size % WORD)
	{
		 block_size = ((block_size / WORD) + DUMMY) * WORD;
	}
	num_of_blocks = (pool_size - WORD)  / block_size;

	printf("num_of_blocks:	%ld\n", num_of_blocks);
	printf("block_size:	%ld\n", block_size);

	*runner = WORD; 	/*init first*/
	printf("block num: %ld " , i+1);
	printf("value: %ld  " , *runner);
	printf("address: %p\n" , runner);
	++runner;

	for(i = 1; i < num_of_blocks; ++i)
	{
		*runner = WORD + block_size * i;
		printf("block num: %ld " , i+1);
		printf("value: %ld  " , *runner);
		printf("address: %p\n" , runner);
		runner += block_size;
	}

	return (fsa_t*)mem;
}


void *Alloc(fsa_t *pool)
{
	size_t next = pool -> next_free;
	pool -> next_free = (size_t)((char*)pool + next);
	printf("\nV\n");
}

void Free(fsa_t *pool, void *mem)
{
	*(size_t *)mem = pool -> next_free;
	pool -> next_free = (char *)mem - (char *)pool;

}
/*
size_t CountFree(fsa_t *pool)
{
	
}
*/
