#include <stdio.h>    /*printf*/
#include <string.h>   /*strcmp*/
#include <stdlib.h>   /*exit*/
#include <unistd.h>   /*fork*/
#include <sys/wait.h> /*pid_t*/
#include <errno.h>    /*errno mess*/

#define MAX_LIMIT 20

static void red(void);
static void reset(void);
void System_Test(void);
void Fork_Test(void);
void SystemFork(void);

int main()
{
    Fork_Test();
    printf("-----------My_Bash---------------\n");
    /*
    SystemFork();
*/
    return 0;
}
void SystemFork(void)
{
    char ch;
    printf("-\tclick 'f' for fork\t-\n-\tclick 's' for system\t-");
    printf("\n----------------------------------\n");
    ch = getchar();
    if (ch == 's')
    {
        System_Test();
    }
    if ('f' == ch)
    {
        Fork_Test();
    }
}
void System_Test(void)
{
    char str[MAX_LIMIT] = {0};
    char char_exit[10] = "exit";
    red();
    printf("SystemBash@MyBash:~$ ");
    reset();
    scanf("%s", str);

    while (0 != strcmp(str, char_exit))
    {
        system(str);
        red();
        printf("SystemBash@MyBash:~$ ");
        reset();
        scanf("%s", str);
    }
    sleep(2);
    exit(0);
}

void Fork_Test(void)
{
    pid_t pid;

    pid = fork();
    if (pid < 0)
    {
        err(1, "fork failed");
    }
    else if (0 == pid)
    {
       
        printf("sd");
    }
}

static void red(void)
{
    printf("\033[1;31m");
}
static void reset(void)
{
    printf("\033[0m");
}