/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbizz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:53:29 by okhan             #+#    #+#             */
/*   Updated: 2025/07/19 17:05:29 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	putnbr(int n)
{
	char digit[10];
	int i = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return;
	}
	while (n > 0)
	{
		digit[i++] = '0' + (n % 10);
		n /= 10;
	}
	while (i--)
		write(1, &digit[i], 1);
}

int	main(void)
{
	int i = 1;

	while (i <= 100)
	{
		if(i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			putnbr(i);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}