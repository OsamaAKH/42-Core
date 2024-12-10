/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:30:25 by marvin            #+#    #+#             */
/*   Updated: 2024/12/08 20:30:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_min(void)
{
	write(1, "-2147483648", 11);
	return (11);
}

static int	ft_digit(char *result, int i)
{
	int	count;

	count = 0;
	while (i > 0)
	{
		i--;
		ft_putchar(result[i]);
		count++;
	}
	return (count);
}

int	ft_printnbr(int n)
{
	char	result[12];
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (n == -2147483648)
		return (ft_min());
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	if (n == 0)
		return (ft_putchar('0'));
	while (n > 0)
	{
		result[i++] = n % 10 + '0';
		n = n / 10;
	}
	count += ft_digit(result, i);
	return (count);
}
