#include <stdio.h>

void FindTwoMissingNum(int arr[], size_t len)
{
    int sum = ((1 + len) * len) / 2;
    int sum_avg_1 = 0;
    int sum_avg_2 = 0;
    size_t i = 0;
    float sum_of_missing = 0;

    for (i = 0; i < len - 2; ++i)
    {
        sum -= arr[i];
    }
    sum_of_missing = ((float)sum / 2);

    sum_avg_1 = ((1 + (int)sum_of_missing) * (int)sum_of_missing) / 2;
    sum_avg_2 = (((1 + len) * len) / 2) - sum_avg_1;

    for (i = 0; i < len - 2; ++i)
    {
        ((float)arr[i] <= sum_of_missing) ? (sum_avg_1 -= arr[i]) : (sum_avg_2 -= arr[i]);
    }
    printf("\nmissing %d, %d\n", sum_avg_2, sum_avg_1);
}

int main()
{
    int i = 0;
    int arr[] = {6, 3, 8, 1, 12, 4, 2, 7, 9, 10};
    int len = 2 + sizeof(arr) / sizeof(arr[0]);

    for (i = 0; i < len - 2; ++i)
    {
        printf("%d | ", arr[i]);
    }
    FindTwoMissingNum(arr, len);
    return 0;
}