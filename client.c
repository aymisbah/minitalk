#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int ft_atoi(const char *str)
{
    size_t res = 0;
    int i = 0;
    int sign = 1;

    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (int)(res * sign);
}

int ft_strlen(const char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}

void send_bit(int pid, int bit)
{
    if (bit == 0)
        kill(pid, SIGUSR2);
    else
        kill(pid, SIGUSR1);
    usleep(17300);
}

void send_msg(int pid, const char *msg)
{
    int i;
    int bit;
    unsigned char c;
    int j;
    
    i = 0;
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
}

int main(int ac, char **av)
{
    if (ac != 3)
    {
        write(2, "Usage: ./client <PID> <message>\n", 31);
        return 1;
    }
    int i = 0;
    while (av[1][i])
    {
        if (av[1][i] == ' ' || av[1][i] == '\t')
        {
            write(2,"provid a valid pid\n",21);
            return (0);
        }
        i++;  
    }
    if (ft_atoi(av[1]) <= 0 || ft_atoi(av[1]) > 4194304)
    {
        write(2,"provid a valid pid\n",21);
            return (0);
    }
    int pid = ft_atoi(av[1]);
    const char *msg = av[2];
    send_msg(pid, msg);
    return 0;
}
