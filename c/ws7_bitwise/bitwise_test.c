#include "bitwise.h"


void Ex1_Test();
void Ex2_Test();

void Ex4_Test();
void Ex5_Test();

void Ex7_Test();
void Ex8_Test();
void Ex9_Test();

int main() 

{
	printf("\n***** TESTS  Ex1 x*2 power y **************************** \n\n");
  
 	Ex1_Test();
 	
 	printf("\n***** TESTS  Ex2 Check if power 2 *********************** \n\n");
  
 	Ex2_Test();
 	
 	printf("\n***** TESTS  Ex4 3Bits ********************************** \n\n");
  
 	Ex4_Test();
 	
 	printf("\n***** TESTS  Ex5 check ByteMirror *********************** \n\n");
  
 	Ex5_Test();

	printf("\n***** TESTS  Ex7 Div16 ********************************** \n\n");
  
 	Ex7_Test();
	
	printf("\n***** TESTS  Ex8 Swap xor ******************************* \n\n");
  
 	Ex8_Test();
	
	
	printf("\n***** TESTS  Ex9 Count ********************************** \n\n");
  
 	Ex9_Test();
	
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

	size_t i = 0;
	unsigned int arr[] = {0, 256, 3 , 16};
	size_t len = sizeof(arr)/sizeof (arr[0]);
	
	printf("\nLoop Version\n");
	for (i = 0 ; i < len ; ++i)
	{
		(1 == Ex2Loop(arr[i])) ?  printf(" %d is pow of 2 \n" ,arr[i]) :
		printf(" %d isn't pow of 2 \n" ,arr[i] );
	}
	
	printf("\nNo Loop Version\n");
	for (i=0 ; i < len ; ++i)
	{
		(1 == Ex2V2(arr[i])) ?  printf(" %d is pow of 2\n" ,arr[i]) :
		printf(" %d isn't pow of 2\n" ,arr[i] );
	}


   	
}

void Ex4_Test()
{
	unsigned int arr[] = {7, 77, 0 , 81 , 53 , 44};
	size_t len = sizeof(arr)/sizeof (arr[0]);

    Bit3(arr ,len);

}


void Ex5_Test()
{
	size_t i = 0;
	unsigned int arr[] = {7, 77, 0 , 81 , 53 , 44};
	size_t len = sizeof(arr)/sizeof (arr[0]);
	
	for (i=0 ; i < len ; ++i)
	{
		printf("input:  %d\n" , ByteMirror(arr[i]));
	}
	
    

}


void Ex7_Test()
{
	size_t i = 0;
	unsigned int arr[] = {22, 100, 0 , 85};
	size_t len = sizeof(arr)/sizeof (arr[0]);
	
	for (i = 0 ; i < len ; ++i)
	{
		printf("input: %d , output: %d\n" , arr[i], Div16(arr[i]));
	} 

	
}



void Ex8_Test()
{
	int num1 = -2 , num2 = -3;
	printf("Before: num1: %d , num2: %d\n" ,num1 , num2);
	SwapXor(&num1 , &num2);
	printf("After:  num1: %d , num2: %d\n" ,num1 , num2);
 
}


void Ex9_Test()
{
	size_t i = 0;
	unsigned int arr[] = {22, 55, 0 , 85};
	size_t len = sizeof(arr)/sizeof (arr[0]);
	
	printf("Not Loop Version\n");
	for (i = 0 ; i < len ; ++i)
	{
		printf("%d have bits on: %d\n" , arr[i], CountCheckBit(arr[i]));
	}
	
	printf("Loop Version\n");
	for (i = 0 ; i < len ; ++i)
	{
		printf("%d have bits on: %d\n" , arr[i], CountBit(arr[i]));
	} 
}	






	
     

