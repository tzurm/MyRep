#include <assert.h>					/*	assert	*/
#include <stddef.h>					/*	size_t	*/
#include "bit_arr.h"

#define LEN_BIT_ARR 64
#define BITON '1'
#define BITOFF '0'
#define CHAR_SIZE 256
#define BYTE 8

/*	Approved by Arie	*/

bit_arr_t SetAll(bit_arr_t arr)
{
	return ~(arr & 0);
}								

/*	Approved by Arie 28.9	*/

bit_arr_t ResetAll(bit_arr_t arr)	
{
	return arr & 0;
}							

/*	Approved by Arie 28.9	*/
/* arr OR 1 return 1	*/
bit_arr_t SetOn(bit_arr_t arr, size_t index)	
{
	/*assert(index < 64); */
	arr |= 1UL << index;
	
	return arr;
}							

/*	Approved by Arie 28.9	*/
/* arr AND 0 return 0	*/
bit_arr_t SetOff(bit_arr_t arr, size_t index)	
{
/*	assert (LEN_BIT_ARR > index); */
	arr &= ~(1UL << index);
	
	return arr;
}							

				
/*	Approved by Arie 28.9	*/
bit_arr_t SetBit(bit_arr_t arr ,size_t index ,int value)	
{
	/*assert (LEN_BIT_ARR > index);
	assert (LEN_BIT_ARR > index);*/
	arr ^= (-value ^ arr) & (1UL << index);
	
	return arr;
}							

/*	Approved by Arie 28.9	*/
/* if 1 return 1 if no return 0	*/
int GetVal(bit_arr_t arr , size_t index)	
{
/*	assert (LEN_BIT_ARR > index); */
	return (arr >> index) & 1;
}							


/*	Approved by Alex 28.9			*/

bit_arr_t FlipBit(bit_arr_t arr , size_t index)	
{
	
	return arr^(1UL << index);
}							

								
/*	Approved by Alex 28.9			*/
/*	pseudo							*
 *	create new arr					*
 *	pass the first bit				*
 *	pass the next bit until end		*
 *	return the reversed array		*/
 
bit_arr_t Mirror(bit_arr_t arr)	
{
	int i = 0;
	
	bit_arr_t rev = arr & 1;
	for ( i = 1; i < LEN_BIT_ARR; ++i) 
	{
		arr = arr >> 1;
		rev = rev << 1;
		rev = rev | (arr & 1);
	}
	return rev;
}
					

/*	Approved by Alex 28.9			*/

bit_arr_t RotateRight(bit_arr_t arr , size_t num)	
{
	return ((arr >> num)|(arr << (LEN_BIT_ARR - num)));
}							

/*	Approved by Alex 28.9			*/

bit_arr_t RotateLeft(bit_arr_t arr , size_t num )	
{

	return ((arr << num)|(arr >> (LEN_BIT_ARR - num)));
}							

/*	Approved by Alex 28.9			*/

size_t CountOn(bit_arr_t arr)	
{
	size_t count = 0;
    
    while ( 0 != arr )
    {
        count += arr & 1;
        arr >>= 1;
    }
    
	return count;
}							

/*	Approved by Alex 28.9			*/

size_t  CountOff(bit_arr_t arr)	
{	
	
	return LEN_BIT_ARR-CountOn(arr);
}

/*	Approved by Mark 28.9			*/

char *ToString(bit_arr_t arr , char *str)	
{
    size_t i = 0;
    
    str += LEN_BIT_ARR; 
    *str='\0';
    --str;
    
    for(i = 0; i < LEN_BIT_ARR; ++i)
    {  
    	(1 == (arr & 1)) ? (*str = BITON) : (*str = BITOFF); 
		arr = arr >> 1;
		--str;
    }
   
    return str;

}

static size_t *InitCountBitLut()
{
	static size_t count_lut[CHAR_SIZE] = {0};
	size_t i = 0;
	for (i=0; i < CHAR_SIZE; i++) 
	{
		count_lut[i] = count_lut[i/2] + (i&1);
	}
	return count_lut;
}


/*	pseudo							*
 *	Init Lut						*
 *	div the number to 8 bytes (8*8)	*
 *	count the bits on at one byte	*
 *	sum the count					*/
 
size_t CountBitLut(bit_arr_t arr)	
{
	size_t *count_lut = InitCountBitLut();
	size_t count_bit = 0;
	bit_arr_t runner = 0;
	size_t i = 0;

	while(BYTE > i)
	{
		runner = arr &  0xff;
		count_bit += count_lut[runner];
		arr >>= 8;
		++i;
	}
	

	return count_bit;
}


static bit_arr_t *InitMirrorLut()
{
	static bit_arr_t mirror_lut[CHAR_SIZE] = {0};
	size_t i = 0;
	for(i = 0; i < CHAR_SIZE; ++i)
	{
		mirror_lut[i] = Mirror(i);
	}
	return mirror_lut;
}


bit_arr_t MirrorLut(bit_arr_t arr)
{
	bit_arr_t *mirror_lut = InitMirrorLut();
	bit_arr_t mirror_bit = 0;
	bit_arr_t runner = 0;
	size_t i = 0;

	while(7 > i)
	{
		runner = arr &  0xff;
		mirror_bit |= mirror_lut[runner];
		mirror_bit <<=8;
		arr >>= 8;
		++i;
	}
	
	return mirror_bit;
}



