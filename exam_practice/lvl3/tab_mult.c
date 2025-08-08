/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:22:17 by okhan             #+#    #+#             */
/*   Updated: 2025/07/21 18:34:39 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	char buffer[11];
	int i = 0;

	if (n == 0)
	{
		ft_putchar('0');
		return;
	}
	while (n > 0)
	{
		buffer[i++] = n % 10 + '0' ;
		n = n / 10;
	}
	while (i--)
	{
		ft_putchar(buffer[i]);
	}
}

void ft_str(char *str)
{
	int i = 0;
	while (str[i])
	{
		ft_putchar(str[i++]);
	}
}

int ft_atoi(char *str)
{
	int i = 0;
	int result = 0;
	while (str[i] >= '0' && str[i]<= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return result;
}

int main(int argc, char **argv)
{
	int n; 
	int	i;

	if (argc != 2)
	{
		ft_putchar('\n');
		return 0;
	}
	n = ft_atoi(argv[1]);
	if (n <= 0)
	{
		ft_putchar('\n');
		return 0;
	}
	i = 1;
	while (i <=9)
	{
		ft_putnbr(i);
		ft_str(" x ");
		ft_putnbr(n);
		ft_str(" = ");
		ft_putnbr(i * n);
		ft_putchar('\n');
		i++;
	}
	return 0;
}