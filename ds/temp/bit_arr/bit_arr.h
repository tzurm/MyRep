#include <stddef.h>
#ifndef __ILRD_CR02_ARRAY_H__
#define __ILRD_CR02_ARRAY_H__

typedef size_t bit_arr_t;

/* set all bit to 1		*
* input: arr 			*			
* output: arr			*/	
					
bit_arr_t SetAll(bit_arr_t arr);


/* set all bit to 0		*/	
/* input: arr			*/			 		
/* output: arr			*/

bit_arr_t ResetAll(bit_arr_t arr);							


/* set one bit to 1		*/	
/* input: arr, index	*/ 				
/* output: arr			*/


/* set one bit to 1		 	input: arr, index 				output: arr		*/
bit_arr_t SetOn(bit_arr_t arr, size_t index);									


/* set one bit to 0	 		input: arr, index		 		output: arr		*/
bit_arr_t SetOff(bit_arr_t arr, size_t index);					


/* set one bit to value	 	input: arr, index, value 		output: arr		*/
bit_arr_t SetBit(bit_arr_t arr ,size_t index ,int value);	


/* get value of bit			input: arr, index		 		output: arr		*/
int GetVal(bit_arr_t arr , size_t index );


/* get flip one bit			input: arr, index		 		output: arr		*/
bit_arr_t FlipBit(bit_arr_t arr , size_t index);								


/* mirror the array			input: arr				 		output: arr		*/
bit_arr_t Mirror(bit_arr_t arr);


/* Rotate Right n times		input: arr, num		 			output: arr		*/
bit_arr_t RotateRight(bit_arr_t arr , size_t num);


/* Rotate left n times		input: arr, num		 			output: arr		*/
bit_arr_t RotateLeft(bit_arr_t arr , size_t num);


/* count bits on			input: arr				 		output: num		*/
size_t CountOn(bit_arr_t arr);


/* count bits off					input: arr		 		output: num		*/
size_t  CountOff(bit_arr_t arr);


/* return the array as string		input: arr			s	output: char	*/	
char *ToString(bit_arr_t arr , char *str);

size_t CountBitLut(bit_arr_t arr);

bit_arr_t MirrorLut(bit_arr_t arr);

#endif


