#include <stdio.h>						/*	printf		*/
#include <stdlib.h>						/*	malloc		*/
#include <malloc.h>						/*	check heap	*/
	
static int static_func(int var);		/*	Static func */
extern int extern_func(int num);		/*	Extern func */
int *heap_variable = NULL;				/*	Heap var	*/
int *realloc_check = NULL;				/*	Heap var	*/
static const int var1 = 0;				/*	Static con	*/
const int var2 = 0;						/*	Const int	*/
int var3 = 0;							/*	Global var	*/
int var4;								/*	Global var	*/

extern int extern_func(int num)			/* func by default is extern */
{
	num=num;
}		
static int static_func(int num)
{
	return (num += 1);
}


size_t recursion(size_t num) 
{
	const int var = 0;							/*	const Local var */
	int var5 = 0;								/*	Local var 		*/
	int var6;	
	size_t i = 1;								/*	Local var 		*/
	char *string_literal = "Hello World";		/*	string literal	*/
	heap_variable = (int *)malloc(10*i);		/*	malloc 			*/
	++i;
	
	printf("%p | %d\n", &var , var);
	printf("%p | %d\n", &var5 , var5);
	printf("%p | %d\n", &var6 , var6);
	++var3;
	++var4;
	
	printf("num: %d \n" , num);
    return (1 != num)? recursion(num-1) : 1;
}


int main(int argc, char *argv[], char *envp[])
{

    size_t run_num_times = 1000;
	heap_variable = (int *)malloc(10);			/*	malloc 			*/
	
  	recursion(run_num_times);
 	free(heap_variable);
    return 0;
}
