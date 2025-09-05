/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:40:23 by okhan             #+#    #+#             */
/*   Updated: 2025/09/05 11:51:36 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"

int length(int n)
{
	int i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n = n /10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	long num ;
	int len;
	char *str;

	num = nbr;
	len = length(nbr);
	str = (char *)malloc((len + 1) * sizeof(char));
	if(!str)
		return NULL;
	str[len] = '\0';
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
		len--;
		str[len] = (num % 10) + '0';
		num = num/10;
	}
	return (str);
}