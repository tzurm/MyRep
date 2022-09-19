#include <stdio.h>		/*	sizeof	*/
#include <assert.h>	
#include "boundary.h"

void *Memset(void *s, int c, size_t n)
{
    char* p=s;
    
    while( 0 < n)
    {
        *p = (char)c;
    	++p;
    	--n;
    }
    
    return s;
}



void *Memcpy(void* dest,const void* src, int n)
{
    char* p_dest = (char*)dest;
    char* p_src = (char*)src;

    if (n & 1) 
    {
        p_dest[0] = p_src[0];
        p_dest += 1;
        p_src += 1;
    }

    n /= 2;
    
    while (n--) 
    {
        p_dest[0] = p_src[0];
        p_dest[1] = p_src[1];

        p_dest += 2;
        p_src += 2;
    }
    return dest;
}


    
