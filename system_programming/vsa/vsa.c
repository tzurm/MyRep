#include <assert.h> 	/*	assert	*/
#include <stddef.h> 	/*	size_t	*/
#include <stdlib.h>	 	/*	malloc	*/
#include <stdio.h>		/*	printf	*/
#include <sys/types.h>	/*	ssize_t	*/
#include <unistd.h>		/*	ssize_t	*/

#include "vsa.h"		/*	fsa		*/

#define WORD 8
#define DUMMY 1

struct vsa
{
	ssize_t block_size;
};

static size_t AlignedPool(size_t pool_size)
{
	if(0 != pool_size % WORD)
	{
		pool_size = ((pool_size / WORD) + DUMMY) * WORD;
	}
	return pool_size;
}

vsa_t *Init(size_t pool_size, void *mem)
{
	size_t *runner = (size_t *)mem;
	pool_size =AlignedPool(pool_size) + WORD;

	*runner = WORD; 
	printf("pool_size_align: %ld \n",pool_size);
}
/*
void *Alloc(vsa_t *pool, size_t required_size)
{

}

void Free(void *pool)
{

}
size_t LargestChunkAvailable(vsa_t *pool)
{

}
*/
