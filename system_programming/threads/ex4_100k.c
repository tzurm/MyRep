#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define SIZE_OF_THREADS 10
#define NUM 10000000

int Right_Sum_Div(int number);

void *SumDiv(void *num)
{
    int number = *(int *)&num;
    int sum_of_divisors = 0;
    int i = 0;

    for (i = number - 99; i <= number; ++i)
    {
        if (0 == NUM % i)
        {
            printf("%d, ", i);
            sum_of_divisors += i;
        }
    }
    
    return (*(void **)&sum_of_divisors);

}

int main()
{
    pthread_t thread[SIZE_OF_THREADS] = {0};
    void *return_sum = NULL;
    int sum = 0;
    int i = 0;
    int j = 0;

    for (i = 100; i <= NUM + 100; i += 100)
    {
        pthread_create(&thread[j], NULL, SumDiv, (*(void **)&i));
        pthread_join(thread[j], &return_sum);
        sum += *(int *)&return_sum;
    }

    printf("\nSum of dividors %d\n", sum);
    printf("Right answer\t%d\n", Right_Sum_Div(NUM));
    ++j;

    return 0;
}

int Right_Sum_Div(int number)
{
    int i = 0;
    int sum_of_divisors = 0;
    for (i = 1; i <= number; ++i)
    {
        if (0 == number % i)
        {
            sum_of_divisors += i;
        }
    }
    return sum_of_divisors;
}