#include <stddef.h>
#include <stdio.h>

#include "../include/bit_arr.h"
#include "../source/bit_arr.c"





int main() 
{
    
	size_t arr = 4294967295;	/* half bits ON */
	char buffer [64] ={'\0'};
	
    ToString(arr , buffer);
	printf ("\narr:	%s\n", buffer);
    
    /*							set all to 1								*/
	arr = SetAll(arr);
	ToString(arr , buffer);
	printf ("\narr:	%s\n", buffer);
	
	/*							set all to 0								*/
	arr = ResetAll(arr);
	ToString(arr , buffer);
	printf ("\narr:	%s\n", buffer);
	
	/*							set ON bit 									*/
	arr = SetOn(arr , 0);
	arr = SetOn(arr , 63);
	ToString(arr , buffer);
	printf ("\narr:	%s\n", buffer);
	
	/*							set OFF bit 								*/
	arr = SetOff(arr , 63);
	ToString(arr , buffer);
	printf ("\narr:	%s\n", buffer);
	
	
	/*							flip one bit 								*/
	arr = FlipBit(arr, 63);
	arr = FlipBit(arr, 0);
	ToString(arr , buffer);
	printf ("\narr:	%s\n", buffer);
	
	
	/*							set bit to value							*/
	arr = SetBit(arr, 17 ,1);
	arr = SetBit(arr, 8 , 1);
	ToString(arr , buffer);
	printf ("\narr:	%s\n", buffer);
	
	/*							get val of bit 								*/
	
	printf ("\nvalue of bit is  %d\n", GetVal(arr,8));
	printf ("\nvalue of bit is  %d\n", GetVal(arr,63));
    
	
	/*							mirror 										*/
	
	ToString(arr , buffer);
	printf ("\narr:	%s\n", buffer);
	arr = Mirror(arr);
	ToString(arr , buffer);
	printf ("\narr:	%s\n", buffer);
	
	/*							count ON & OFF								*/
	
	ToString(arr , buffer);
	printf ("\narr:	%s %ld %ld\n " ,buffer, CountOff(arr) ,CountOn(arr));

	/*							rotate right								*/
	arr = RotateRight(arr, 0);
	ToString(arr , buffer);
	printf ("\narr:	%s %ld %ld\n " ,buffer, CountOff(arr) ,CountOn(arr));

	/*							rotate left									*/
	arr = RotateLeft(arr, 2);
	ToString(arr , buffer);
	printf ("\narr:	%s %ld %ld\n " ,buffer, CountOff(arr) ,CountOn(arr));

	return 0;
}

/*
	printf ("\nindex:	3210987654321098765432109876543210987654321098765432109876543210");
	*/





