#include <stdio.h>
#include <stddef.h>


long *SumIntPairToLong(int ints[] , size_t len)
{
    size_t i = 0;
    for (i = 0 ; i < len ; i += 2)
    {
        *(long*)&ints[i] = ints[i] + ints[i + 1];
    }
    return (long*)ints;
}



int main() 
{
    int ints[] = {1,6,456,-3,8,20};
    long *longs = NULL;
    size_t i = 0;

    longs = SumIntPairToLong(ints, 6);

    for(i = 0; i < 6 ; ++i)
    {
        printf("%ld |", longs[i]);
    }
    printf("\n");
    return 0;
}