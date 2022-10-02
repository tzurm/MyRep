#include <stdio.h>		/*	sizeof	*/
#include "boundary.h"
#define WORDSIZE sizeof(size_t *)

/*  Approve by Alex 20.9*/
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
}									*/


void *Memset(void *s, int c, size_t n)
{
/*	char temp = (char)c;
	size_t size_c = 0; set 		*/ 
    char *runner = (char*)s;
    char arr[WORDSIZE] = {0};
    size_t i = 0;
     
    while( (0 < n) && (0 != ((size_t)&runner % WORDSIZE)))
    {
      
		*runner = (char)c;
		++runner;
		--n;
    }
    
    for ( i = 0 ; i < WORDSIZE ; ++i )
    {
    	arr[i] = (char)c;

	}
    
    while( WORDSIZE <= n ) 
    {
        *(size_t*)runner = *(size_t*)arr;
        n -= WORDSIZE;
        runner += WORDSIZE; 
	}
   
    while ( 0 < n )
    {
    	*runner = (char)c;
		++runner;
		--n;
	}
	
    return s;
}
/*  Approve by Ziv 20.9*/
/*	pseudo									*				
 *	while wordsize < num					*
 *		copy src to dest					*		
 *	set the rest if needed byte by byte		*/

void *Memcpy(void *dest,const void *src, size_t len)
{
	
    char *p_dest = (char*)dest;
    char *p_src = (char*)src;
 	
 	while (WORDSIZE <= len)
 	{
    	*(size_t*)p_dest =*(size_t*)p_src;
  		p_dest += WORDSIZE; 
		p_src += WORDSIZE;
 		len -= WORDSIZE;
 		
 	}
 	
    while (0 < len)
 	{
 		*p_dest =*p_src;
 		++p_dest; 
		++p_src;
		--len;
 	}
 
    return dest;
}

/*  Approve by Pini 20.9*/

/*	pseudo						 					*				
 *	check what address is higher for overlap		*
 *	if dest higher:									*
 *		point to last byte of dest					*
 *		copy from end to start	(src to dest)		*		
 *	else											*
 *		copy from start to end (src to dest)		*/
 								
void *Memmove(void *dest, const void *src, size_t n)
{
	char *p_dest = (char*)dest;
    char *p_src = (char*)src;
	if (&p_dest > &p_src) 
	{
		while ( NULL == p_dest)
		{
			++p_dest;
		}
		while ( 0 < n )
	 	{
			*p_dest = *p_src;
			--p_dest; 
			--p_src;
		}
	}
	else 
	{
		while ( 0 < n )
	 	{
	 		*p_dest =*p_src;
	 		++p_dest; 
			++p_src;
			--n;
	 	}
	}
	
	return dest;
	
	
}



    
