#include <stdio.h>     /*printf()*/
#include <string.h>    /*memset*/
#include <sys/types.h> /*size_t*/

#include "ext2.h" /*header file*/

#define SMALL 64
#define BIG 44000
#define EXIT "exit"

int main(int argc, char const *argv[])
{
    int inode = 0;
    int chmod_num = 0;
    if (3 != argc)
    {
        printf("invalid input!\n");
        return -1;
    }

    inode = OpenFile(argv[1], argv[2]);

    printf("Enter chmod num:\n");
    scanf("%d", &chmod_num);
    MyChmod(inode, chmod_num);

    return 0;
}
