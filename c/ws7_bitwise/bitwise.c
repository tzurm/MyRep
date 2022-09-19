#include "bitwise.h"
#include <assert.h>

 /* date: 12.9
writer: Tzur
review: Ziv
Status: approved
*/
/* Ex1 */
long Pow2 (unsigned int x, unsigned int y)
{
	return x<<y;
}

 /* date: 12.9
writer: Tzur
review: Ziv
Status: approved
*/

/* Ex2 */

int  Ex2Loop  (unsigned int num)
{
    unsigned int i = 0;
    for(i = 1 ; i < 33 ; ++i )
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
	if ( 0 == num )
		return 0;
	
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
/*	pseudo: 							*
 *	search for first 0 bit				*
 *		- change 1 bit to 0				*
 *		- scan the next bit				*
 *	when done , flip the 0 bit to 1		*/
	
/* Ex3 */
int AddOne( int num)
{
	int mask = 1;
	
	while (0 != (num & mask))
	{
		num &= ~mask;
		mask <<= 1;
	}
	num |= mask;
	
	return num;
}

 /* date: 12.9
writer: Tzur
review: Ziv
Status: approved
*/

/* Ex4  +Ex9*/	
/* input: num , output: count bits on (1)					*
 * explain:  												*
 * count += num &1 - check and count if the last bit is 1	*
 * num>>=1 - change the num like 0110 >> 1  -> 1100 		*/

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


 /* date: 12.9
writer: Tzur
review: Ziv
Status: approved
*/
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

 /* date: 12.9
writer: Tzur
review: Ziv
Status: approved
*/

/* Ex5 ByteMirror */

unsigned char ByteMirror(unsigned char byte) 
{			/*11110000 */
   byte = (byte & 0xF0) >> 4 | (byte & 0x0F) << 4;
   byte = (byte & 0xCC) >> 2 | (byte & 0x33) << 2;
   byte = (byte & 0xAA) >> 1 | (byte & 0x55) << 1;
   return byte;
}

 /* date: 12.9
writer: Tzur
review: Ziv
Status: approved
*/

/* Ex6 */

unsigned char Bit2and6( unsigned char num)
{
	/*   	 00000010 		 00100000 */
	return ((num & 0x2)	 && (num & 0x20));

}

unsigned char Bit2or6( unsigned char num)
{
	/*   	 00000010 		 00100000 */
	return ((num & 0x2) || (num & 0x20));
}

unsigned char Bit3swap5( unsigned int num)
{
	char a = 0;
	
	a = (((num << 2) & 16) | ((num >> 2) & 4));
	num &= 235; /* 1110 1011 */
	num |= a;
	
	return num;
}

 /* date: 12.9
writer: Tzur
review: Ziv
Status: approved
*/
/*	Ex7																*
*	pseudo:															*
*	check if num is equal to num*16/16 if not check for (num-1)		*
*	example:														*
*	num != (num >> 4) << 4											*
*	32 !=	(32/16 *16)=32											*/

int Div16 (unsigned int num)
{
	while ( num != (num >> 4) << 4 )
	{
		-- num;
	}
	
	return num;
}

 /* date: 12.9
writer: Tzur
review: Ziv
Status: approved
*/

/* Ex8  swap with bitwise*/

void SwapXor (int *num1 , int *num2)
{
   *num1 = *num1 ^ *num2;
   *num2 = *num1 ^ *num2;
   *num1 = *num1 ^ *num2;
}


 /* date: 12.9
writer: Tzur
review: Ziv
Status: approved
*/

/* Ex9  without loop , need to understand */

int CountCheckBit (unsigned int num)
{ 
	int a1 = 0;	/*nibble 1*/
	int a2 = 0;	/*nibble 2*/
	int a3 = 0;	/*nibble 3*/
	int a4 = 0;	/*nibble 4*/
	int a5 = 0;	/*nibble 5*/
	int a6 = 0;	/*nibble 6*/
	int a7 = 0;	/*nibble 7*/
	int a8 = 0;	/*nibble 8*/
	
	a1 = (num >> 3 & 1) + (num >> 2 & 1) + (num >> 1 & 1) + (num & 1);
	num >>= 4;
	a2 = (num >> 3 & 1) + (num >> 2 & 1) + (num >> 1 & 1) + (num & 1);
	num >>= 4;
	a3 = (num >> 3 & 1) + (num >> 2 & 1) + (num >> 1 & 1) + (num & 1);
	num >>= 4;
	a4 = (num >> 3 & 1) + (num >> 2 & 1) + (num >> 1 & 1) + (num & 1);
	num >>= 4;
	a5 = (num >> 3 & 1) + (num >> 2 & 1) + (num >> 1 & 1) + (num & 1);
	num >>= 4;
	a6 = (num >> 3 & 1) + (num >> 2 & 1) + (num >> 1 & 1) + (num & 1);
	num >>= 4;
	a7 = (num >> 3 & 1) + (num >> 2 & 1) + (num >> 1 & 1) + (num & 1);
	num >>= 4;
	a8 = (num >> 3 & 1) + (num >> 2 & 1) + (num >> 1 & 1) + (num & 1);
	
	return (a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8);

}

 /* date: 12.9
writer: Tzur
review: Mark
Status: approved
*/

/*	Ex10															*
*	pseudo:															*
*	cast float to int												*
*	run as size of float 4*8										*
*		-print the last bit											*/
void FloatBitPrint( float num)
{
	int count = 0;
	unsigned int number;
	unsigned int x =  *(unsigned int *) &num;
	printf("original: %f , uint: %u \n" ,num, x);
	
	for(count = 31; count > -1; --count)
	{
		number = x >> count;
		number = number & 1;
		printf("%u", (number));
	}
	
	printf("\n");

}





