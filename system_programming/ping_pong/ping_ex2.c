#define _POSIX_SOURCE

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>

int parent = 0;

void ParentHandler(int signum)
{
    parent = 1;
}

int main()
{
    pid_t pid = 0;
    struct sigaction action_parent;
    char *argv[1] = {0};

    action_parent.sa_handler = ParentHandler;
    /*refrencing SIGUSR2 to parent handler*/
    sigaction(SIGUSR2, &action_parent, NULL);

    pid = fork();
    if (pid < 0) 
    { 
   	    perror("Fork failed");
    }

    if (pid == 0) 
    {
        execv("./runchild", argv);
    }
    sleep(1);

    /*sigfillset(&action_parent.sa_mask);
    sigprocmask(SIG_UNBLOCK, &action_parent.sa_mask, NULL);*/

    kill(pid, SIGUSR1);
    while (1)
    {
        while (!parent)
        {
            
        }
        /*safe print*/
        write(1,"parent\n", 7);
        parent = 0;
        kill(pid, SIGUSR1);
    }

    return(0);
} 
