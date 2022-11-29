#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>   /*  thread  */
#include <unistd.h>    /*  usleep  */
#include <semaphore.h> /*semaphore  */
#include <time.h>
#include "sll.h"
/*
 *  ex6 : A producer produces a "message" and waaits until all consumers    *
 *      consumed that message exactly 1 time                                *
 *      Use 1 condition variable, 1 mutex, 1 semaphore.                     *
 *      (1 producer n consumers).                                           *
 *                                                                          */

#define NUM_THREAD 3

pthread_mutex_t mutex;
sem_t semaphore;
int index_user = 1;
int rand_num = 0;
pthread_cond_t cond;
size_t counter = 0;
int i = 0;

void *Producer_write()
{
    i = NUM_THREAD;
    while (1)
    {
        while (counter < NUM_THREAD)
        {
            pthread_cond_wait(&cond, &mutex);
        }
        counter = 0;

        rand_num = rand();
        printf("Sent:\t%d\n", rand_num);

        /* reset post to start recvied message*/
        i = 0;
        while (i < NUM_THREAD)
        {
            sem_post(&semaphore);
            i++;
        }
    }
    return NULL;
}

void *Consumer_read()
{
    while (1)
    {
        sem_wait(&semaphore);
        pthread_mutex_lock(&mutex);

        printf("User %ld Received %d\n", counter + 1, rand_num);
        ++index_user;
        ++counter;
        /* cancel infinty loop */ /*
           if(index_user>90)
           {
               exit(1);
           }
   */
        pthread_mutex_unlock(&mutex);
        if (counter == NUM_THREAD)
        {
            pthread_cond_signal(&cond);
        }
    }
    return NULL;
}

int main()
{
    size_t i = 0;
    pthread_t producers;
    pthread_t consumers[NUM_THREAD] = {0};

    sem_init(&semaphore, 0, 0);
    pthread_cond_init(&cond, NULL);
    pthread_mutex_init(&mutex, NULL);
    /*need check if fail*/

    pthread_create(&producers, NULL, Producer_write, NULL);

    for (i = 0; i < NUM_THREAD; ++i)
    {
        pthread_create(&consumers[i], NULL, Consumer_read, NULL);
        /*need check if fail*/
    }
    counter = NUM_THREAD;
    pthread_cond_signal(&cond);

    pthread_join(producers, NULL);

    for (i = 0; i < NUM_THREAD; ++i)
    {
        pthread_join(consumers[i], NULL);
        /*need check if fail*/
    }

    sem_destroy(&semaphore);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;
}
