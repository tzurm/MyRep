#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#define SIZE 100000

int arr[SIZE] = {0};
static int i = 0;

pthread_mutex_t mutex;

void *routine()
{
    pthread_mutex_lock(&mutex);
    arr[i] = i;
    pthread_mutex_unlock(&mutex);
}

int main()
{
    pthread_t thread;

    int status = 0;
    pthread_mutex_init(&mutex, NULL);

    for (i = 0; i < SIZE; ++i)
    {
        status = pthread_create(&thread, NULL, routine, NULL);
        while (0 != status)
        {
            perror("Failed to create thread");
            pthread_create(&thread, NULL, routine, NULL);
        }
        pthread_join(thread, NULL);
        /*add join to avoid "Faild to create thread: cannot allocate memory"*/
    }

    pthread_mutex_destroy(&mutex);

    for (i = 0; i < SIZE; ++i)
    {
        if (arr[i] == i)
        {
            printf("%d \n", arr[i]);
        }
    }

    return 0;
}
