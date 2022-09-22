#include <assert.h>  
#include <stdio.h>		/* printf */
#include <stdlib.h>		/* sprintf */
#include <string.h>		/* strcpy */
#include "atoi.h"

#define IS_LITTLE_ENDIAN() ((char *)(1) == (char *)(1u) ? (1) : (0))
#define LUT_LEN 256

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
	printf("\nnum: 	%d	base:	%d	Itoa:	%s	",
		num, base, Itoa(num,buffer,base));
	sprintf(buffer, "%d" , num);
	printf("sprintf	%s	", buffer);
	
	(0 == strncmp (buffer,Itoa(num,buffer,base),strlen(buffer))) ?
		printf("SUCCESS") : printf("FAILURE");
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



/*  Approve by	Andrey 22.9		*/

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


/*	Approve by	Andrey	22.9			*/

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


/*  Approve by	Andrey 22.9			*/	

/* CheckEndian						*
 *	pseudo							*
 *	if the left byte is empty		*
 *		yes ->	big endian			*		
 *		no	->	little endian		*/

void CheckEndian(char *c)	
{
	(0 == *c ) ? printf("Big endian\n") : printf("Little endian\n"); 
}

size_t CheckMacroEndian()	
{
	return IS_LITTLE_ENDIAN();
}




/*  Approve by	andrey 22.9													*/	

/* input 3 array output: the chars that appear in array 1,2 and not in 3	*
 *	pseudo																	*
 *	if found in array 1,2 flag equal to 3									*
 *	if found in 3 flag equal to 0											*		
 *	print all chars the with flag is 3										*/
 
void IsChInArr(char *arr1, char *arr2, char *arr3, int len1, int len2, int len3)
{
	char LUT[LUT_LEN] = {0};
	int i = 0;

	for(i = 0 ; i < len1-1 ; ++i)
	{
		LUT[(int)arr1[i]] = 1;
	}

	for(i = 0 ; i < len2-1 ; ++i)
	{
		if(3 == LUT[(int)arr2[i]])
		{
			continue;
		}
		LUT[(int)arr2[i]] += 2;
	}

	for(i = 0 ; i < len3 ; ++i)
	{
		LUT[(int)arr3[i]] = 0;
	}
	
	for(i = 0 ; i < LUT_LEN ; ++i)
	{
		if(3 == LUT[i])
		{
			printf("%d\t",(char)i);
		}
	}
}





