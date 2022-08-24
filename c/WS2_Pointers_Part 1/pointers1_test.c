#include <stdio.h>
#include "all_functions.h"
#include "all_functions.c"


int main() 
{
    int num1,num2;
    printf("Enter num for num1 ");
    scanf("%d",&num1);
    printf("Enter num for num2 ");
    scanf("%d",&num2);
    printf("The values before swapping: \n");
    printf("num1: %d  num2: %d \n", num1, num2);
    Swap(&num1,&num2);
    printf("The values after swapping: \n");
    printf("num1: %d  num2: %d \n", num1, num2);
    
    return 0;
  }
