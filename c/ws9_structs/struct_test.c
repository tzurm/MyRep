#include "struct.h"


   
void Ex1_Test();

void Ex5_Test();

void Ex6_Test();

void Ex7_Test();

int main() 

{
	printf("\n\n********** TESTS  Ex1 MultiTypeArray *******************\n\n");
	
	Ex1_Test();
   
	printf("\n\n********** TESTS  Ex5 Max a,b,c ************************\n\n");
	
	Ex5_Test();
	
	printf("\n\n********** TESTS  SIZE OF VAR *************************\n\n");
	
	Ex6_Test();
	
	printf("\n\n********** TESTS  SIZE OF TYPE *************************\n\n");
	
	Ex7_Test();
	
	return 0;
}
	

void Ex1_Test()
{
	 printf(" building here ");
}
	
void Ex5_Test()
{

	int a = 2,b = 5,c = 8;
	
	
	
    printf("The number are: ");
    printf("a = %d , b = %d \n", a, b);   
    printf("The max is %d\n",MAX2(a,b));
    printf("Enter 3 numbers: ");
    
    printf("a = %d , b = %d , c = %d\n",a, b, c);   
    printf("The max is %d\n",MAX3(a, b, c));
    
    
}


void Ex6_Test()
{
	struct my_struct 
	{
	  int my_int;
	  char my_char;
	};
	struct my_struct s1;
	
	char arr[5]={'0'};
	char arr2[100];
	
    printf("Size type: %ld \n", SIZEOF_TYPE(s1));
    printf("Size type: %ld \n", SIZEOF_TYPE(arr));
    printf("Size type: %ld \n", SIZEOF_TYPE(arr2));
   
}

void Ex7_Test()
{
	struct my_struct 
	{
	  int my_int;
	  char my_char;
	} s1;
	
	char arr[5]={'0'};
	char arr2[5];

    printf("Size var: %ld \n", SIZEOF_VAR(s1));
    printf("Size var: %ld \n", SIZEOF_VAR(arr));
    printf("Size var: %ld \n", SIZEOF_VAR(arr2));
   
}





	
     

