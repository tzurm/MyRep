#define _POSIX_SOURCE

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

int child = 0;

void ChildHandler(int signum)
{
    child = 1;
}

int main()
{
    struct sigaction action_child;
    action_child.sa_handler = ChildHandler;

    /*refrencing SIGUSR1 to child handler*/
    sigaction(SIGUSR1, &action_child, NULL);

    /*sigfillset(&action_child.sa_mask);
    sigprocmask(SIG_UNBLOCK, &action_child.sa_mask, NULL);*/

    while (1)
    {
        while (!child)
        {
        
        }
        /*safe print*/
        write(1,"child\n", 6);
        child = 0;
        kill(getppid(), SIGUSR2);
    }

    return(0);
} 
