#include <stddef.h>
#include <stdio.h>

#include "bit_arr.h"






int main() 
{
    
	size_t arr = 4294967295;	/* half bits ON */
	size_t arr2 = 4294967295;	/* half bits ON */
	char buffer [65] ={0};
	
	
	/*******************************************************************/
	printf ("\n				TO STRING  & COUNT ON / OFF				\n");
	ToString(arr , buffer);
	printf ("\narr:	%s %ld %ld\n " ,buffer, CountOff(arr) ,CountOn(arr));
	
	/*******************************************************************/
    printf ("\n				SET ALL TO 1							\n");
    
	arr = SetAll(arr);
	ToString(arr , buffer);
	printf ("\narr:	%s\n", buffer);
	
	/*******************************************************************/
	printf ("\n				SET ALL TO 0							\n");
	
	arr = ResetAll(arr);
	ToString(arr , buffer);
	printf ("\narr:	%s\n", buffer);
	
	/*******************************************************************/
	printf ("\n				SET ON ONE BIT							\n");
	
	arr = SetOn(arr , 0);
	arr = SetOn(arr , 63);
	ToString(arr , buffer);
	printf ("\narr:	%s\n", buffer);
	
	/*******************************************************************/
	printf ("\n				SET OFF ONE BIT							\n");

	arr = SetOff(arr , 63);
	ToString(arr , buffer);
	printf ("\narr:	%s\n", buffer);
	
	/*******************************************************************/
	printf ("\n				FLIP ONE BIT n=63 , n=1					\n");
	
	arr = FlipBit(arr, 63);
	arr = FlipBit(arr, 1);
	ToString(arr , buffer);
	printf ("\narr:	%s\n", buffer);
	
	/*******************************************************************/
	printf ("\n				SET BIT TO VALUE						\n");

	arr = SetBit(arr, 17 ,1);
	arr = SetBit(arr, 8 , 1);
	ToString(arr , buffer);
	printf ("\narr:	%s\n", buffer);
	
	/*******************************************************************/
	printf ("\n				TEST MIRROR								\n");
	
	ToString(arr , buffer);
	printf ("\nbefore:	%s\n", buffer);
	arr = Mirror(arr);
	ToString(arr , buffer);
	printf ("\nafter:	%s\n", buffer);
	
	/*******************************************************************/
	
	printf ("\n				ROTATE RIGHT N=1						\n");
	
	arr = RotateRight(arr, 1);
	ToString(arr , buffer);
	printf ("\narr:	%s %ld %ld\n " ,buffer, CountOff(arr) ,CountOn(arr));
	
	/*******************************************************************/
	printf ("\n				ROTATE LEFT N=2							\n");
	arr = RotateLeft(arr, 2);
	ToString(arr , buffer);
	printf ("\narr:	%s %ld %ld\n " ,buffer, CountOff(arr) ,CountOn(arr));
	
	printf ("\n				ROTATE LEFT N=129						\n");
	arr = RotateLeft(arr, 129);
	ToString(arr , buffer);
	printf ("\narr:	%s %ld %ld\n " ,buffer, CountOff(arr) ,CountOn(arr));
	
	printf ("\n				ROTATE LEFT N=80						\n");
	arr = RotateLeft(arr, 80);
	ToString(arr , buffer);
	printf ("\narr:	%s %ld %ld\n " ,buffer, CountOff(arr) ,CountOn(arr));
	

	/*******************************************************************/
	printf ("\n				GET VAL  N=1, N=63						\n");
	
	printf ("\nvalue of bit is  %d\n", GetVal(arr,1));
	printf ("\nvalue of bit is  %d\n", GetVal(arr,63));
	
	
	/*******************************************************************/
	printf ("\n				COUNT LUT								\n");
	printf("\n%lu have %lu bits on\n" ,arr2, CountBitLut(arr2));
	printf("\n3 have %lu bits on\n" , CountBitLut(3));
	printf("\n0 have %lu bits on\n" , CountBitLut(0));
	
	/*******************************************************************/
	printf ("\n				MIRROR LUT								\n");
    arr = MirrorLut(arr);
	ToString(arr , buffer);
	printf ("\narr:	%s %ld %ld\n " ,buffer, CountOff(arr) ,CountOn(arr));
	
	return 0;
}






