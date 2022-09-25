#include <stddef.h>
#ifndef __ILRD_CR02_ARRAY_H__
#define __ILRD_CR02_ARRAY_H__

typedef size_t bit_arr_t;

bit_arr_t SetAll(bit_arr_t arr);									

bit_arr_t ResetAll(bit_arr_t arr);								

bit_arr_t SetOn(bit_arr_t arr, size_t index);									

bit_arr_t SetOff(bit_arr_t arr, size_t index);					

bit_arr_t SetBit(bit_arr_t arr ,size_t index ,int value );	

int GetVal(bit_arr_t arr , size_t index );

bit_arr_t FlipBit(bit_arr_t arr , size_t index );								

bit_arr_t Mirror(bit_arr_t arr);

bit_arr_t RotateRight(bit_arr_t arr , size_t num );

bit_arr_t RotateLeft(bit_arr_t arr , size_t num );

size_t CountOn(bit_arr_t arr);

size_t  CountOff(bit_arr_t arr);

char *ToString(bit_arr_t arr , char *str);


#endif

