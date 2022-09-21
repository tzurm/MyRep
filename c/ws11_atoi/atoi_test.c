#include <stdlib.h>
#include "atoi.h"


void Test_Atoi();

void Test_Itoa();
/*
void Ex1_Memmove();
*/

int main() 
{
	printf("\n***** TESTS  Atoi explicit: string to int**************** \n\n");
  
 	Test_Atoi();
 	
  
 	printf("\n***** TESTS  Itoa  explicit: int to string ************** \n\n");
  
 	Test_Itoa();

 
	return(0);
}	
 	
/* string to int */
void Test_Atoi()
{
	char str1[] = "0";
 	char str2[] = "123";
    char str3[] = "3check";
    char str4[] = "check3";
    char str5[] = "-10";
    char str6[] = "-15f";
   
	CheckAtoi(str1);
	CheckAtoi(str2);
	CheckAtoi(str3);
	CheckAtoi(str4);
	CheckAtoi(str5);
	CheckAtoi(str6);
    
    printf("\n\n**********************************************************\n");

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
	
	CheckItoa(123, buffer1, 10);
	CheckItoa(123, buffer2, 8);
	CheckItoa(123, buffer3, 6);
	CheckItoa(123, buffer4, 2);
	CheckItoa(123, buffer5, 35);
	CheckItoa(0, buffer6, 10);
	CheckItoa(-123, buffer7, 10);
	CheckItoa(-123, buffer8, 2);
	
	printf("\n\n**********************************************************\n");
}



