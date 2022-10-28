#include <assert.h> /*	assert	*/
#include <stddef.h> /*	size_t	*/
#include <stdlib.h> /*	malloc	*/
#include "vsa.h"	/*	fsa		*/

#define WORD sizeof(vsa_t)
#define DUMMY 1
#define END (long)0xBADC0FFEE0DDF00D
#define MARK_DEBUG (long)0xDEADBABEBAAAAAAD
#define BLOCK_SIZE(ptr) ((ptr->block_size))
#define ROUND_UP(size) ((size + WORD - 1) & ~(WORD - 1))
#define ROUND_DOWN(size) ((size) & (-WORD))
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
	return ROUND_UP(size);
}

/****************************		DEFRAG		*****************************
 *																			*
 *			p1			p2													*
 *		+---+------+----+------+---+------------+-----+						*
 *		| 8 | DATA | 24 | DATA |-16|			| END |						*
 *		+---+------+----+------+---+------------+-----+						*
 *		0  0x8	 0x16  0x24  0x48  0x56			0x72						*
 *																			*
 * 		free(p1) , free(p2)													*
 *																			*
 *		+----+-----------------+---+------------+-----+						*
 *		| 40 | 				   |-16|			| END |						*
 *		+----+-----------------+---+------------+-----+						*
 *		0	0x8				 0x48  0x56			0x72						*
 *																			*
 ****************************************************************************/
static void *Defrag(void *mem)
{
	vsa_t *save_before_defrag = NULL;
	vsa_t *runner = NULL;
	size_t sum = 0;

	assert(NULL != mem);

	runner = (vsa_t *)mem;

	if (BLOCK_SIZE(runner) > -1)
	{
		save_before_defrag = runner;
		sum = BLOCK_SIZE(runner);
		runner = (vsa_t *)((char *)runner + sizeof(vsa_t) + BLOCK_SIZE(runner));
		if (BLOCK_SIZE(runner) > -1 && BLOCK_SIZE(runner) != (long)END)
		{
			sum += BLOCK_SIZE(runner) + sizeof(vsa_t);
			BLOCK_SIZE(save_before_defrag) = sum;
		}
	}
	return save_before_defrag;
}
/*-----------------------------Init-----------------------------------------*
 *		pool 201 -> 200 -8 -8 ->184											*														*
 *																			*
 *		+-----+---------------------------------+-----+						*
 *		| 184 |	  								| END |						*
 *		+-----+---------------------------------+-----+						*
 *		0	 0x8							  0x192   0x200					*
 *																			*
 *--------------------------------------------------------------------------*/
vsa_t *Init(size_t pool_size, void *mem)
{
	vsa_t *runner = NULL;

	assert(NULL != mem);

	runner = (vsa_t *)mem;
	pool_size = ROUND_DOWN(pool_size) - 2 * WORD;

	BLOCK_SIZE(runner) = pool_size;	  /*set the first block to pool size*/
	runner += (pool_size / WORD) + 1; /*jump to end and set the magin num */
	BLOCK_SIZE(runner) = END;

	return (vsa_t *)mem;
}

/****************************************************************************
 * sent pool: 85 -> aligned to 80 - two words -> 64							*
 *																			*
 *		+----+----------------------------------+-----+						*
 *		| 64 |									| END *		  				*
 *		+----+----------------------------------+-----+						*
 *		0  0x8								  x72							*
 *																			*														*
 *		 __aloc 8__															*
 * 		/		   \ 64-8-8		 											*
 *		+----+------+----+----------------------+-----+						*
 *		| -8 | DATA | 48 |					    | END *						*
 *		+----+------+----+----------------------+-----+						*
 *		0	0x8	  0x16  0x24 				   0x72							*
 *																			*
 * 					  _aloc 24__											*
 *					 /		    \ 48-24-8									*
 *		+----+------+-----+------+----+---------+-----+						*
 *		| -8 | DATA | -24 | DATA | 16 |		    | END *						*
 *		+----+------+-----+------+----+---------+-----+						*
 *		0	0x8	  0x16  0x24  0x48 0x56		   0x72							*
 *																			*
 ****************************************************************************/

/****************************************************************************
 * pseudo																	*
 * run until reach to end or unmarked block	by step by his absolute value	*					*
 * if you reached to end return NULL										*
 * if current block is too small perform defrag it possible					*
 * mark the new block (by minus value)										*				*
 * set the next block to left mem (before - new block - size of word)		*
 * 																			*
 ****************************************************************************/
void *Alloc(vsa_t *pool, size_t required_size)
{
	vsa_t *runner = NULL;
	vsa_t *save_runner = NULL;
	long temp = 0;
	long skip = 0;

	assert(NULL != pool);

	runner = pool;
	required_size = AlignedSize(required_size);

	/* run until reach to end or unmarked block */
	while (END != BLOCK_SIZE(runner) && BLOCK_SIZE(runner) < 0)
	{
		skip = -BLOCK_SIZE(runner);
		runner = (vsa_t *)((char *)runner + sizeof(vsa_t) + skip);
	}
	/* if reached to end return NULL*/
	if (END == BLOCK_SIZE(runner))
	{
		return NULL;
	}
	/* if current block is too small perform defrag when possible*/
	if ((long)required_size > BLOCK_SIZE(runner))
	{
		Defrag(runner);
	}

	temp = BLOCK_SIZE(runner);
	BLOCK_SIZE(runner) = -required_size;
	save_runner = (vsa_t *)((char *)runner);
	runner = (vsa_t *)((char *)runner + required_size + sizeof(vsa_t));
	BLOCK_SIZE(runner) = temp - required_size - sizeof(vsa_t);
	/*
		#ifndef NDEBUD
			save_runner->debug_num = MARK_DEBUG;
		#endif
	*/

	save_runner = (vsa_t *)((char *)save_runner + sizeof(vsa_t));

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
	/*
		#ifndef NDEBUD
			assert(MARK_DEBUG == (runner -> debug_num));
			runner -> debug_num = 0;
		#endif
	*/
	runner = (vsa_t *)mem;
	runner = (vsa_t *)((char *)runner - sizeof(vsa_t));
	BLOCK_SIZE(runner) = -1 * (BLOCK_SIZE(runner));
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
	while (END != BLOCK_SIZE(runner))
	{
		if (BLOCK_SIZE(runner) < 0)
		{
			skip = -BLOCK_SIZE(runner);
			runner = (vsa_t *)((char *)runner + sizeof(vsa_t) + skip);
		}
		if (BLOCK_SIZE(runner) < (long)max)
		{
			Defrag(runner);
		}
		if (BLOCK_SIZE(runner) > (long)max)
		{
			max = BLOCK_SIZE(runner);
			runner = (vsa_t *)((char *)runner + BLOCK_SIZE(runner));
		}
	}

	return max;
}
