#include <assert.h>  

#include "atoi.h"


void CheckAtoi(char **str, int n)
{
	int i = 0;
	for(i  =0 ; i < n ; ++i)
	{
    printf("\ninput:	%s	Atoi:	%d	atoi:	%d	",
    	str[i], 	Atoi(str[i]) ,atoi(str[i]));
	
	Atoi(str[i]) == atoi(str[i]) ? printf("SUCCESS") : printf("FAILURE");
    }
    
}


void CheckItoa(int num , char *buffer, int base)
{
	printf("\nnum:	%d	base:	%d	Itoa:	%s", num, base, Itoa(num,buffer,base));
}

static char *ReverseStr(char *str)
{
	char temp;
	char *end = str + strlen(str) - 1;

	assert(NULL != str);

	while (str < end)
	{
		temp = *str;
		*str = *end;
		*end = temp;
		++str;
		--end;
	}
	
	return 0;
}



/*  Approve by					*/

/* string to int 				*
 *	pseudo						*
 *	While the char is number	*
 *		Sum every byte			*
 *		Return sun				*/
 

int Atoi(char *str)	
{
    int i = 0;
    int result = 0;
    int is_negative = 0;
    
    assert(NULL != str);
    
    if( '-' == str[i])
    {
    	is_negative=1;
    	++i;
    }
    
    while( '9' >= str[i] && '0' <= str[i] && '\0' != str[i] )
    {    
        result = result * 10 + str[i] -'0';
        ++i;
    }
    
    if( 1 == is_negative)
    {
    	result = -result;
    }
    
    return result;
}


/*	Approve by							*/

/*	int to string						*
 *	pseudo								*
 *	move the last digit to string		*
 *	if 0 return 0 						*
 *	if negative append '-'				*/
 
 
char *Itoa(int num, char *buffer, int base)		
{
	int i = 0;
	int one_digit = 0;
    int is_negative = 0;
 	(void)base;
 	
 	assert(NULL != buffer);
    
    if( 0 == num)
	{
		buffer[i] = '0';
		return buffer;
	}
    
    if(num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	
	while(num > 0)
	{
		one_digit = num % base;
		buffer[i] = one_digit + '0' ;
        num /= base;
		++i;
      
    }
    
	if(1 ==  is_negative)
 	{
 		buffer[i] = '-';
 	}
    ReverseStr(buffer);
    
    return buffer;
}

