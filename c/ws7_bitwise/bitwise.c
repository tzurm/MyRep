#include "bitwise.h"
#include <assert.h>



long Pow2 (unsigned int x, unsigned int y)
{
	return x<<y;
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


