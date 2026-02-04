/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 19:10:43 by okhan             #+#    #+#             */
/*   Updated: 2025/07/21 19:39:36 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "stddef.h"

unsigned int len(int n)
{
	int i = 0;
	if (n <= 0);
		i = 1;
	while (n != 0)
	{
		n = n /10;
		i++;
	}
	return(i);
}

char	*ft_itoa(int n)
{
	long num;
	int length;
	char *str;

	num = n;
	length = len(n);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return NULL;
	str[length] = '\0';
	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		length--;
		str[length] = (num % 10) + '0';
		num = num / 10;
	}
	return (str);
}