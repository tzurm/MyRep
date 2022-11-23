#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#define SIZE 100



int mails = 0;
pthread_mutex_t mutex;
size_t i = 0;

void *routine()
{
    for (i = 0; i < SIZE; ++i)
    {
        pthread_mutex_lock(&mutex);
        ++mails;
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char *argv[])
{
    pthread_t arr[SIZE];
    int i;
    pthread_mutex_init(&mutex, NULL);
    for (i = 0; i < SIZE; ++i)
    {
        if (pthread_create(arr + i, NULL, &routine, NULL) != 0)
        {
            perror("Failed to create thread");
            return 1;
        }
        printf("Thread %d has started\n", i);
    }

    for (i = 0; i < SIZE; ++i)
    {
        if (pthread_join(arr[i], NULL) != 0)
        {

            return 2;
        }
        printf("Thread %d has finished execution\n", i);
    }
    pthread_mutex_destroy(&mutex);
    printf("Number of mails: %d\n", mails);
    return 0;
}