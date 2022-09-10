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
  if(0 == (num & (num-1)))
  {
     return 1;
  } 
  return 0;
 
}


int Div16 (unsigned int num)
{
    while ( num != (num >> 4) << 4 )
  {
    -- num;
  }  
  return num;
}



void SwapXor (int *num1 , int *num2)
{
    
   *num1 = *num1 ^ *num2;
   *num2 = *num1 ^ *num2;
   *num1 = *num1 ^ *num2;
 
}


