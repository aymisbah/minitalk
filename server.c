/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymisbah <aymisbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:08:42 by aymisbah          #+#    #+#             */
/*   Updated: 2025/02/25 17:18:54 by aymisbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_signal_state g_state; 

void signal_handler(int sig, siginfo_t *siginfo, void *more_info)
{
    (void)more_info;

    if (siginfo->si_pid != g_state.pid) 
    {
        g_state.pid = siginfo->si_pid;
        g_state.i = 7;
        g_state.c = 0;  
    }
    if (sig == SIGUSR1)
		g_state.c += 1 << g_state.i;
    g_state.i--;
    if (g_state.i == -1) {
        write(1, &g_state.c, 1);
        g_state.i = 7;
        g_state.c = 0;
    }
    usleep(500);
    kill(siginfo->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	action;
	pid_t				pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	action.sa_sigaction = signal_handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
