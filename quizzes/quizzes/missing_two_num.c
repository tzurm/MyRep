#include <stdio.h>

void FindTwoMissingNum(int arr[], size_t len)
{
    int sum = ((1 + len) * len) / 2;
    int sum_avg_1 = 0;
    int sum_avg_2 = 0;
    int i = 0;
    float sum_of_missing = 0;

    for (i = 0; i < len - 2; ++i)
    {
        sum -= arr[i];
    }
    sum_of_missing = ((float)sum / 2);
   /* printf("sum_two\tavg_two\n%d\t%.2f\n", sum, sum_of_missing);*/
    /*find the num that smaller than avg*/

    sum_avg_1 = ((1 + (int)sum_of_missing) * (int)sum_of_missing) / 2;
    sum_avg_2 = (((1 + len) * len) / 2) -  sum_avg_1;

    for (i = 0; i < len - 2; ++i)
    {
        if ((float)arr[i] <= sum_of_missing)
        {
            sum_avg_1 -= arr[i];
        }
        else
        {
            sum_avg_2 -= arr[i];
        }
    }
    printf("\nmissing %d, %d\n", sum_avg_2, sum_avg_1);
}




int main()
{
    int i = 0;
    /*           0  1  2  3  4  5  6  7  8  9 */
    int arr[] = {6, 3, 8, 1,12,4, 2, 7, 9, 10};
    /*  int arr[] = {1, 6, 2,9, 4, 7, 8};*/
    int len = 2 + sizeof(arr) / sizeof(arr[0]);
    int sum = ((1 + len) * len) / 2;
  /*  printf("len %d\n", len);*/
    for (i = 0; i < len - 2; ++i)
    {
        printf("%d | ", arr[i]);
    }
   /* printf("\nsum\tavg\n%d\t%d\n", sum, (sum / len));*/
    FindTwoMissingNum(arr, len);
    return 0;
}