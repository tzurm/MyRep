#include <stdio.h>		/*	sizeof	*/
#include <assert.h>	
#include "boundary.h"
#define WORDSIZE sizeof(size_t *)


/*	pseudo
 *	set byte by byte until aligned 					*
 *	initialize the array (size of word) to char		*					 
 *	set s by the array								*
 *	set the rest if needed byte by byte				*/


/*
static void *SetByte(void *s, int c)
{
	char *ptr_s = (char*)s;
	
	*ptr_s = (char)c;
	++ptr_s;

	return ptr_s;
}
*/

void *Memset(void *s, int c, size_t n)
{
    char *ptr_s = (char*)s;
    size_t arr[WORDSIZE] = {0};
    size_t i = 0;
     
    while( (0 < n) && (0 != ((size_t)&ptr_s % WORDSIZE)) )
    {
      
		*ptr_s = (char)c;
		++ptr_s;
		--n;
    }
    
    for ( i = 0 ; i < WORDSIZE ; ++i )
    {
    	arr[i] = (char)c;
	}
    
    while( WORDSIZE <= n ) 
    {
        *(size_t*)ptr_s = *(size_t*)arr;
        n -= WORDSIZE;
        ptr_s += WORDSIZE; 
	}
   
    while ( 0 < n )
    {
    	*ptr_s = (char)c;
		++ptr_s;
		--n;
	}
	
    return s;
}

/*	pseudo							 						*				
 *	while wordsize < num			 						*
 *		copy word to dest									*		
 *	set the rest if needed byte by byte						*/

void *Memcpy(void *dest,const void *src, size_t n)
{
	
    char *p_dest = (char*)dest;
    char *p_src = (char*)src;
 	
 	while (WORDSIZE <= n)
 	{
    	*(size_t*)p_dest =*(size_t*)p_src;
  		p_dest += WORDSIZE; 
		p_src += WORDSIZE;
 		n -= WORDSIZE;
 	}
 	
    while ( 0 < n )
 	{
 		*p_dest =*p_src;
 		++p_dest; 
		++p_src;
		--n;
 	}
 
    return dest;
}

/*	pseudo							 					*				
 *	check what address is higher						*
 *	if dest 											*
 *		point to last byte of dest		 				*
 *		copy from end to start	(src to dest)			*		
 *	else												*
 *		copy from start to end (src to dest)
 														*/
 								
void *Memmove(void *dest, const void *src, size_t n)
{
	
	printf("%ld \n" , (long int)dest);
	printf("%ld \n" , (long int)src);
	
	return dest;
	/*
	char *p_dest = (char*)dest;
    char *p_src = (char*)src;
	if (&p_dest > &p_src) */
}



    
