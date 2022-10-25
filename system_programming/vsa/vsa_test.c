#include<stdio.h>/*printf()*/
#include <stdlib.h>
#include "vsa.h"

#define number_of_test1 4

#ifndef NDEBUD
#define DEBUB_OFFSET 0
#else
#define DEBUB_OFFSET 0
#endif

static int InitTest(size_t pool_size, size_t expected_size, size_t unalignment)
{
    vsa_t * pool = NULL;
    void * mem = malloc(pool_size);
    char * runner = mem;
    runner += unalignment; 
    
    pool = Init(pool_size, runner);
    if(expected_size + DEBUB_OFFSET != *(size_t*)pool)
    {
        printf("FAIL InitTest expect: %lu actual: %lu \n", 
        expected_size, *(size_t*)pool);
        free(mem);

        return 1;
    } 
    free(mem);
    
    return 0;
}

void test1()
{
    size_t expected_size[number_of_test1] = {16, 16, 16, 1024};
    size_t pool_size[number_of_test1] = {24, 32, 32, 1032};
    size_t unalignment[number_of_test1] = {0, 7, 1, 0};
    int pass = 1;
    size_t i = 0;
    
    for(i = 0; i < number_of_test1; ++i)
    {
        if(0 != InitTest
        (pool_size[i] + DEBUB_OFFSET, expected_size[i], unalignment[i]))
        {
            pass = 0;
        }
    }
    if(pass)
    {
        printf("PASSED InitTest\n");
    }
    else
    {
        printf("FAILED InitTest\n");
    }
}

static int ChunckTest(size_t pool_size, size_t expected_size, size_t unalignment)
{
    vsa_t * pool = NULL;
    void * mem = malloc(pool_size);
    char * runner = mem;
    runner += unalignment; 
    
    pool = Init(pool_size, runner);

    if(expected_size != LargestChunkAvailable(pool))
    {
        printf("FAIL ChunckTest expect: %lu actual: %lu \n", 
        expected_size, LargestChunkAvailable(pool));
        free(mem);

        return 1;
    } 
    free(mem);
    
    return 0;
}

void test2()
{
    size_t expected_size[number_of_test1] = {8, 8, 8, 1016};
    size_t pool_size[number_of_test1] = {24, 32, 32, 1032};
    size_t unalignment[number_of_test1] = {0, 7, 1, 0};
    int pass = 1;
    size_t i = 0;
    
    for(i = 0; i < number_of_test1; ++i)
    {
        if(0 != ChunckTest
        (pool_size[i] + DEBUB_OFFSET, expected_size[i], unalignment[i]))
        {
            pass = 0;
        }
    }
    if(pass)
    {
        printf("PASSED ChunckTest\n");
    }
    else
    {
        printf("FAILED ChunckTest\n");
    }
}

static int AllocTest(size_t pool_size, size_t number_of_blocks)
{
    vsa_t * pool = NULL;
    size_t i = 0;
    size_t * tester = NULL;
    void * mem = malloc(pool_size);
    char * runner = mem;
    void * pool_arr = NULL;  
    pool_arr = malloc(number_of_blocks * sizeof(void*));
    
    pool = Init(pool_size, runner);
    
    tester = ((size_t*)pool);
	
    printf("############################\n");
    for(i = 0; i < pool_size/8 ; ++i)
    {
        printf("data: %lu address: %p\n", *tester, (void*)tester);
        ++tester;
    }
    printf("############################\n");
    
	
    for(i = 0; i < number_of_blocks; ++i)
    {
        *(((size_t*)pool_arr + i)) = (size_t)Alloc(pool, 8 * number_of_blocks);
		printf("return addrss: %p\n", (*((size_t*)pool_arr + i)));
    }
	
    
    *(size_t*)&tester = (*((size_t*)pool_arr));
    
    #ifndef NDEBUD
        
    #endif
    --tester;
    printf("############################\n");
    for(i = 0; i < pool_size/8; ++i)
    {
        printf("data: %lu address: %p\n", *tester, (void*)tester);
        ++tester;
    }
    printf("############################\n");
    
    /*
    for(i = 0; i < number_of_blocks; ++i)
    {
        Free((void*)*((size_t*)pool_arr + i));
    }
    */
    /*
    *(size_t*)&tester = (*((size_t*)pool_arr));
    --tester;
    printf("############################\n");
    for(i = 0; i < pool_size/8 ; ++i)
    {
        printf("data: %lu address: %p\n", *tester, (void*)tester);
        ++tester;
    }
    printf("############################\n");
    *
    LargestChunkAvailable(pool);
    *(size_t*)&tester = (*((size_t*)pool_arr));
    --tester;
    printf("############################\n");
    for(i = 0; i < pool_size/8 ; ++i)
    {
        printf("data: %lu address: %p\n", *tester, (void*)tester);
        ++tester;
    }
    printf("############################\n");
    */
   	/*
    if((pool_size - (16 + DEBUB_OFFSET)) != LargestChunkAvailable(pool))
    {
        printf("FAIL AllocTest expect: %lu actual: %lu \n", 
        (pool_size - (16 + DEBUB_OFFSET)), LargestChunkAvailable(pool));
        free(mem);
        free(pool_arr);
        return 1;
    } 
	*/
    free(mem);
    free(pool_arr);
    return 0;
}

void test3()
{
    size_t pool_size[number_of_test1] = {24 , 104, 1032, 512};
    size_t number_of_blocks[number_of_test1] = {1, 2, 3, 4};
    int pass = 1;
    size_t i = 0;
    
    for(i = 0; i < number_of_test1; ++i)
    {
        if(0 != AllocTest(pool_size[i] + DEBUB_OFFSET, number_of_blocks[i]))
        {
            pass = 0;
        }
    }
    if(pass)
    {
        printf("PASSED AllocTest\n");
    }
    else
    {
        printf("FAILED AllocTest\n");
    }
}
/*
void test2()
{
    size_t pool_size = 16;
    void * mem = malloc(pool_size);
    char * test_runner = mem;
    printf("assertion init TEST");    
    printf("%p\n", test_runner);
    ++test_runner;
    printf("%p\n", test_runner);
    pool = Init(pool_size, test_runner);    
}

void test3()
{
    size_t pool_size = 24;
    void * mem = malloc(pool_size);
    char * test_runner = mem;
    printf("assertion init TEST");    
    printf("%p\n", test_runner);
    ++test_runner;
    printf("%p\n", test_runner);
    pool = Init(pool_size, test_runner);    
}
*/

int main()
{
    /*test1();
    test2();*/
    test3();
    return 0;
}
