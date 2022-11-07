#include <stdio.h>  /*  printf			*/
#include <stdlib.h> /*  random,qsort	*/
#include <time.h>   /*  time			*/
#include "sort.h"

#define LEN 20000

static int IsSorted(int arr[], size_t len)
{
    size_t i = 0;

    for (i = 0; i < len; ++i)
    {
        if (arr[i + 1] < arr[i])
        {
            return 1;
        }
        ++i;
    }
    return 0;
}

static int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

static void InitArrayRandom(int arr[], size_t len)
{
    size_t i = 0;

    for (i = 0; i < len; ++i)
    {
        arr[i] = rand() % 100;
    }
}

static void PrintArray(int arr[], size_t len)
{
    size_t i = 0;

    printf("| ");
    for (i = 0; i < len; ++i)
    {
        printf("%d | ", arr[i]);
    }
    printf("\n");
}
static void PrintTimes(clock_t arr[], size_t len)
{
    size_t i = 0;

    printf("bubble      |selection   |insert      |quik \n");
    printf("---------------------------------------------\n");
    for (i = 0; i < len; ++i)
    {
        printf("%.3f       |", arr[i] * 1000.0 / CLOCKS_PER_SEC);
    }
    printf("\n");
}

int main()
{
    int arr[LEN] = {0};
    clock_t elapsed[4] = {0};
    clock_t start;

    printf("\n--------------Original---------------------------------------\n");
    InitArrayRandom(arr, LEN);
    PrintArray(arr, LEN);

    printf("-------------BubbleSort--------------------------------------\n");
    start = clock();
    BubbleSort(arr, LEN);
    elapsed[0] = clock() - start;
    PrintArray(arr, LEN);
    printf("-------------------------------------------------------------\n");
    0 == IsSorted(arr, LEN) ? printf("Is sorted\n") : printf("Not Sorted\n");

    printf("\n------------SelectionSort------------------------------------\n");
    InitArrayRandom(arr, LEN);
    PrintArray(arr, LEN);
    start = clock();
    SelectionSort(arr, LEN);
    elapsed[1] = clock() - start;
    PrintArray(arr, LEN);
    printf("-------------------------------------------------------------\n");
    0 == IsSorted(arr, LEN) ? printf("Is sorted\n") : printf("Not Sorted\n");

    printf("\n------------InsertionSort------------------------------------\n");
    InitArrayRandom(arr, LEN);
    PrintArray(arr, LEN);
    start = clock();
    InsertionSort(arr, LEN);
    elapsed[2] = clock() - start;
    PrintArray(arr, LEN);
    printf("-------------------------------------------------------------\n");
    0 == IsSorted(arr, LEN) ? printf("Is sorted\n") : printf("Not Sorted\n");

    printf("\n------------QuikSort-----------------------------------------\n");
    InitArrayRandom(arr, LEN);
    PrintArray(arr, LEN);
    start = clock();
    qsort(arr, LEN, sizeof(int), cmpfunc);
    elapsed[3] = clock() - start;
    PrintArray(arr, LEN);
    printf("-------------------------------------------------------------\n");
    0 == IsSorted(arr, LEN) ? printf("Is sorted\n\n") : printf("Not Sorted\n\n");

    PrintTimes(elapsed, 4);

    return 0;
}
