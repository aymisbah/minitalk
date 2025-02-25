#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>

int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
int		isnmb(char c);

void	send_bit(int pid, int bit);
void	check_sig(int sig);
void	send_msg(int pid, const char *msg);

#endif