/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:45:43 by okhan             #+#    #+#             */
/*   Updated: 2025/07/21 16:54:42 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_putnbr(int n)
{
	char buff[11];
	int	i = 0;

	while (n > 0)
	{
		buff[i++] = n % 10 + '0';
		n = n/10;
	}
	while(i--)
		write(1, &buff[i], 1);
}

int main (int argc, char** argv)
{
	(void)argv;
	if (argc > 1)
		ft_putnbr(argc - 1);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}