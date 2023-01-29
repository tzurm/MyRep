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
    int allow = 0;

    printf("Enter your username, please: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;

    if (IsAllowedUser(username))
    {
        allow = 1;
    }

    if (allow)
    {
        PrivilegedAction();
    }

    return 0;
}
/*
gcc *.c -o tt -fno-stack-protector
*/
