#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> /*	size_t	*/
#include <assert.h>

int RecBinarySearch(int arr[], size_t from, size_t to, int value)
{
    if (to >= from)
    {
        int mid = from + (to - from) / 2;
        if (arr[mid] == value)
        {
            return mid;
        }
        if (arr[mid] > value)
        {

            return RecBinarySearch(arr, from, mid - 1, value);
        }
        return RecBinarySearch(arr, mid + 1, to, value);
    }
    return -1;
}

int *IterBinarySearch(int *arr, int *param, size_t len)
{
    size_t right_index = len - 1;
    size_t left_index = 0;
    size_t middle_index = len / 2;

    assert(NULL != arr);
    assert(NULL != param);
    while (1 != len)
    {
        if (*param > arr[middle_index])
        {
            left_index = middle_index;
            middle_index = (right_index + left_index + 1) / 2;
        }
        if (*param < arr[middle_index])
        {
            right_index = middle_index;
            middle_index = (right_index + left_index) / 2;
        }
        if (*param == arr[middle_index])
        {
            return param;
        }
        len /= 2;
    }
    return NULL;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 11, 15, 16, 17, 18, 19, 20, 21, 23, 100};
    size_t len = sizeof(arr) / sizeof(arr[0]);

    printf("------------------RecBinarySearch----------------------------\n");
    if (-1 == RecBinarySearch(arr, 0, len - 1, 11))
    {
        printf("not found\n");
    }
    printf("%d Found in index: %d\n", arr[(len-1)/2], RecBinarySearch(arr, 0, len - 1, arr[(len-1)/2]));

    printf("------------------IterBinarySearch---------------------------\n");
    printf("Found : %d\n", *(IterBinarySearch(arr, &arr[6], len)));

    return 0;
}
