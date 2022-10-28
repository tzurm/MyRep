
#include <stdio.h>

int IsSumFound( int *arr, int len ,int sum)
{
    while( 0 != len-1 )
    {
        if(sum == *arr+*(arr+len-1))
        {
            printf("%d\n" , *arr);
            printf("%d\n" ,*(arr+len-1));
            return 0;
        }
        if(sum <  *arr+*(arr+len-1))
        {
            --len;
            
        }
        else
        {

           ++arr;
        }
    }
    return 1;
}


int main() {
    int arr[5] = {8, 9, 12, 17, 29};
    int sum=20;
    if (0 == IsSumFound(arr,5,sum) )
        printf("found");
    else 
         printf("isn't found");
    return 0;
}