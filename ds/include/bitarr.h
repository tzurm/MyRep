#ifndef __BITARR__
#define __BITARR__

typedef size_t bitarr;


bitarr SetAll(bitarr bit_arr);									

bitarr ResetAll(bitarr bit_arr);								

bitarr SetOn(bitarr bit_arr, size_t index);									

bitarr SetOff(bitarr bit_arr, size_t index);					

bitarr SetBit(bitarr bit_arr ,size_t index ,int value );	

int GetVal(bitarr bit_arr , size_t index );

bitarr FlipBit(bitarr bit_arr , size_t index );								

bitarr Mirror(bitarr bit_arr);

bitarr RotateRight(bitarr bit_arr , size_t num );

bitarr RotateLeft(bitarr bit_arr , size_t num );

size_t CountOn(bitarr bit_arr);

size_t  CountOff(bitarr bit_arr);

char *ToString(bitarr bit_arr , char *str);


#endif
