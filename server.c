#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define MAX_MSG_LEN 256


void signal_handler(int sig, siginfo_t *siginfo, void *more_info)
{
    static int        i;
    static char        c;
    static pid_t    pid;

    (void)more_info;
    if (siginfo->si_pid != pid)
    {
        pid = siginfo->si_pid;
        i = 7;
        c = 0;
    }
    if (sig == SIGUSR1)
        c += 1 << i;
    i--;
    if (i == -1)
    {
        write(1, &c, 1);
        i = 7;
        c = 0;
    }
}

int main() 
{
    pid_t pid = getpid();
    printf("Server PID: %d\n", pid);

    struct sigaction action;
    action.sa_sigaction = signal_handler;
    action.sa_flags = SA_SIGINFO;
    sigemptyset(&action.sa_mask);

    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);

    while (1) {
        pause();
    }

    return 0;
}
