#include "arrays_pointers.h"
#include <assert.h>


void PrintDataTypes ()
{
    size_t a = sizeof(int);
    size_t b = sizeof (unsigned int);
    size_t c = sizeof(float);
    size_t d = sizeof(char);
    size_t e = sizeof(signed char);
    size_t f = sizeof(unsigned char);
    size_t g = sizeof (double);
    size_t h = sizeof (short);
    size_t i = sizeof (unsigned short);
    size_t j = sizeof (long);
    size_t k = sizeof (unsigned long);

    printf("\nsize of int: %lu" , a);
    printf("\nsize of unsigned int: %lu" , b);
    printf("\nsize of float: %lu" , c);
    printf("\nsize of char: %lu" , d);
    printf("\nsize of signed char: %lu" , e);
    printf("\nsize of unsigned char: %lu" , f);
    printf("\nsize of double: %lu" , g);
    printf("\nsize of short: %lu" , h);
    printf("\nsize of unsigned short: %lu" , i);
    printf("\nsize of long: %lu" , j);
    printf("\nsize of unsigned long: %lu" , k);
}

int Yosef(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return ((Yosef(n - 1) + 1) % n) + 1;
    }
}

void Print2d (int arr[2][4], int i, int j)
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

void SumRows(int arr[2][4], int i, int j)
{
    int sump[2];
    int rows, columns;
    for(rows = 0; rows < i; rows++)
    {
        int sum = 0;
        for(columns = 0; columns < j; columns++)
        {
            sum = sum + arr[rows][columns];
        }
        sump[rows]=sum;
        printf("Sum of a rows num %d  =  %d \n",rows+1, sum );
        
    }
}
