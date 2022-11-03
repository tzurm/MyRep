#include <dlfcn.h>
#include <stdio.h>

int main()
{
	void *lib_handle = NULL;
	void (*foo_func)(int) = NULL;
	
	lib_handle = dlopen("./libfoo.so", RTLD_LAZY);
	*(void **)&foo_func = dlsym(lib_handle, "PrintNum");
	
	foo_func(5);
	
	dlclose(lib_handle);
	
	return 0;
}

/*
 gcc -c foo.c
 gcc -shared -o libfoo.so foo.o
 gd main.c -ldl -o tt
 
*/
