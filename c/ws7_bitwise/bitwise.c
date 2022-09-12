#include "bitwise.h"
#include <assert.h>


/* Ex1 */
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

 /* date: 12.9
writer: Tzur
review: Slava
Status: approved
*/

/* Ex3 */
int AddOne( int num)
{
	/*pseudo code
	search for first 0 bit
		-change 1 bit to 0
	when done , flip the 0 bit to 1 
	*/
	
	int mask = 1;
	while (0 != (num & mask))
	{
		num &= ~mask;
		mask <<= 1;
	}
	num |= mask;
	
	return num;
}



/* Ex4  +Ex9*/
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

/* Ex5 ByteMirror 
						explain for swap 8 bits
	b7 b6 b5 b4  b3 b2 b1 b0
	1  0  1  0	 1  1  0  0   			1  0  1  0 	 1  1  0  0
& 	1  1  1  1   0  0  0  0			 &	0  0  0  0	 1  1  1  1
>>4	1  0  1  0   0  0  0  0			<<4	0  0  0  0   1  1  0  0
	0  0  0  0   1  0  1  0			 	1  1  0  0   0  0  0  0

						0  0  0  0   1  0  1  0
					|	1  1  0  0   0  0  0  0
						1  1  0  0   1  0  1  0					*/

unsigned char ByteMirror(unsigned char byte) 
{			/*11110000 */
   byte = (byte & 0xF0) >> 4 | (byte & 0x0F) << 4;

   byte = (byte & 0xCC) >> 2 | (byte & 0x33) << 2;
   byte = (byte & 0xAA) >> 1 | (byte & 0x55) << 1;
   return byte;
}


/* Ex6 */

unsigned char Bit2and6( unsigned char num)
{
	/*   	 00000010 		 00100000 */
	return ((num & 0x2) && (num & 0x20));

}

unsigned char Bit2or6( unsigned char num)
{
	/*   	 00000010 		 00100000 */
	return ((num & 0x2) || (num & 0x20));

}


/* Ex7
explain:
num != (num >> 4) << 4
32 !=	(32/16 *16)=32
check if the num is dived by 16	 if not --num, and start over */

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
/* Ex9  without loop , need to understand */
int CountCheckBit (unsigned int i)
{

	 i = i - ((i >> 1) & 0x55555555);       
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333); 
     i = (i + (i >> 4)) & 0x0F0F0F0F;      
     return (i * 0x01010101) >> 24; 
}




