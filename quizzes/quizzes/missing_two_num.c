#include <stdio.h>

void FindTwoMissingNum(int arr[], size_t len)
{
    int sum = ((1 + len) * len) / 2;
    int sum_avg_1 = 0;
    int sum_avg_2 = 0;
    int i = 0;

    for (i = 0; i < len; ++i)
    {
        sum -= arr[i];
    }
  /*  printf("sum_two\tavg_two\n%d\t%d\n",sum, (sum / 2));*/
    /*find the num that smaller than avg*/

    for (i = 0; i < (sum / 2); ++i)
    {
        sum_avg_1 += i;
    }
    /*find the num that bigger than avg*/

    for (i = (sum / 2); i <= len; ++i)
    {
        sum_avg_2 += i;
    }

    for (i = 0; i <= len; ++i)
    {
        if (arr[i] < (sum / 2))
        {
            sum_avg_1 -= arr[i];
        }
        else
        {
            sum_avg_2 -= arr[i];
        }
    }
    printf("missing %d, %d\n", sum_avg_2, sum_avg_1);
}

int main()
{
    int i = 0;
    /*           0  1  2  3  4  5  6  7  8  9 */
  /*  int arr[] = {6, 1, 2, 8, 4, 7};*/
    int arr[] = {1, 6, 2, 9, 4, 7, 8};
    int len = 2 + sizeof(arr) / sizeof(arr[0]);
    int sum = ((1 + len) * len) / 2;

    for (i = 0; i < len - 2; ++i)
    {
        printf("%d | ", arr[i]);
    }
    printf("\nsum\tavg\n%d\t%d\n", sum, (sum / len));
    FindTwoMissingNum(arr, len);
    return 0;
}