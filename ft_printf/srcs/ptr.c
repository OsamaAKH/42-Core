/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:31:03 by marvin            #+#    #+#             */
/*   Updated: 2024/12/08 20:31:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_null(void)
{
	write(1, "(nil)", 5);
	return (5);
}

int	ft_printptr(void *ptr, char *base)
{
	unsigned long	addr;
	char			result[16];
	int				i;
	int				count;

	count = 0;
	addr = (unsigned long)ptr;
	if (ptr == NULL)
		return (ft_null());
	i = 0;
	while (addr > 0)
	{
		result[i++] = base[addr % 16];
		addr = addr / 16;
	}
	write(1, "0x", 2);
	while (i > 0)
	{
		i--;
		ft_putchar(result[i]);
		count++;
	}
	return (count + 2);
}
