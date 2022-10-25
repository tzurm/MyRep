#include <assert.h> /*	assert	*/
#include <stddef.h> /*	size_t	*/
#include <stdlib.h> /*	malloc	*/
#include <stdio.h>	/*	printf	*/
#include "vsa.h"	/*	fsa		*/

#define WORD 8
#define DUMMY 1
#define END (long)0xBADC0FFEE0DDF00D
#define MARK_DEBUG 0xDEADBABEBAAAAAAD
#define BLOCK_SIZE runner->block_size

struct vsa
{
	long block_size;
	/*
	#ifndef NDEBUD
		size_t debug_num;
	#endif
	*/
};

static size_t AlignedSize(size_t size)
{
	if (0 != size % WORD)
	{
		size = ((size / WORD) + DUMMY) * WORD;
	}

	return size;
}

/****************************		DEFRAG		*****************************
 *				  p1	p2			p3										*
 *			*************************************************				*
 *			* 8  * DATA * 24 * DATA * -16 *			*END*					*
 *			*************************************************				*
 * Free(p1)		0x8	  0x16  0x24   0x48	 0x56 			0x72				*
 * Free(p2)																	*
 *			*************************************************				*
 *			* 40  * 				* -16 *				*END*				*
 *			*************************************************				*
 *				0x8	  			   0x48	 0x56 			0x72				*
 *																			*
 ****************************************************************************/
static void Defrag(void *mem)
{
	vsa_t *save_before_defrag = NULL;
	vsa_t *runner = NULL;
	size_t sum = 0;

	assert(NULL != mem);

	runner = (vsa_t *)mem;

	if (BLOCK_SIZE > -1)
	{
		save_before_defrag = runner;
		sum = BLOCK_SIZE;
		runner = (vsa_t *)((char *)runner + sizeof(vsa_t) + BLOCK_SIZE);
		if (BLOCK_SIZE > -1 && BLOCK_SIZE != (long)END)
		{
			sum += BLOCK_SIZE + sizeof(vsa_t);
			save_before_defrag->block_size = sum;
		}
	}
}

vsa_t *Init(size_t pool_size, void *mem)
{
	vsa_t *runner = (vsa_t *)mem;
	/* minus three words , first for first , second to mark last ,
	last for round down*/
	pool_size = AlignedSize(pool_size) - 3 * WORD;
	printf("pool_size: %ld\n", pool_size);
	BLOCK_SIZE = pool_size; /* size pool left*/
	runner += pool_size / WORD;
	BLOCK_SIZE = END;

	return (vsa_t *)mem;
}

/****************************************************************************
 * sent pool: 85 -> aligned to 80 - two words -> 64							*
 *																			*
 *		*************************************************					*
 *		* 64  *										*END*					*
 *		*************************************************					*
 *			*0x8*								  0x72-0x80					*
 *																			*
 *		aloc 8			64-8-8												*
 *		*************************************************					*
 *		* -8  *	 DATA  * 48 *						*END*					*
 *		*************************************************					*
 *			*0x8*	 0x16  0x24					  0x72-0x80					*
 *																			*
 *		aloc 20->24					48-24-8									*
 *		*************************************************					*
 *		* -8  *	 DATA  *-24 * DATA * 16 *			*END*					*
 *		*************************************************					*
 *			*0x8*	 0x16  0x24	 0x48  0x56		  0x72-0x80					*
 *																			*
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
	vsa_t *runner = NULL;
	vsa_t *save_runner = NULL;
	long temp = 0;
	long skip = 0;
	
	assert(NULL != pool);
	
	runner = pool;
	required_size = AlignedSize(required_size);

	/* run until reach to end , if this block marked keep going */
	while (END != BLOCK_SIZE && BLOCK_SIZE < 0)
	{
		skip = -BLOCK_SIZE;
		runner = (vsa_t *)((char *)runner + sizeof(vsa_t) + skip);
	}
	/* if get to end return NULL*/
	if (END == BLOCK_SIZE)
	{
		return NULL;
	}
	/* when you have space*/
	if ((long)required_size > BLOCK_SIZE)
	{
		printf("defrag\n");
		Defrag(runner);
	}
	else
	{
		temp = BLOCK_SIZE;
		BLOCK_SIZE = -required_size;
		save_runner = (vsa_t *)((char *)runner);
		runner = (vsa_t *)((char *)runner + required_size + sizeof(vsa_t));
		BLOCK_SIZE = temp - required_size - sizeof(vsa_t);
	}
	
	save_runner = (vsa_t *)((char *)save_runner + sizeof(vsa_t));
	/*
		#ifndef NDEBUD
			base->debug_num = MARK_DEBUG;
		#endif
	*/
	return (vsa_t *)save_runner;
}

/********************************************************
 * pseudo												*
 * unmark the address (multiply by -1)					*
 ********************************************************/
void Free(void *mem)
{
	vsa_t *runner = NULL;
	assert(NULL != mem);
	/*	#ifndef NDEBUD
			assert(MARK_DEBUG == (runner -> debug_num));
			runner -> debug_num = 0;
		#endif
	*/
	runner = (vsa_t *)mem;
	runner = (vsa_t *)((char *)runner - sizeof(vsa_t));
	BLOCK_SIZE = -1 * (BLOCK_SIZE);
	printf("clean	%ld bytes\n", BLOCK_SIZE);
}

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
	vsa_t *runner = NULL;
	size_t max = 0;
	long skip = 0;

	assert(NULL != pool);

	runner = pool;
	while (END != BLOCK_SIZE)
	{
		if (BLOCK_SIZE < 0)
		{
			skip = -BLOCK_SIZE;
			runner = (vsa_t *)((char *)runner + sizeof(vsa_t) + skip);
		}
		if (BLOCK_SIZE < (long)max)
		{
			Defrag(runner);
		}
		if (BLOCK_SIZE > (long)max)
		{
			max = BLOCK_SIZE;
			runner = (vsa_t *)((char *)runner + BLOCK_SIZE);
		}
	}

	return max;
}
