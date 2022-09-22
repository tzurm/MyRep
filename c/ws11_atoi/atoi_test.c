#include <stdlib.h>
#include "atoi.h"


void Test_Atoi();

void Test_Itoa();

void Test_Endian();


int main() 
{
	printf("\n***** TESTS  Atoi explicit:string to int **************** \n\n");
  
 	Test_Atoi();
 	
  
 	printf("\n***** TESTS  Itoa  explicit: int to string ************** \n\n");
  
 	Test_Itoa();
 	
 	printf("\n***** TESTS endian *************************************** \n\n");
  
 	Test_Endian();

 
	return(0);
}	
 	
/* string to int */
void Test_Atoi()
{
	char *str_arr[6] ={"0", "123" , "3check" , "check3" , "-10" , "-15f"};

	CheckAtoi(str_arr , 6);
    
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
	
	CheckItoa(100000000, buffer1, 10);
	CheckItoa(1010, buffer2, 10);
	CheckItoa(101, buffer2, 10);
	CheckItoa(100, buffer3, 10);
	CheckItoa(1, buffer4, 10);
	CheckItoa(0, buffer5, 10);
	CheckItoa(-1, buffer6, 10);
	CheckItoa(-100, buffer7, 10);
	CheckItoa(-1010, buffer8, 10);
	CheckItoa(-1010000000, buffer8, 10);
	
	printf("\n\n***********************************************************\n");
}

void Test_Endian()
{
	unsigned int num = 1234;
	CheckEndian((char*)&num);
	
	CHECK_ENDIAN((char*)&num);
}



