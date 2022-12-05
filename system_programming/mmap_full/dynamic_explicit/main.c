#include <dlfcn.h>
#include <stdio.h>
#include <stddef.h>

#include "mm.h"


int main()
{

	void *lib_handle = NULL;
	void (*foo_func)(size_t) = NULL;			/*pointer to func */
	
	int *heap_variable = NULL;				/*	Heap var	*/
    size_t run_num_times = 500;
    
	heap_variable = (int *)malloc(10);			/*	malloc 			*/
	
	lib_handle = dlopen("./libmm.so", RTLD_LAZY);
	*(void **)&foo_func = dlsym(lib_handle, "recursion");
	
  	foo_func(run_num_times);
  	
  	dlclose(lib_handle);
 	free(heap_variable);
    return 0;
}

