#include <stddef.h>					/*		size_t			*/
#ifndef __ILRD_CR02_FSA_H__
#define __ILRD_CR02_FSA_H__

									


typedef struct pool fsa_t;

/****************************************************************************
 *																			*					
 ****************************************************************************/
size_t SuggestSize(size_t block_size, size_t block_num);

fsa_t *Init(size_t pool_size, size_t block_size, void *mem);

void *Alloc(fsa_t *pool);

void *Free(fsa_t *pool, void *mem);

size_t CountFree(fsa_t *pool);


#endif


