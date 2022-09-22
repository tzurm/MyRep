
#ifndef __BITARR__
#define __BITARR__

typedef char[8] bitarr;


bitarr Set_All(bit_arr arr);									

bitarr Reset_All(bitarr arr);								

bitarr Set_On(bitarr arr, size_t index);									

bitarr Set_Off(bitarr arr, size_t index);					

bitarr Set_Bit(bitarr arr ,int value ,size_t index );	

int Get_Val(bitarr arr , size_t index );

bitarr FlipBit(bitarr arr , size_t index );								

bitarr Mirror(bitarr arr);

bitarr RotateRight(bitarr arr , int num );

bitarr RotateLeft(bitarr arr , int num );

size_t CountOn(*bitarr arr);

size_t  CountOff(bitarr arr);

char ToString(*bitarr arr);


#endif
