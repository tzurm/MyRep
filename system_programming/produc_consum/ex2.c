#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "sll.h"

#define FREE 0
#define LOCKED 1

int spinlock = FREE;
int rand_num = 0;

void *producer_write(sll_iter_t node)
{
    size_t sum_write=0;

    while (1)
    {
        if (spinlock == FREE)
        {
            rand_num = rand()% 50;
            printf("producer write:\t%d\t", rand_num);
            node = SLLInsertBefore(node, &rand_num); 
            spinlock = LOCKED;
            sum_write +=rand_num;
        }
    }
}

void *consumer_read()
{
    size_t sum_read=0;
    while (1)
    {
        if (spinlock == LOCKED)
        {
            printf("consumer read:\t%d\n", rand_num);
            spinlock = FREE;
            sum_read +=rand_num;
        }
        
    }
}

int main()
{
    pthread_t thread[2] = {0};

    sll_t *list = SLLCreate();
	sll_iter_t node = SLLBegin(list);

    pthread_create(&thread[0], NULL, producer_write, (*(void **)&node));
    pthread_create(&thread[1], NULL, consumer_read, (*(void **)&node));

    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);

    SLLDestroy(list);
    return 0;
}
