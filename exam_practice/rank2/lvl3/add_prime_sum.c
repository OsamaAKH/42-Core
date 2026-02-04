/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:01:58 by okhan             #+#    #+#             */
/*   Updated: 2025/07/21 14:25:08 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
} 

void	ft_putnbr(int n)
{
	char	buff[11];
	int	i = 0;

	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	while (n > 0)
	{
		buff[i++] = (n % 10) + '0';
		n = n /10; 
	}
	while (i--)
		ft_putchar(buff[i]);
}

int	ft_atoi(char *str)
{
	int	result = 0;
	int	i = 0;

	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

int	is_prime(int n)
{
	int i = 2;

	if (n < 2)
		return (0);
	while (i <= n/2)
	{
		if (n % i == 0)
			return 0;
		i++;
	}
	return 1;
}

int	main(int argc, char **argv)
{
	int i = 2;
	int sum = 0;
	int nb;

	if (argc == 2)
	{
		nb = ft_atoi(argv[1]);
		if (nb >= 0)
		{
			while (i <= nb)
			{
				if (is_prime(i))
					sum += i;
				i++;
			}
			ft_putnbr(sum);
			ft_putchar('\n');
			return 0;
		}
	}
	write(1, "0\n", 2);
	return 0;
}