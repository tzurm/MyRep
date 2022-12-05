#include <stdio.h>      /*printf()*/
#include <string.h>     /*memset*/
#include <sys/types.h>  /*size_t*/

#include "ext2.h"/*header file*/

#define SMALL 64
#define BIG   44000
#define EXIT "exit"

int main(int argc, char const *argv[])
{
    int inode = 0;
    size_t i = 0;
    char small_buffer[SMALL] = {0};
    char big_buffer[BIG] = {0};
    char * runner = NULL;

    if (3 != argc)
    {
        printf("invalid input!\n");
        return -1;
    }
    

    inode = OpenFile(argv[1], argv[2]);
    printf("%d\n", inode);

    runner = ReadBytes(inode, small_buffer, SMALL);

    for (i = 0; i < SMALL; i++)
    {
        printf("%c", *runner);
        ++runner;
    }
    printf("\n");
    printf("\n");

    runner = Read(inode, big_buffer);

    for (i = 0; i < 41000; i++)
    {
        printf("%c", *runner);
        ++runner;
    }
    printf("\n");

    return 0;
}

