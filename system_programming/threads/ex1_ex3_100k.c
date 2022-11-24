#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#define SIZE 100
#define TRUE 0
#define FALSE 1

void ElementsInPlace(int arr[]);

int arr[SIZE] = {0};
static int index = 0;
pthread_t thread[SIZE] = {0};

pthread_mutex_t mutex;

void *Routine()
{
    pthread_mutex_lock(&mutex);

    arr[index] = index;
    ++index;
    printf("i = %d\tID: %ld\n", index, pthread_self());

    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main()
{

    int status = 0;
    int i = 0;

    pthread_mutex_init(&mutex, NULL);

    for (i = 0; i < SIZE; ++i)
    {

        status = pthread_create(&thread[i], NULL, Routine, NULL);

        while (0 != status)
        {
            perror("Failed to create thread");
            pthread_create(&thread[i], NULL, Routine, NULL);
        }
    
    }
    for (i = 0; i < SIZE; ++i)
    {
        if (0 != pthread_join(thread[i], NULL))
        {
            printf("fail pthread_join\n");
        }
        /*
         if (0 != pthread_detach(thread[i]))
         {
             printf("fail pthread_detach\n");
         }
        */

        /*
        add join to avoid "Faild to create thread: cannot allocate memory"
        and to keep return value
        */
    }
    


    pthread_mutex_destroy(&mutex);

    ElementsInPlace(arr);

    return 0;
}

/* Simple Sum of Divisors algorithm */
/*

*/

void ElementsInPlace(int arr[])
{
    int is_equal_to_index = TRUE;
    int i = 0;

    for (i = 0; i < SIZE; ++i)
    {
        /*  printf("index: %d\tvalue: %d\n", i, arr[i]);*/
        if (arr[i] != i)
        {
            printf("index: %d\tvalue: %d\n", i, arr[i]);
            is_equal_to_index = FALSE;
        }
    }
    (TRUE == is_equal_to_index) ? printf("All elements equal to index\n") : printf("not equal\n");
}