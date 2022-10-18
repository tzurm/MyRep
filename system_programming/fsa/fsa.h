#include <stddef.h>					/*		size_t			*/
#ifndef __ILRD_CR02_FSA_H__
#define __ILRD_CR02_FSA_H__

									


typedef struct pool fsa_t;

/****************************************************************************
 *	user ask size of block at heap, return fixed size						*
 *	paramters:																*
 *		block_size - size of each block										*
 *		block_num - the number of blocks									*
 *																			*					
 ****************************************************************************/
size_t SuggestSize(size_t block_size, size_t block_num);


/****************************************************************************
 *	init the block to point to next free address							*
 *	paramters:																*
 *		pool_size - total size of the pool									*
 *		block_size - size of each block										*
 *		mem - address point to start of the pool							*
 ****************************************************************************/
fsa_t *Init(size_t pool_size, size_t block_size, void *mem);

void *Alloc(fsa_t *pool);

void *Free(fsa_t *pool, void *mem);

size_t CountFree(fsa_t *pool);


#endif


