#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define FREE 0
#define LOCKED 1

int spinlock = FREE;
int rand_num = 0;

void *producer_write()
{
    while (1)
    {
        if (FREE == spinlock)
        {
            rand_num = rand();
            printf("producer write:\t%d\t", rand_num);
            spinlock = LOCKED;
        }
        sleep(1);
    }
}

void *consumer_read()
{
    while (1)
    {
        if (LOCKED == spinlock)
        {
            printf("consumer read:\t%d\n", rand_num);
            spinlock = FREE;
        }
    }
}

int main()
{
    pthread_t thread[2] = {0};

    pthread_create(&thread[0], NULL, producer_write, NULL);
    pthread_create(&thread[1], NULL, consumer_read, NULL);

    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);

    return 0;
}
