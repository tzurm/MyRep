#include <stdio.h>
#include <stddef.h>
#include "vector.h"					/*		my_vector		*/

void Test_1();
/*
void Test_2_EmptyVector();
*/

int main() 
{
   
	printf("\n***********	Test_1		************************ \n\n");
	
	Test_1();
	
	/*
	printf("\n***********	Test_2_EmptyVector ************************ \n\n");
	
	Test_2_EmptyVector();
	*/
	
	
	
	return 0;
}



void Test_1()
{

	vector_t *vector = VectorCreate(4 ,4);
	int value[] ={3,6,9,278};
	
	
}

void Test_2_EmptyStack()
{

}




