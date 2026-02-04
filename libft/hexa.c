/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:31:35 by marvin            #+#    #+#             */
/*   Updated: 2024/12/08 20:31:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_prthexa(unsigned int num, char *base)
{
	char	result[9];
	int		i;
	int		count;

	count = 0;
	if (num == 0)
	{
		ft_putchar('0');
		return (1);
	}
	i = 0;
	while (num > 0)
	{
		result[i++] = base[num % 16];
		num /= 16;
	}
	while (i > 0)
	{
		i--;
		ft_putchar(result[i]);
		count++;
	}
	return (count);
}
