#include <stdio.h>
#include <stddef.h>
#include <stdlib.h> /*		malloc		*/
#include "vsa.h"	/*		fsa			*/

void Test_Init();

int main()
{

	printf("*************************\n*   Test Init		* \n*************************\n");

	Test_Init();

	return 0;
}

void Test_Init()
{

	void *mem = NULL;
	vsa_t *pool = NULL;
	size_t pool_size = 85;
	void *p1 = NULL;
	void *p2 = NULL;
	void *p3 = NULL;

	mem = malloc(pool_size);
	pool = Init(pool_size, mem);
	
	
	p1 = Alloc(pool, 7);  /* 7 > 8 > 16 */
	p2 = Alloc(pool, 20); /* 20 > 24 > 32 */
	p3 = Alloc(pool, 35); /* 35 > 40 > 48 */

	

	(void)p1;
	(void)p2;
	(void)p3;
/*
	Free(p1);
	Free(p2);
	Free(p3);
*/
	free(mem);
}
