#include <stdio.h> /*   size_t */
#include "sort.h"

#define TRUE 1
#define FALSE 0

/* approved by Arie 6.11.22 */

static void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/* compare two elements                 *
 * swap if the left element is bigger   *
 * keep check next two elements         *
 * repeat len times                     */

void BubbleSort(int arr[], size_t len)
{
    size_t i = 0;
    size_t j = 0;

    for (i = 0; i < len - 1; ++i)
    {
        /* compare two elements */
        for (j = 0; j < len - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

/* find the minum in array      *
 * place him to be first(swap)  *
 * repeat and place in order    */
void SelectionSort(int arr[], size_t len)
{
    size_t i = 0;
    size_t j = 0;
    size_t min_index = 0;

    for (i = 0; i < len - 1; ++i)
    {
        min_index = i;

        for (j = i + 1; j < len; ++j)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (i != min_index)
        {
            swap(&arr[min_index], &arr[i]);
        }
    }
}

/*
 * mark first element as sorted
 * set the next element as 'key' to fix him in place
 * Compae key with each element on the left of it until an element smaller
 * fix him in place
 * repeat
 */
void InsertionSort(int arr[], int len)
{
    int i = 0;
    int j = 0;
    int current = 0;

    for (i = 1; i < len; ++i)
    {
        current = arr[i];
        j = i - 1;

        /*move back to place the current in right place*/
        while (current < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = current;
    }
}
