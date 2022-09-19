#include "boundary.h"


void Ex1_Memset();
/*void Ex1_Memcpy();
void Ex1_Memmove();
*/

int main() 

{
	printf("\n***** TESTS  memset **************************** \n\n");
  
 	Ex1_Memset();
 	/*
 	printf("\n***** TESTS  Ex2 Check if power 2 *********************** \n\n");
  
 	Ex1_Memcpy();
 	
 	printf("\n***** TESTS  Ex3 Add one ******************************** \n\n");
  
 	Ex1_Memmove();
 */
	return(0);
}	
 	

void Ex1_Memset()
{
	char str1[50];
	char str2[50];
	strcpy(str1,"$$$abcdefg");
	strcpy(str2,"$$$abcdefg");
	puts(str1);
	Memset(str1,'*',3);
	puts(str1);
	
	puts(str2);
	memset(str2,'*',3);
	puts(str2);
	
}

   

