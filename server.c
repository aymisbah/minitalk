#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define MAX_MSG_LEN 256

// Function to handle SIGUSR1 and SIGUSR2 signals
// void signal_handler(int sig, siginfo_t *info, void *ucontext) {
//     static char message[MAX_MSG_LEN];
//     static int index = 0;
//     pid_t pid;

//     if (info->si_pid != pid)
//     {
//         pid = info->si_pid;
//     }
//     // Determine which signal is received
//     if (sig == SIGUSR1) {
//         message[index] = '0'; // Character for SIGUSR1
//         index++;
//     } else if (sig == SIGUSR2) {
//         message[index] = '1'; // Character for SIGUSR2
//         index++;
//     }

//     message[index] = '\0'; // Null-terminate the string

//     if (index >= MAX_MSG_LEN - 1) {
//         printf("Received message: %s\n", message);
//         index = 0;  // Reset for next message
//     }
// }
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

int main() {
    pid_t pid = getpid();
    printf("Server PID: %d\n", pid);

    struct sigaction action;
    action.sa_sigaction = signal_handler;
    action.sa_flags = SA_SIGINFO;
    sigemptyset(&action.sa_mask);

    // Set up the signal handlers for SIGUSR1 and SIGUSR2
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);

    // Keep the server running indefinitely to listen for signals
    while (1) {
        pause(); // Wait for signals
    }

    return 0;
}
