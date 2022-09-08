#include "arrays_pointers.h"
#define ROW 2
#define COLUMN 4

void PrintDataTypesTest();

void YosefTest();

void SumRowsTest();

void EnvpTest();

int main() 
{
	
	printf("\n***************************************** ");
	printf("\n***** TESTS  PrintDataTypes function **** \n");
	printf("*****************************************\n"); 
	
	PrintDataTypesTest();
	
	printf("\n***************************************** ");
   	printf("\n***** TESTS  Yosef function ************* \n");
	printf("*****************************************\n"); 
	
	YosefTest();
	
	printf("\n***************************************** ");
   	printf("\n***** TESTS  SumRows function *********** \n");
	printf("*****************************************\n"); 
	
	SumRowsTest();
	
	printf("\n***************************************** ");
   	printf("\n***** TESTS  EnvpTest function *********** \n");
	printf("*****************************************\n"); 
	
	EnvpTest();
	
	
	return 0;
}

	
void PrintDataTypesTest()
{
		
	PrintDataTypes();
	printf("\n");
}
 
	
	
void YosefTest()
{
	size_t n100[100] = {0};
	size_t n50[50] = {0};
	size_t n1[1] = {0};
		
	printf("n=100, The lucky one %lu\n", Yosef(100,n100));
	printf("n=50, The lucky one %lu\n", Yosef(50,n50));
	 printf("n=1, The lucky one %lu\n", Yosef(1,n1));
	 	
}
	 	
 	

void SumRowsTest()
{
	int i=0;
	size_t arrsum[2] = {0};
	int arr[2][4] = 
 	{
		{10, 20, 30, 30},
		{1, 2, 3, 3}
	};
		
	Print2d(arr, ROW, COLUMN);
   	SumRows(arr, arrsum ,ROW, COLUMN);
   		
   	/*print new array */
   	for(i=0 ; i < 2 ; i++)
   	{
		printf("%lu\n", arrsum[i]);
   	}
}
   
   
void EnvpTest()
{
	PrintEnv();
}
	
     

