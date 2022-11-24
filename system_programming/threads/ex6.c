#include <stdio.h>
#include <omp.h>/*pragma omp parallel for*/

int Sum_Div(int number)
{
    int i = 0;
    int sum_of_divisors = 0;


    #pragma omp parallel for
    for (i = 1; i <= number; ++i)
    {
        if (0 == number % i)
        {
            sum_of_divisors += i;
        }
    }
    return sum_of_divisors;
}

int main()
{
    int num = 10000000;
    printf("sum of div %d\n", Sum_Div(num));

    return 0;
}