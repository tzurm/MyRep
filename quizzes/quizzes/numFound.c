#include <stdio.h>
#include <string.h>

void IsNumInArray(int *array , size_t len, int num)
{
    size_t i = 0;
    char string[255] = {0};
    char num_char[4] = {0};
    
    sprintf(&num_char[strlen(num_char)], "%d,", num);
   
    for(i = 0; i < len; ++i)
    {
        sprintf(&string[strlen(string)], "%d,", array[i]);
    }
    printf("%s\n", string);
    (strstr (string,num_char)) ? printf("%d ,found\n", num) : printf("%d not found\n",num);

}

int main()
{
    int array[] = {1, 6, 2, 4, 4};
    size_t len =sizeof(array)/sizeof(int);
    int num1 = 7;
    int num2 = 4;
    IsNumInArray(array, len, num1);
    IsNumInArray(array, len, num2);

    return 0;
    
}
