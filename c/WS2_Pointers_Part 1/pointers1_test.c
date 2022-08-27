#include <stdio.h>
#include "pointers1.h"
#include "pointers1.c"


int main() 
{

    /* Swap */
    int a=5,b=9;
    printf(" ***********  Swap  *********** \n");
    printf("The values before swapping: \n");
    printf("num1: %d  num2: %d \n", a, b);
    Swap(&a,&b);
    printf("The values after swapping: \n");
    printf("num1: %d  num2: %d \n", a, b);
    
    /* Copied Array */
    printf(" ***********  Copied Array  *********** \n");
    int n;
    printf("Enter the size of array ");
    scanf("%d",&n);
    int arr1[n];
    int arr2[n];
    printf("Enter the array elements ");
    for(int i=0;i<n;i++)
       scanf("%d",&arr1[i]);
    printf("\nThe original array: \n");
    printArray(arr1,n);
    Copy(arr1,arr2,n);
    printf("\nThe copied array: \n");
    printArray(arr2,n);
    
    /* StrLen */
    printf(" ***********  StrLen  *********** \n");
    char str[300];
    int length;
    printf("Enter str \n");
    scanf("%s", str);
    length=StrLen(str);
    printf("Length of string: = %u \n",length);
     
    
    /* StrCmp */
    printf(" ***********  StrCmp  *********** \n");
    char str1[300];
    char str2[300];
    int cmp;
    printf("Enter str1 \n");
    scanf("%s", str1);
    printf("Enter str2 \n");
    scanf("%s", str2);
    cmp=StrCmp(str1,str2);
    printf("print 0 if same = %u \n",cmp);
    
    /* Size_t swap value */
    size_t num1 = 9;
    size_t num2 = 5;
    size_t *p_num1 = &num1;
    size_t *p_num2 = &num2;
    printf(" ***********  swap value  *********** \n");
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
