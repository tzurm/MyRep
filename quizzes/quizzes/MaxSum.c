#include <stdio.h>

int MaxSum(int a[],int n ,int *first, int* last)
{
  int i,j,k;
  int sum,maxSum = 0;
  for(i=0; i<n; i++)
  {
      
    for(j=i; j<n; j++)
    {
         
      sum = 0;
      for(k = i ; k < j; k++)
      {
        sum += a[k];
       
      }
      if(sum > maxSum)
        maxSum = sum;
    }
   }
   printf("\nlast index : %d" , last);
   return maxSum;
}

int main()
{
    int i;
    int arr1[] = {2, -5, 1, 2, 3, 5,1};
    int *first_index=NULL;
    int *last_index=NULL;
    int len = sizeof(arr1)/sizeof(arr1[0]);
	for(i = 0; i < len ; ++i)
	{
    	printf("%d | ", arr1[i]);
    } 
    printf("\nLargest sum : %d \n", MaxSum(arr1, len ,first_index,last_index));
    printf("First index: %d\nLast index %d" ,first_index ,last_index);
    return 0;
}
