#include "arrays_pointers.h"
#include <assert.h>

/* date: 30.8
writer: Tzur
review: Arye
Status: approved
*/
void PrintDataTypes()
{
   
    printf("\nsize of int: %lu" , sizeof(int));
    printf("\nsize of unsigned int: %lu" , sizeof (unsigned int));
    printf("\nsize of float: %lu" , sizeof(float));
    printf("\nsize of char: %lu" , sizeof(char));
    printf("\nsize of signed char: %lu" , sizeof(signed char));
    printf("\nsize of unsigned char: %lu" , sizeof(unsigned char));
    printf("\nsize of double: %lu" , sizeof (double));
    printf("\nsize of short: %lu" , sizeof (short));
    printf("\nsize of unsigned short: %lu" , sizeof (unsigned short));
    printf("\nsize of long: %lu" , sizeof (long));
    printf("\nsize of unsigned long: %lu" ,  sizeof (unsigned long));
}

size_t Yosefr(size_t n)
{
    if (n == 1)
    {
        return 1;
    }
    else
	{
    	return ((Yosefr(n - 1) + 1) % n) + 1;
	}
}

/* date: 5.9
writer: Tzur
review: Mark
Status: approved
*/

size_t Yosef(size_t n , size_t *p)
{ 
    size_t i = 0;
    size_t j = 0;
   
   assert(n > 0);
    
    /* enter the index to value */
    for(i = 0; i < n - 1; ++i)
    {
        p[i] = i + 1;
    }
    
    p[n] = 0;
    
    i = 0;
    
    while(p[i] != i)
    {
        j = p[i];
        p[i] = p[j];
        i = p[j];
    }
    
    return i+1;
}


void Print2d(int arr[2][4] , int i, int j)
{
	printf("\nTwo Dimensional array elements:\n");
	for(i=0; i<2; i++) 
	{
		for(j=0;j<4;j++) 
		{
			printf("%d ", arr[i][j]);
			if(j==3)
         	{
            	printf("\n");
         	}
     	}
	}	
}

/* date: 5.9
writer: Tzur
review: Mark
Status: approved
*/

void SumRows(int arr[2][4] , size_t *sumarr , int i, int j)
{
  	
    int rows=0, columns=0;
    assert (sumarr == NULL);
    for(rows = 0; rows < i; ++rows)
    {
        
        for(columns = 0; columns < j; ++columns)
        {
            sumarr[rows] += arr[rows][columns];
        }
     }
 }
 
 /* date: 5.9
writer: Tzur
review: Andery
Status: approved
*/

char *ToLow(char *src)
{
    char *des=src;
    while('\0' != *des) 
    {
        *des=tolower(*des);
        ++des;
    
    }
    return src;
}

void PrintEnv()
{
	extern char **environ;
	char **buffer = environ;
	
	
	while ('\0' != *buffer)
	{
		printf("%s\n" ,ToLow(*buffer));
		++buffer;
	}
	printf("end of file\n");
	
}

  

