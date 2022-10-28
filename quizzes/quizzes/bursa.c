
#include <stdio.h>

int Bursa(int* arr, int len)

{
    int i=0, max=0, min=0, max_value=0, difference=0;
    
   
    for(i = len-1; i >= 0; --i)
    {
        if(arr[i] < min)
        {
            min = arr[i];
        }
        
        if(arr[i] > max){
            max = arr[i];
            min = max;
        }
        difference = max - min;
        
        if(difference > max_value)
        {
            max_value = difference;
        }
    }
    return max_value;
}

int main() 
{
    int arr[8] = {6, 10, 3, 5, 2 ,4, 19, 22};       
    printf("Highest profit: %d\n" , Bursa(arr,8));

    return 0;
}
