#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "atoi.h"

void CheckAtoi(char **str, int n);

void CheckItoa(int num , char *buffer, int base);

void Test_Atoi();

void Test_Itoa();

void Test_found_at_two_array();

void Test_Endian();


int main() 
{
	printf("\n***** TESTS  Atoi explicit:string to int **************** \n\n");
  
 	Test_Atoi();
 	
 	printf("\n\n***** TESTS  Itoa  explicit: int to string ************ \n\n");
  
 	Test_Itoa();
 	
 	printf("\n\n***** TESTS Found in two arraay *********************** \n\n");
  
 	Test_found_at_two_array();
 	
 	printf("\n\n***** TESTS endian ************************************ \n\n");
  
 	Test_Endian();

	
	return(0);
}	
 	
/* string to int */
void Test_Atoi()
{
	char *str_arr[] ={"0", "123" , "3check" , "check3" , "-10" , "-15f",
	 "  7a" , "  100" ,"  10 1"   };
	size_t len = sizeof(str_arr)/sizeof (str_arr[0]);
	CheckAtoi(str_arr , len);
   
}

/* int to string */
void Test_Itoa()
{
	char buffer1[50] = {0};
	char buffer2[50] = {0};
	char buffer3[50] = {0};
	char buffer4[50] = {0};
	char buffer5[50] = {0};
	char buffer6[50] = {0};
	char buffer7[50] = {0};
	char buffer8[50] = {0};
	char buffer9[50] = {0};
	char buffer10[50] = {0};
	char buffer11[50] = {0};
	char buffer12[50] = {0};
	
	CheckItoa(1010, buffer1, 10);
	CheckItoa(1000, buffer2, 10);
	CheckItoa(101, buffer3, 10);
	CheckItoa(123, buffer4, 10);
	CheckItoa(100, buffer5, 10);
	CheckItoa(1, buffer6, 10);
	CheckItoa(0, buffer7, 10);
	CheckItoa(-1, buffer8, 10);
	CheckItoa(-100, buffer9, 10);
	CheckItoa(-123, buffer10, 10);
	CheckItoa(-1000, buffer11, 10);
	CheckItoa(-1010, buffer12, 10);
	
}

void Test_found_at_two_array()
{
	char str1[7] = {'A','B','C','D','E','F','\0'};
	char str2[7] = {'B','C','A','D','3','4','\0'};
	char str3[7] = {'A','C','4','3','E','F','\0'};
	
	IsChInArr(str1, str2, str3, 7, 7, 6);
	
}

void Test_Endian()
{
	unsigned int num = 1234;
	CheckEndian((char*)&num);
	
	(1 == CheckMacroEndian()) ? printf("Little endian\n") : printf("big");
	
}

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



