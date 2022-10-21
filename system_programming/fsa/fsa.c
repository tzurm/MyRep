#include <assert.h> 	/*	assert	*/
#include <stddef.h> 	/*	size_t	*/
#include <stdlib.h>	 	/*	malloc	*/
#include <stdio.h>		/*	printf	*/
#include "fsa.h"		/*	fsa		*/

#define WORD 8
#define DUMMY 1

struct pool
{
	size_t next_free;
};


/*******************approved by alex 19.10.22	****************************/
/****************************************************************************
 * pseudo																	*
 *  fixed the block size if needed to be alignd								*
 *  return block * size + 8 byte to point to first							*
 ****************************************************************************/
size_t SuggestSize(size_t block_size, size_t num_of_blocks)
{
	size_t fixed_size_block = 0;
	size_t suggest_size = 0;

	if (0 == (num_of_blocks * block_size) % WORD)
	{
		return (num_of_blocks * block_size) + WORD;
	}
	fixed_size_block = (((block_size) / WORD) + DUMMY) * WORD;
	suggest_size = fixed_size_block * num_of_blocks + WORD;

	return suggest_size;
}
/*******************approved by roman 19.10.22	*****************************/
/****************************************************************************
 * pseudo																	*
 *  init the value of the nodes to be offset from the start of the pointer	*
 *  init the first next to be 8												*
 *  set the rest by moving the pointer plus	block size every time			*
 * 	and the value by sum the multiply block size by i that count			*
 * 	set the last to be 0													*
 ****************************************************************************
 * 			block 21 | fixed block 24 | num_of_blocks 3 | pool 80			*
 *  																		*		
 *	*********		*********		*********		*********		 		*
 *	*	8	*	->	*	32	*	->	*	56	*	->	*	0	*				*
 *	*********		*********		*********		*********				*	
 *	0x100			0x108			0x132			0x156				  	*	
 *																			*
 ****************************************************************************/
fsa_t *Init(size_t pool_size, size_t block_size, void *mem)
{
	size_t num_of_blocks = 0;
	size_t i = 0;
	size_t *runner = (size_t *)mem;

	if (0 != block_size % WORD)
	{
		block_size = ((block_size / WORD) + DUMMY) * WORD;
	}
	num_of_blocks = (pool_size - WORD) / block_size;

	*runner = WORD; /*init first*/
	++runner;
	printf("block num: %ld " , i);
		printf("value: %ld  \n" , *runner);

	for (i = 1; i < num_of_blocks; ++i)
	{
		*runner += WORD + block_size * i;
		printf("block num: %ld " , i);
		printf("value: %ld  \n" , *runner);
		runner += block_size / WORD;
	}
	*runner = 0;
	printf("block num: %ld " , i);
		printf("value: %ld  \n" , *runner);
	return (fsa_t *)mem;
}

/*******************approved by Arie 19.10.22	*****************************/
/****************************************************************************
 * 	before		block 21 | fixed block 24 | num_of_blocks 3 | pool 80		*
 *  																		*		
 *	*********		*********		*********		*********		 		*
 *	*	8	*	->	*	32	*	->	*	56	*	->	*	0	*				*
 *	*********		*********		*********		*********				*	
 *	0x100			0x108			0x132			0x156				  	*	
 ****************************************************************************
 * after		block 21 | fixed block 24 | num_of_blocks 3 | pool 80		*
 *  																		*		
 *	*********		*********		*********		*********		 		*
 *	*	32	*	->	* data	*	->	*	56	*	->	*	0	*				*
 *	*********		*********		*********		*********				*	
 *	0x100			0x108			0x132			0x156				  	*	
 *																			*
 ****************************************************************************/
void *Alloc(fsa_t *pool)
{
	size_t next = 0;

	assert(NULL != pool);
	next = pool->next_free;

	pool->next_free = *(size_t *)((char *)pool + next);
	return (void *)((char *)pool + next);
}
/*******************approved by Arie 19.10.22	******************************/
/****************************************************************************
 * before		block 21 | fixed block 24 | num_of_blocks 3 | pool 80		*
 *  																		*		
 *	*********		*********		*********		*********		 		*
 *	*	32	*	->	* data	*	->	*	56	*	->	*	0	*				*
 *	*********		*********		*********		*********				*	
 *	0x100			0x108			0x132			0x156				  	*	
 ****************************************************************************
 * after		block 21 | fixed block 24 | num_of_blocks 3 | pool 80		*
 *  																		*		
 *	*********		*********		*********		*********		 		*
 *	*	32	*	->	*  data	*	->	*	56	*	->	*	0	*				*
 *	*********		*********		*********		*********				*	
 *	0x100			0x108			0x132			0x156				  	*	
 *
 * mem = 108
 * pool next 0x108 = 108 - 100 = 8																		*																		*
 ****************************************************************************/

void Free(fsa_t *pool, void *mem)
{
	assert(NULL != pool);
	assert(NULL != mem);

	*(size_t *)mem = pool->next_free;
	pool->next_free = (char *)mem - (char *)pool;
}

/*******************approved by Arie 19.10.22	******************************/
/*****************************************************************************/
size_t CountFree(fsa_t *pool)
{
	size_t count = 0;
	size_t next = 0;

	assert(NULL != pool);

	next = pool->next_free;
	while (0 != next)
	{
		next = *(size_t *)((char *)pool + next);
		++count;
	}

	return count;
}