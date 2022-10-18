#include <stdio.h>
#include <stddef.h>
#include "fsa.h"					/*		fsa			*/


void Test_SuggestSize();


int main() 
{
   
	printf("*************************\n*   Test SuggestSize	* \n*************************\n");
	Test_SuggestSize();

	
	return 0;
}


void Test_SuggestSize()
{
	printf("Send:	11*3	SuggestSize:	%ld\n", SuggestSize(11,3));
	printf("Send:	7*12	SuggestSize:	%ld\n", SuggestSize(7,12));
	printf("Send:	1*1	SuggestSize:	%ld\n", SuggestSize(1,1));
}

