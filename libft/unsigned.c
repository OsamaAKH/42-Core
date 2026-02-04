/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:32:19 by marvin            #+#    #+#             */
/*   Updated: 2024/12/08 20:32:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_prtunsigned(unsigned int num)
{
	char	result[10];
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
		result[i++] = (num % 10) + '0';
		num /= 10;
	}
	while (i > 0)
	{
		i--;
		ft_putchar(result[i]);
		count++;
	}
	return (count);
}
