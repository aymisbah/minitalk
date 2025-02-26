/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymisbah <aymisbah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:50:20 by aymisbah          #+#    #+#             */
/*   Updated: 2025/02/25 17:21:48 by aymisbah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	check(const char c, va_list args)
{
	int	res;

	res = 0;
	if (c == 'd')
		res = ft_putnbr(va_arg(args, int));
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total;
	int		res;

	i = 0;
	total = 0;
	va_start(args, format);
	if (write (1, "", 0) == -1)
		return (-1);
	while (format[i])
	{
		if (format[i] != '%')
			res = ft_putchar(format[i]);
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			res = check(format[i], args);
		}
		total += res;
		i++;
	}
	va_end(args);
	return (total);
}
