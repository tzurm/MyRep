#include <stdio.h>
#include "pointers1.h"
#include "pointers1.c"


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
    
    
    int n;
    printf("Enter the size of array ");
    scanf("%d",&n);
    int a[n];
    int b[n];
    printf("Enter the array elements ");
    for(int i=0;i<n;i++)
       scanf("%d",&a[i]);
    printf("\nThe original array: \n");
    printArray(a,n);
    Copy(a,b,n);
    printf("\nThe copied array: \n");
    printArray(b,n);
    
    return 0;
  }
