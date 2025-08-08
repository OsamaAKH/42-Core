/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:35:30 by okhan             #+#    #+#             */
/*   Updated: 2025/07/21 17:53:05 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	printhex(unsigned int n)
{
	char *hex = "0123456789abcdef";
	char buffer[16];
	int i = 0;

	if (n == 0)
	{
		ft_putchar("0");
		return ;
	}
	while ((n > 0))
	{
		buffer[i++] = hex[n %16];
		n = n/16;
	}
	while (i--)
		ft_putchar(buffer[i]);
}

int main(int argc, char **argv)
{
	unsigned int n = 0;
	int i = 0;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	while (argv[1][i] >= '0' && argv[1][i] <= '9')
	{
		n = n * 10 + (argv[1][i] - '0');
		i++;
	}
	printhex(n);
	write(1, "\n", 1);
	return 0;
}