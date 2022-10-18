#include <assert.h>					/*		assert			*/
#include <stddef.h>					/*		size_t			*/
#include <stdlib.h>					/*		malloc			*/
#include "fsa.h"					/*		fsa				*/

#define TRUE 1
#define FALSE 0
#define BYTE 8
#define DUMMY 1

struct pool							/*copy struct to c file	*/
{
	size_t next_free;
};

/*******************approved by  				******************************/
/*****************************************************************************/
size_t SuggestSize(size_t block_size, size_t block_num)
{
	size_t size = 0;
	
	if(0 == (block_num * block_size) % BYTE)
	{
		return block_num * block_size;
	}
	size = (block_num * block_size) /BYTE;
	
	return (size + DUMMY) * BYTE;
}

fsa_t *Init(size_t pool_size, size_t block_size, void *mem)
{
	fsa_t total = malloc(sizeof(fsa_t) + 
}

/*
void *Alloc(fsa_t *pool)

void *Free(fsa_t *pool, void *mem)

size_t CountFree(fsa_t *pool)

*/
