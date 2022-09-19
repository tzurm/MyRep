#include <stdio.h>
#include <string.h>
#include "boundary.h"


void Ex1_Memset();
void Ex1_Memcpy();
void Ex1_Memmove();


int main() 

{
	printf("\n***** TESTS  memset **************************** \n\n");
  
 	Ex1_Memset();
 	
 	printf("\n***** TESTS  Ex2 Check if power 2 *********************** \n\n");
  
 	Ex1_Memcpy();
 	
 	printf("\n***** TESTS  Ex3 Add one ******************************** \n\n");
  
 	Ex1_Memmove();
 
	return(0);
}	
 	

Ex1_Memset()
{
	char str[50];
	strcpy(str,"This is string.h library function");
	puts(str);
	memset(str,'$',7);
	puts(str);
}

   

