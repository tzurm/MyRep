#include "files.h"

void Ex1_Test();

void Ex2_Test();


int main() 

{
	printf("\n*********** TESTS  Ex1 function ************************ \n\n");
	
	Ex1_Test();
   
	printf("\n\n\n*********** TESTS  Ex2 function ************************\n");
	
	Ex2_Test();
	
	return 0;
}
	

void Ex1_Test()
{
	Ex1();
}
	
void Ex2_Test()
{
	char filename[] = "";
	printf("Enter file name: ");
	scanf("%s", filename);
	ex2(filename);
}





	
     

