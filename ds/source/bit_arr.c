
#include <stddef.h>
#include "bit_arr.h"

#define LEN = 64

typedef size_t bit_arr_t;

/* set all bit to 1	 		input: arr 						output: arr		*/


bit_arr_t SetAll(bit_arr_t arr)
{
	
	return arr | 0xFF;
}								

/* set all bit to 0		 	input: arr				 		output: arr		*/

bit_arr_t ResetAll(bit_arr_t arr)	
{
	
	return arr;
}							

/* set one bit to 1		 	input: arr, index 				output: arr		*/

bit_arr_t SetOn(bit_arr_t arr, size_t index)	
{
	
	return arr;
}							

/* set one bit to 0	 		input: arr, index		 		output: arr		*/

bit_arr_t SetOff(bit_arr_t arr, size_t index)	
{
	
	return arr;
}							

				
/* set one bit to value	 	input: arr, index, value 		output: arr		*/
bit_arr_t SetBit(bit_arr_t arr ,size_t index ,int value )	
{
	
	return arr;
}							


/* get value of bit			input: arr, index		 		output: arr		*/
int GetVal(bit_arr_t arr , size_t index )	
{
	
	
	return 1;
}							


/* get flip one bit			input: arr, index		 		output: arr		*/

bit_arr_t FlipBit(bit_arr_t arr , size_t index )	
{
	
	return arr;
}							

								
/* mirror the array			input: arr				 		output: arr		*/

bit_arr_t Mirror(bit_arr_t arr)	
{
	
	return arr;
}							


/* Rotate Right n times		input: arr, num		 			output: arr		*/

bit_arr_t RotateRight(bit_arr_t arr , size_t num )	
{
	
	return arr;
}							


/* Rotate left n times		input: arr, num		 			output: arr		*/

bit_arr_t RotateLeft(bit_arr_t arr , size_t num )	
{
	
	return arr;
}							


/* count bits on			input: arr				 		output: num		*/

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

/* count bits off					input: arr		 		output: num		*/

size_t  CountOff(bit_arr_t arr)	
{	
	
	return LEN-CountOn(arr);
}


/* return the array as string		input: arr			s	output: char	*/	

char *ToString(bit_arr_t arr , char *str)	
{
	
	return sprintf(str, "%d" , arr);
}



