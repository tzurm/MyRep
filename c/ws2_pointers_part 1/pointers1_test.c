#include <stdio.h>
#include "pointers1.h"
#include "pointers1.c"


int main() 
{

	/* Copied Array */
	int arr1[5]={0,1,2,3,4};
	int arrcopy[5];
	int n=5;
	 
    size_t num1 = 9;				/* Size_t swap value */
    size_t num2 = 5;				/* Size_t swap value */
    size_t *p_num1 = &num1;			/* Size_t swap value */
    size_t *p_num2 = &num2;			/* Size_t swap value */
    
    /* Swap */
    int a=5,b=9;
    printf("***********  Swap  *********** \n");
    printf("The values before swapping: \n");
    printf("num1: %d  num2: %d \n", a, b);
    Swap(&a,&b);
    printf("The values after swapping: \n");
    printf("num1: %d  num2: %d \n", a, b);
    
    /* Copied Array */
    printf("***********  Copied Array  *********** \n");
    printf("\nThe original array: \n");
    printArray(arr1,n);
    Copy(arr1,arrcopy,n);
    printf("\nThe copied array: \n");
    printArray(arrcopy,n);
    
    
    /* Size_t swap value */
    printf("\n***********  swap value  *********** \n");
    printf("BEFORE: num1: %lu  | num2: %lu \n",num1, num2);
    Swap_Size_t(&num1 ,&num2 );
    printf("AFTER:  num1: %lu  | num2: %lu\n \n",num1, num2);
 
    printf("*********** swap address pointers *************\n");
    printf("BEFORE:\naddress of ptr num1: %lu \naddress of ptr num2: %lu\n",p_num1,p_num2 );
    printf("BEFORE:  num1: %lu  | num2: %lu\n \n",num1, num2);
    Swap_Ptr(&p_num1,&p_num2);
    printf("AFTER:\naddress of ptr num1: %lu \naddress of ptr num2: %lu\n",p_num1,p_num2  );
    printf("AFTER:  num1: %lu  | num2: %lu\n \n",num1, num2);
    
    return 0;
  }
