#include <stdio.h>

void to1(int arr[], size_t len)
{
    size_t right = len - 1;
    size_t left = 0;
    size_t i = 0;

    while (right != left)
    {
        if (1 == arr[left])
        {
            if (1 == arr[right])
            {
                --right;
            }
            else
            {
                arr[left] = 0;
                arr[right] = 1;
                ++left;
            }
        }
        else
        {
            ++left;
        }
    }

    for (i = 0; i < len; ++i)
    {
        printf("%d |", arr[i]);
    }
}

int main()
{
    int arr[] = {1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1};
    size_t len = sizeof(arr) / sizeof(int);
    size_t i = 0;

    for (i = 0; i < len; ++i)
    {
        printf("%d |", arr[i]);
    }
    printf("\nafter\n");
    to1(arr, len);

    return 0;
}
