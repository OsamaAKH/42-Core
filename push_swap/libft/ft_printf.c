/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:32:58 by marvin            #+#    #+#             */
/*   Updated: 2024/12/08 20:32:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_format(va_list *args, const char format)
{
	if (format == '%')
		return (ft_putchar('%'));
	else if (format == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (format == 's')
		return (ft_printstr(va_arg(*args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_printnbr(va_arg(*args, int)));
	else if (format == 'u')
		return (ft_prtunsigned(va_arg(*args, unsigned int)));
	else if (format == 'x')
		return (ft_prthexa(va_arg(*args, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_prthexa(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	else if (format == 'p')
		return (ft_printptr(va_arg(*args, void *), "0123456789abcdef"));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_format(&args, str[i]);
		}
		else
		{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
