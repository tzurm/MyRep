#include <stdlib.h>
#include <stdio.h>
#include <pthread.h> /*  thread  */
#include <unistd.h>  /*  usleep  */

#include "sll.h"

#define NUM_THREAD 10
#define NUM_NODES 10000

pthread_mutex_t mutex;
size_t num_nodes_arr[NUM_NODES] = {0};
size_t num_nodes = 0;
size_t sum = 0;

void InitArr(void)
{
    size_t i = 0;
    for (i = 0; i < NUM_NODES; ++i)
    {
        num_nodes_arr[i] = i;
    }
}

void *Producer_write(void *ptr)
{
    sll_t *linked_list = (sll_t *)ptr;
    while (1)
    {
        pthread_mutex_lock(&mutex);
        if (num_nodes >= NUM_NODES)
        {
            pthread_mutex_unlock(&mutex);
            return ptr;
        }
        ++num_nodes;
        SLLInsertBefore(SLLEnd(linked_list), &num_nodes_arr[num_nodes]);
        pthread_mutex_unlock(&mutex);
        /* usleep(10000);*/
    }
    return ptr;
}

void *Consumer_read(void *ptr)
{
    sll_iter_t iterator = NULL;
    sll_t *linked_list = (sll_t *)ptr;

    while (1) /*busy wait*/
    {
        pthread_mutex_lock(&mutex);
        if (1 == SLLCount(linked_list))
        {
            pthread_mutex_unlock(&mutex);
        }
        else
        {
            iterator = SLLBegin(linked_list);
            sum += *(size_t *)SLLGetData(iterator);
            SLLRemove(iterator);
            printf("%lu\n", sum);
            pthread_mutex_unlock(&mutex);
        }
    }
    return ptr;
}

int main()
{
    size_t i = 0;
    sll_t *linked_list = NULL;
    pthread_t producers[NUM_THREAD] = {0};
    pthread_t consumers[NUM_THREAD] = {0};

    InitArr();
    linked_list = SLLCreate();
    pthread_mutex_init(&mutex, NULL);

    for (i = 0; i < NUM_THREAD; ++i)
    {
        if (0 != pthread_create(&producers[i], NULL, Producer_write, linked_list))
        {
            perror("Failed to create thread");
        }
        if (0 != pthread_create(&consumers[i], NULL, Consumer_read, linked_list))
        {
            perror("Failed to create thread");
        }
    }

    for (i = 0; i < NUM_THREAD; ++i)
    {
        if (0 != pthread_join(consumers[i], NULL))
        {
            perror("Failed to join thread");
        }
    }

    pthread_mutex_destroy(&mutex);
    SLLDestroy(linked_list);
    return 0;
}
