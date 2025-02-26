/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymisbah <aymisbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:07:58 by aymisbah          #+#    #+#             */
/*   Updated: 2025/02/25 17:21:37 by aymisbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		i;
	int		res;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		i++;
		nb = -nb;
	}
	if (nb > 9)
	{
		res = ft_putnbr(nb / 10);
		i += res;
	}
	ft_putchar((nb % 10) + '0');
	i++;
	return (i);
}
