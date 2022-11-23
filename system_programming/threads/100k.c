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

int main(int argc, char *argv[])
{
    pthread_t thread;
    (void)argv;
    (void)argc;
    pthread_mutex_init(&mutex, NULL);

    for (i = 0; i < SIZE; ++i)
    {
        if (pthread_create(&thread, NULL, routine, NULL) != 0)
        {
            perror("Failed to create thread");
            return 1;
        }
        pthread_join(thread, NULL);
    }

    pthread_mutex_destroy(&mutex);

    for (i = 0; i < SIZE; ++i)
    {
        printf("%d \n", arr[i]);
    }

    return 0;
}