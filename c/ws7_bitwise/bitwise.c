#include "bitwise.h"
#include <assert.h>


/* ex1 */
long Pow2 (unsigned int x, unsigned int y)
{
	return x<<y;
}

/* Ex2 */

int  Ex2Loop  (unsigned int num)
{
    unsigned int i = 0;
    for(i = 1 ; i < num ; ++i )
    {
        if (num == (unsigned)(1 << i))
        {
         
            return 1;
        }   
    }
    return 0;
}

int  Ex2V2  (unsigned int num)
{
	/*power of two always should be 1 and zero after that 10=2 , 100=4 1000=8..
	 0 == (100 and 011 = 000  )*/
  if(0 == (num & (num-1)))
  {
     return 1;
  } 
  return 0;
 
}


/* ex4 */
/* input: num , output: count bits on (1)
explain:  
count += num &1 - check and count if the last bit is 1
num>>=1 - change the num like 0110 >> 1  -> 1100  */
unsigned int CountBit( unsigned int num)
{
    unsigned int count = 0;
    while ( 0 != num )
    {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

/* input: arr of num , output: print the num with only 3 bits on */
void Bit3( unsigned int *arr , size_t len)
{
	size_t i = 0;
	unsigned int temp = 0;
    unsigned int count = 0;
    printf("the number with only 3 bit on:\n");
    while ( i < len )
    {
    	temp = arr[i];
		count = CountBit(arr[i]);
		++i;
		
		if(3 == count)
		{
			printf(" %d |" , temp);
    	}
    }
    printf("\n");
}


/* Ex7 */
int Div16 (unsigned int num)
{
    while ( num != (num >> 4) << 4 )
  {
    -- num;
  }  
  return num;
}


/* Ex8  swap with bitwise*/
void SwapXor (int *num1 , int *num2)
{
    
   *num1 = *num1 ^ *num2;
   *num2 = *num1 ^ *num2;
   *num1 = *num1 ^ *num2;
 
}


