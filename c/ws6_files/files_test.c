#include "files.h"



void Ex1_Test();

void Ex2_Test();


int main() 

{
	

	printf("\n*********** TESTS  Ex1 function *********** \n\n");
	
	
	Ex1_Test();
   
	printf("\n\n\n*********** TESTS  Ex2 function *********** \n\n");
	
	Ex2_Test();
   
	
	return 0;
}
	

void Ex1_Test()
{
	Ex1();
}
	
void Ex2_Test()
{

	ex2("temp_f.txt");
	

}





	
     

