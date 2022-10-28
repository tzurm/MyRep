#include <stdio.h>

/*  count bits , because we send num&num-1 we count pair of two*/
unsigned int CountBits(unsigned int num) {
    unsigned int i;
    for (i = 0; num; ++i)
       num &= num - 1;
    return i;
}

void Swap(int* num1, int* num2)
{
    if (num1 == num2) 
        return;
    *num1 = *num1 + *num2;
    *num2 = *num1 - *num2;
    *num1 = *num1 - *num2;
}

int main() {
    unsigned int num=255;
    int num1 = 10 , num2 = 5;
    
    printf("%u\n", CountBits(num&(num-1)));
    
    Swap(&num1, &num2);
    printf("Before swap: num1 = %d , num2 = %d\n",num1, num2);
    printf("After swap: num1 = %d , num2 = %d",num1, num2);
    return 0;

}


