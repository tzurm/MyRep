#include "arrays_pointers.h"
#define row 2
#define column 4

int main() 
{

	int arr[row][column] = 
 	{
		{10, 20, 30, 30},
		{1, 2, 3, 3}
	};
	
	printf("\n***************************************** ");
   	printf("\n***** TESTS  PrintDataTypes function **** \n");
	printf("*****************************************\n"); 
	
	PrintDataTypes();
	printf("\n");
 
	printf("\n***************************************** ");
   	printf("\n***** TESTS  Yosef function ************* \n");
	printf("*****************************************\n"); 
	  
 	printf("n=10, The last alive is %d\n", Yosef(10));
    printf("n=50, The last alive is %d\n", Yosef(50));
    printf("n=100, The last alive is %d\n", Yosef(100));
 	
 	
	printf("\n***************************************** ");
   	printf("\n***** TESTS  SumRows function *********** \n");
	printf("*****************************************\n"); 
	
    Print2d(arr, row, column);
    SumRows(arr, row, column);
	
     return 0;
}

