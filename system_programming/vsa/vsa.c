#include <assert.h> /*	assert	*/
#include <stddef.h> /*	size_t	*/
#include <stdlib.h> /*	malloc	*/
#include <stdio.h>	/*	printf	*/
#include "vsa.h"	/*	fsa		*/

#define WORD 8
#define DUMMY 1
#define END (long)0xBADC0FFEE0DDF00D
#define BLOCK_SIZE runner->block_size

struct vsa
{
	long block_size;
};

static size_t AlignedSize(size_t size)
{
	if (0 != size % WORD)
	{
		size = ((size / WORD) + DUMMY) * WORD;
	}

	return size;
}

void * Defrag(vsa_t *pool)
{
	vsa_t *runner = pool;
	
	while (END != BLOCK_SIZE)
	{

	}
	return (vsa_t*)runner;
} 


vsa_t *Init(size_t pool_size, void *mem)
{
	vsa_t *runner = (vsa_t *)mem;
	/* plus two words , first for first , second to mark last*/
	pool_size = AlignedSize(pool_size) + 2 * WORD;
	printf("pool_size: %ld\n", pool_size);
	BLOCK_SIZE = pool_size - WORD; /* size pool left*/

	/*	printf("First address:	%p	", (void *)runner);
		printf("value: %ld \n", BLOCK_SIZE);*/

	*(size_t *)(char *)&runner += pool_size - WORD;
	BLOCK_SIZE = END;

	/*	printf("Last address:	%p	", (void *)runner);
		printf("value: %ld \n", BLOCK_SIZE);
	*/

	return (vsa_t *)mem;
}

/****************************************************************************
 * sent pool: 85 -> aligned to 96 + two words -> 112						*
 *																			*
 *		*************************************								*
 *		*96	  *							*END*								*
 *		*************************************								*
 *			*0x8*					  0x104-0x112							*
 *																			*
 *		aloc 8->16		96-16												*
 *		*************************************								*
 *		* -16  * DATA * 	 72	*		*END*								*
 *		*************************************								*
 *		*0x8*	   0x024    0x32		0x104								*
 *																			*
 *		aloc 24->32					72-32									*
 *		*************************************								*
 *		* -16  * DATA * -32 * DATA * 40	*END*								*
 *		*************************************								*
 *			*0x8*	0x024  0x32   0x64	0x104								*
 *																			*
 ****************************************************************************/

/********************************************************
 * pseudo												*
 * keep run until reach to end							*
 * 		if you see marked blocked						*
 * 			step by his absolute value					*
 * 		if you see size smaller than you				*
 *   		check the next one if free do defrag		*
 * 		if you see size bigger than you					*
 * 			mark the current block to minus you			*
 * 			set the next block to left mem (pool - you)	*
 ********************************************************/
void *Alloc(vsa_t *pool, size_t required_size)
{
	vsa_t *runner = pool;
	vsa_t *save_before_defrag = NULL;
	vsa_t *save_runner = NULL;
	long temp = 0;
	size_t sum = 0;

	required_size = AlignedSize(required_size) + WORD;
	printf("size_align: %ld \n", required_size);

	runner += WORD;
	/* run until reach to end  , if this block marked keep going */			
	while (END != BLOCK_SIZE)
	{
		/* case: if see markd block*/
		if (BLOCK_SIZE < 0)
		{
			BLOCK_SIZE = -BLOCK_SIZE;
			/*probelm here!!!!!!!!!!!*/
			runner += BLOCK_SIZE;
		}

		/* case: required_size bigger than current block*/
		if ((long)required_size > BLOCK_SIZE)
		{
			/*defrag*/
			save_before_defrag = runner;
			sum = BLOCK_SIZE;
			runner = runner + BLOCK_SIZE;
			if (BLOCK_SIZE > 0 && (long)END != BLOCK_SIZE)
			{
				sum += BLOCK_SIZE;
				save_before_defrag->block_size = sum;
				runner = save_before_defrag;
			}
		}
		/* case: block is available*/
		if ((long)required_size < BLOCK_SIZE)
		{
			temp = BLOCK_SIZE;
			BLOCK_SIZE = -required_size;
			save_runner = runner; /* save address to return*/
			runner += *(size_t *)(char *)required_size;
			BLOCK_SIZE = temp - required_size;
		}
		runner += BLOCK_SIZE;
	}

	return (vsa_t *)save_runner;
}

/********************************************************
 * pseudo												*
 * ?????????????????									*
 ********************************************************/

/*
void Free(void *pool)
{

}
*/


/********************************************************
 * pseudo												*
 * set max to 0											*
 * keep run until reach to end							*
 * 		if you see marked blocked						*
 * 			step by his absolute value					*
 * 		if current chunk is bigger than max				*
 * 			max set to current chunk					*
 * 			step to next chunk							*
 * return max											*
 ********************************************************/


size_t LargestChunkAvailable(vsa_t *pool)
{
	vsa_t *runner = pool;
	size_t max = 0;
	size_t i = 5;
	
	while (END != BLOCK_SIZE && --i)
	{

		if(BLOCK_SIZE > (long)max)
		{
			max = BLOCK_SIZE;
		}
		/*probelm here!!!!!!!!!!!*/
		runner += *(size_t *)(char *)BLOCK_SIZE;

		printf("step:	%ld\n",BLOCK_SIZE );
	}
	return max;
}

/*
if (BLOCK_SIZE < 0)
		{
			BLOCK_SIZE = -BLOCK_SIZE;
			runner += BLOCK_SIZE;
		}
*/
