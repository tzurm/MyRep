#include "files.h"
#include <assert.h>


/* date: 
writer: 
review: 
Status: 
*/


#include <stdio.h>

void Print (int a)
{
    printf("%d" , a);
}


void Ex1 ()
{
    int i = 0;
    struct print_me
    {
      int a;
      void (*p)(int);
    };
    
    struct print_me arr[10];
    
    for( i = 0 ; i < 10 ;++i )
    {
    	arr[i].a = i;
    	arr[i].p = Print;
    }
    
     for( i = 0 ; i < 10 ;++i )
    {
    	(arr[i].p)(arr[i].a);
    }
}


