#include <stdio.h>		/*	sizeof	*/
#include <assert.h>	
#include "boundary.h"
#define WORDSIZE sizeof(size_t *)


/*	pseudo
     *	1. set byte by byte until aligned 					*
     *	2. initialize the array (size of word) to char		*					 
     *	3. set s by the array								*
     *	4. set the rest if needed byte by byte				*/



static void *SetByte(void *s, int c)
{
	char *ptr_s = (char*)s;
	
	*ptr_s = (char)c;
	++ptr_s;

	return ptr_s;
	
}

void *Memset(void *s, int c, size_t n)
{
    char *ptr_s = (char*)s;
    size_t arr[WORDSIZE] = {0};
    size_t i = 0;
     
    while( (0 < n) && (0 != ((size_t)&ptr_s % WORDSIZE)) )
    {
        ptr_s = SetByte(ptr_s, c);
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
    	ptr_s = SetByte(ptr_s, c);
    	--n;
	}
	
    return s;
}

/*	pseudo
 *	1. set byte by byte until aligned 						*
 *	2. keep copy the src to array							*		
 *			initialize the array (size of word) to src 		*					 
 *		 	set s by the array								*
 *	3. set the rest if needed byte by byte					*/

void *Memcpy(void *dest,const void* src, int n)
{
	
    char *p_dest = (char*)dest;
    char *p_src = (char*)src;
    size_t arr[WORDSIZE] = {0};
    
    while( (0 < n) && (0 != ((size_t)&p_dest % WORDSIZE)) )
    {
        ptr_s = SetByte(ptr_s, c);
		--n;
    }

 
 
 
    return dest;
}



    
