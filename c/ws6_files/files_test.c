#include "files.h"



void Ex1_Test();

void Ex2_Test();


int main() 

{
	
	printf("\n***************************************** ");
	printf("\n*** TESTS  Ex1 function **** \n");
	printf("*****************************************\n"); 
	
	Ex1_Test();
   
	printf("\n***************************************** ");
	printf("\n*** TESTS  Ex2 function **** \n");
	printf("*****************************************\n"); 
	
	Ex2_Test();
   
	
	return 0;
}
	

void Ex1_Test()
{
	Ex1();
}
	
void Ex2_Test()
{
	char *new_line = "this is the new line";
	char *first_str = "<first line go to the top ";	
	/*
	FILE *filename = NULL;
	filename = fopen("abc.txt" , "a");
	*/
	
 	Append("abc1.txt", new_line);
 	TopLine("abc1.txt", first_str+1);
	printf("number lines: %d\n" , Count("abc1.txt"));
    
	/* Remove("abc.txt");
	*/
}





	
     

