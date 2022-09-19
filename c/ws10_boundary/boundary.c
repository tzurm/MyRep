#include <assert.h>	
#include "boundary.h"

void *Memset(void *s, int c, size_t n)
{
    unsigned char* p=s;
    while( 0 < n)
    {
        *p = (unsigned char)c;
    	++p;
    	--n;
    }
    return s;
}
