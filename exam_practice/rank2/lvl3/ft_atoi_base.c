/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:04:20 by okhan             #+#    #+#             */
/*   Updated: 2025/09/03 14:06:51 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int	ft_atoi_base(const char *str,unsigned int str_base)
{
	int i = 0;
	int result = 0;
	int sign = 1;
	unsigned int value = 0;

	if (str_base < 2 || str_base > 16)
		return (0);

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			value = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			value = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			value = str[i] - 'A' + 10;
		else
			break;
		if (value >= str_base)
			break;

		result = result * str_base + value;
		i++;
	}
	return (result * sign);
}