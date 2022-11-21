#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void HandlerParent(int sig);
void HandlerChild(int sig);

static pid_t child;

int main()
{
    struct sigaction parent_action, child_action;

    parent_action.sa_handler = HandlerParent;
    parent_action.sa_flags = 0;
    sigemptyset(&parent_action.sa_mask);

    child_action.sa_handler = HandlerChild;
    child_action.sa_flags = 0;
    sigemptyset(&child_action.sa_mask);

    sigaction(SIGUSR1, &child_action, NULL);
    sigaction(SIGUSR2, &parent_action, NULL);

    child = fork();

    if (0 < child)
    {
        kill(child, SIGUSR1);
        wait(NULL);
    }
    while (1)
        ;

    return 0;
}

void HandlerParent(int sig)
{
    (void)sig;
    puts("pong");
    kill(child, SIGUSR1);
}

void HandlerChild(int sig)
{
    (void)sig;
    puts("received ping");
    kill(getppid(), SIGUSR2);
}
