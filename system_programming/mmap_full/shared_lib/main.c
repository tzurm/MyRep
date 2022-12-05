#include <stdio.h>						/*	printf		*/
#include <stdlib.h>						/*	malloc		*/
#include <malloc.h>						/*	check heap	*/
#include "mm.h"


int main(int argc, char *argv[], char *envp[])
{

	int *heap_variable = NULL;				/*	Heap var	*/
    size_t run_num_times = 500;
    
	heap_variable = (int *)malloc(10);			/*	malloc 			*/
	
  	recursion(run_num_times);
 	free(heap_variable);
    return 0;
}

