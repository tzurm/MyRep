#include <assert.h>					/*	assert	*/
#include <stddef.h>					/*	size_t	*/



#include "../include/bit_arr.h"

#define LEN_BIT_ARR 64
#define BITON '1'
#define BITOFF '0'

bit_arr_t SetAll(bit_arr_t arr)
{
	return ~(arr & 0);
}								


bit_arr_t ResetAll(bit_arr_t arr)	
{
	return arr & 0;
}							

/* arr OR 1 return 1	*/
bit_arr_t SetOn(bit_arr_t arr, size_t index)	
{
	arr |= 1UL << index;
	
	return arr;
}							


/* arr AND 0 return 0	*/
bit_arr_t SetOff(bit_arr_t arr, size_t index)	
{
/*	assert (LEN_BIT_ARR > index); */
	arr &= ~(1UL << index);
	
	return arr;
}							

				

bit_arr_t SetBit(bit_arr_t arr ,size_t index ,int value )	
{
	/*assert (LEN_BIT_ARR > index);
	assert (LEN_BIT_ARR > index);*/
	arr ^= (-value ^ arr) & (1UL << index);
	
	return arr;
}							


/* if 1 return 1 if no return 0	*/
int GetVal(bit_arr_t arr , size_t index )	
{
	/*assert (LEN_BIT_ARR > index); */
	return (arr >> index) & 1;
}							




bit_arr_t FlipBit(bit_arr_t arr , size_t index )	
{
	
	return arr^(1UL << index);
}							

								

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



bit_arr_t RotateRight(bit_arr_t arr , size_t num )	
{
	bit_arr_t copy_arr = arr;
       
    num = num % LEN_BIT_ARR;
    arr = arr >> num;
    copy_arr = copy_arr << (LEN_BIT_ARR - num);
    
    return arr | copy_arr;
}							



bit_arr_t RotateLeft(bit_arr_t arr , size_t num )	
{
	

    bit_arr_t copy_arr = arr;
       
    num = num % LEN_BIT_ARR;
    arr = arr << num;
    copy_arr = copy_arr >> (LEN_BIT_ARR - num);
    
    return arr | copy_arr;


}							



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



size_t  CountOff(bit_arr_t arr)	
{	
	
	return LEN_BIT_ARR-CountOn(arr);
}



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

