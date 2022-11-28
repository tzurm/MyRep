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

#define NUM_THREAD 5

pthread_mutex_t mutex;
sem_t semaphore;
int index_user = 1;
int rand_num = 0;
pthread_cond_t cond;

void *Producer_write()
{
    rand_num = rand();
    printf("Sent:\t%d\n", rand_num);
    sleep(1);
    pthread_cond_broadcast(&cond);
    return NULL;
}

void *Consumer_read()
{
 /*  MEMORY MAP
    int pop1 = 11;
    int pop0 = 10;
    int const pop2 = 11;
    int pop3;
    int static pop4 = 11;
    int static pop5;*/
    
    sem_wait(&semaphore);
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&cond, &mutex);
    printf("User %d Received %d\n", index_user, rand_num);
    ++index_user;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main()
{
    size_t i = 0;
    pthread_t producers;
    pthread_t consumers[NUM_THREAD] = {0};

    sem_init(&semaphore, 0, NUM_THREAD);
    pthread_cond_init(&cond, NULL);
    pthread_mutex_init(&mutex, NULL);
    /*need check if fail*/

    pthread_create(&producers, NULL, Producer_write, NULL);

    for (i = 0; i < NUM_THREAD; ++i)
    {
        pthread_create(&consumers[i], NULL, Consumer_read, NULL);
        /*need check if fail*/
    }
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
