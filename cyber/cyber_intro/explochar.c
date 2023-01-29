#include <stdio.h>
#include <string.h>

int IsAllowedUser(char *username)
{
    char *str1 = "tzur";
    return !(strcmp(str1, username));
}

void PrivilegedAction()
{
    printf("you are allowed\n");
}

int main()
{
    char username[8];
    char allow = '0';

    printf("Enter your username, please: ");
    gets(username);

    if (IsAllowedUser(username))
    {
        allow = 'z';
    }

    if (allow == 'z')
    {
        PrivilegedAction();
    }

    return 0;
}
/*
gcc *.c -o tt -fno-stack-protector
*/

/*
-fstdarg-opt
           Optimize the prologue of variadic argument functions with respect
           to usage of those arguments.

           NOTE: In Ubuntu 14.10 and later versions,
           -fstack-protector-strong is enabled by default for C, C++, ObjC,
           ObjC++, if none of -fno-stack-protector, -nostdlib, nor
           -ffreestanding are found.
*/
