#include "bitwise.h"


void Ex1_Test();
void Ex2_Test();

void Ex7_Test();
void Ex8_Test();

int main() 

{
	printf("\n*********** TESTS  Ex1 power 2 *********** \n\n");
  
 	Ex1_Test();
 	
 	printf("\n*********** TESTS  Ex2 check if power 2 *********** \n\n");
  
 	Ex2_Test();

	printf("\n*********** TESTS  Ex7 div16 *********** \n\n");
  
 	Ex7_Test();
	
	printf("\n*********** TESTS  Ex8 swap xor ********** \n\n");
  
 	Ex8_Test();
	
	
	return 0;
	
}
	
void Ex1_Test()
{
	unsigned int x = 3 , y = 4;
	printf("input: x= %d, y= %d, output: %ld\n" ,x ,y , Pow2(x,y));
	printf("input: x=2 , y=2, output: %ld\n" , Pow2(2,2));

}

void Ex2_Test()
{
	/* v1 */
	(1 == Ex2Loop(256)) ?  printf("256 is pow of 2\n" ) :
	printf("256 isn't pow of 2\n" );
	(1 == Ex2Loop(39)) ?  printf("39 is pow of 2\n" ) :
   	printf("39 isn't pow of 2\n" );
   	
   	/* v2 */
	(1 == Ex2V2(2)) ?  printf("2 is pow of 2\n" ) :
	printf("2 isn't pow of 2\n" );
	(1 == Ex2V2(3)) ?  printf("3 is pow of 2\n" ) :
   	printf("3 isn't pow of 2\n" );
   	
   	
}

void Ex7_Test()
{
	unsigned int num1=22;
	unsigned int num2=100;
	unsigned int num3=0;
	printf("input: %d , output: %d\n" ,num1 , Div16(num1));
	printf("input: %d , output: %d\n" ,num2 , Div16(num2));
	printf("input: %d , output: %d\n" ,num3 , Div16(num3));
	printf("input: 85 , output: %d\n" , Div16(85));
	
}

void Ex8_Test()
{
	int num1 = -2 , num2 = -3;
	printf("Before: num1: %d , num2: %d\n" ,num1 , num2);
	SwapXor(&num1 , &num2);
	printf("After:  num1: %d , num2: %d\n" ,num1 , num2);
 
}







	
     

