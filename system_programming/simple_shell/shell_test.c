#include <stdio.h>    /*printf*/
#include <string.h>   /*strcmp*/
#include <stdlib.h>   /*exit*/
#include <unistd.h>   /*fork*/
#include <sys/wait.h> /*pid_t*/
#include <errno.h>    /*errno mess*/
#include <sys/types.h>

#define MAX_LIMIT 60

static void red(void);
static void reset(void);
void System_Test(void);
void Fork_Test(void);
void SystemFork(void);

/*-----------------------------------MAIN-------------------------------------*/
int main(int argc, char *argv[])
{
    (void)argc;
    if (0 == strcmp(argv[1], "sys"))
    {
        System_Test();
    }
    else
    {
        Fork_Test();
    }
    return 0;
}

/*----------------------------------SYSTEM------------------------------------*/
void System_Test(void)
{
    char str[MAX_LIMIT] = {0};
    char char_exit[10] = "exit\n";
    red();
    printf("SystemBash@MyBash:~$ ");
    reset();
    fgets(str, 60, stdin);

    while (0 != strcmp(str, char_exit))
    {
        system(str);
        red();
        printf("SystemBash@MyBash:~$ ");
        reset();
        fgets(str, 60, stdin);
    }
    sleep(1);
    exit(0);
}
/*-----------------------------------FORK-------------------------------------*/
void parse(char *line, char **argv)
{
    while (*line != '\0')
    {
        while (*line == ' ' || *line == '\t' || *line == '\n')
        {
            *line++ = '\0';
        }
        *argv++ = line;
        while (*line != '\0' && *line != ' ' && *line != '\t' && *line != '\n')
        {
            ++line;
        }
    }
    *argv = '\0';
}

void execute(char **argv)
{
    pid_t pid;
    int status;

    if ((pid = fork()) < 0)
    {
        printf("ERROR: forking child process failed\n");
        exit(1);
    }
    else if (pid == 0)
    {
        if (execvp(*argv, argv) < 0)
        {
            printf("ERROR: exec failed\n");
            exit(1);
        }
    }
    else
    {
        while (wait(&status) != pid);
    }
}

void Fork_Test(void)
{
    char line[1024];
    char *argv[64];
    while (1)
    {
        red();
        printf("ForkBash@MyBash:~$ ");
        reset();
        scanf("%s", line);
        parse(line, argv);
        if (strcmp(argv[0], "exit") == 0)
        {
            sleep(1);
            exit(0);
        }
        execute(argv);
    }
}

/*----------------------------------------------------------------------------*/
static void red(void)
{
    printf("\033[1;31m");
}
static void reset(void)
{
    printf("\033[0m");
}

/*****************************************************************************
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
}*/