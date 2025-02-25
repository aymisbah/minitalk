#include "minitalk.h"

void	send_bit(int pid, int bit)
{
	if (bit == 0)
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGUSR1);
	pause();
}
int	g_signal_r = 0;

void	check_sig(int sig)
{
	if (sig == SIGUSR1)
		g_signal_r = 1;
	else if (sig == SIGUSR2)
		g_signal_r = 0;
}

void	send_msg(int pid, const char *msg)
{
	unsigned char	c;
	int				i;
	int				bit;
	int				j;

	i = 0;
	signal(SIGUSR1, check_sig);
	signal(SIGUSR2, check_sig);
	while (msg[i])
	{
		c = msg[i];
		j = 7;
		while (j >= 0)
		{
			bit = (c >> j) & 1;
			send_bit(pid, bit);
			j--;
		}
		i++;
	}
	while (!g_signal_r)
		usleep(100);
	write(1, "Message Recieved\n", 17);
}

int	check_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || !isnmb(str[i]))
		{
			write(2, "provid a valid pid\n", 20);
			return (0);
		}
		i++;
	}
	return (i);
}

int	main(int ac, char **av)
{
	int			pid;
	int			f;
	const char	*msg;

	if (ac != 3)
	{
		write(2, "Usage: ./client <PID> <message>\n", 31);
		return (1);
	}
	f = check_valid(av[1]);
	if (f == 0)
		return (0);
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[1]) > 4194304)
	{
		write(2, "provid a valid pid\n", 20);
		return (0);
	}
	pid = ft_atoi(av[1]);
	msg = av[2];
	send_msg(pid, msg);
	return (0);
}
