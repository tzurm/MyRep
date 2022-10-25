#include <stddef.h>					/*		size_t			*/
#ifndef __ILRD_CR02_FSA_H__
#define __ILRD_CR02_FSA_H__

									


typedef struct vsa vsa_t;


/****************************************************************************
 *	init the all pool                              							*
 *	paramters:																*
 *		pool_size - total size of the pool									*
 *		mem - address point to start of the pool							*
 ****************************************************************************/
vsa_t *Init(size_t pool_size, void *mem);

/****************************************************************************
 *	aloc the block 							                                *
 *	paramters:																*
 *		pool - 									*
 *		required_size - 						*
 ****************************************************************************/
void *Alloc(vsa_t *pool, size_t required_size);

void Free(void *mem);

size_t LargestChunkAvailable(vsa_t *pool);


#endif


