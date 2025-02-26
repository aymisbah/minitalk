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

void	signal_handler(int sig, siginfo_t *siginfo, void *more_info)
{
	pid_t	pid;
	int		i;
	char	c;

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
