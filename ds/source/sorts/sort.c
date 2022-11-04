#include <stdio.h>

#include "sort.h"
#define TRUE 1
#define FALSE 0

static void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(int arr[], int len)
{
    int i = 0;
    int j = 0;
    int swapped = TRUE;

    for (i = 0; i < len - 1; ++i)
    {
        swapped = FALSE;
        for (j = 0; j < len - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = TRUE;
            }
        }

        if (swapped == FALSE)
            break;
    }
}

void SelectionSort(int arr[], int len)
{
    int i = 0;
    int j = 0;
    int min_idx = 0;

    for (i = 0; i < len - 1; ++i)
    {
        min_idx = i;
        for (j = i + 1; j < len; ++j)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        if (min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

void InsertionSort(int arr[], int len)
{
    int i = 0;
    int j = 0;
    int key = 0;

    for (i = 1; i < len; ++i)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}