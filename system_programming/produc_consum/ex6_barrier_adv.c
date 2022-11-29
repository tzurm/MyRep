#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>   /*  thread  */
#include <unistd.h>    /*  usleep  */
#include <semaphore.h> /*semaphore  */
#include <time.h>
#include "sll.h"
/* -------------------------------------------------------------------------*
 *  ex6 : A producer produces a "message" and waaits until all consumers    *
 *      consumed that message exactly 1 time                                *
 *      Use 1 condition variable, 1 mutex, 1 semaphore.                     *
 *      (1 producer n consumers).                                           *
 * -------------------------------------------------------------------------*
 * pseudo                                                                   *
 * Producer_wait signal from num of threads to be ready                     *
 * sent message and increase semaphore value                                *
 *                                                                          *
 * wait signal, received the message and when counter is get to num         *
 * of threads signal to producer to ACTION!                                 *
 * -------------------------------------------------------------------------*/

#define NUM_THREAD 10

sem_t semaphore;
pthread_mutex_t mutex;
pthread_cond_t cond;

size_t counter = 0;
int index_user = 1;
int rand_num = 0;
int i = 0;

void *Producer_write()
{
    while (1)
    {
        rand_num = rand();
        printf("Sent:\t%d\n", rand_num);

        pthread_mutex_lock(&mutex);
        counter = 0;
        i = 0;
        while (i < NUM_THREAD)
        {
            sem_post(&semaphore);
            i++;
        }
        pthread_cond_wait(&cond, &mutex);
        pthread_mutex_unlock(&mutex);
        
    }
    return NULL;
}

void *Consumer_read()
{
    while (1)
    {
        sem_wait(&semaphore);

        printf("User %ld Received %d\n", pthread_self(), rand_num);

        pthread_mutex_lock(&mutex);
        ++counter;
        if (counter == NUM_THREAD)
        {
            pthread_cond_broadcast(&cond);
        }
        else
        {
            pthread_cond_wait(&cond, &mutex);
        }
        pthread_mutex_unlock(&mutex);
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

   /* pthread_cond_broadcast(&cond);*/

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
