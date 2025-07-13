/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:21:54 by okhan             #+#    #+#             */
/*   Updated: 2025/07/13 14:25:38 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_digit_string(char *str)
{
	int	i;

	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicate(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	validate_and_store(char **token, int *num, int count)
{
	int		i;
	long	val;

	i = 0;
	while (i < count)
	{
		if (!is_digit_string(token[i]))
			return (0);
		val = ft_atol(token[i]);
		if (val < INT_MIN || val > INT_MAX)
			return (0);
		num[i] = (int)val;
		i++;
	}
	if (check_duplicate(num, count))
		return (0);
	return (1);
}

int	*parse_and_validate(char **token)
{
	int	count;
	int	*num;

	count = 0;
	while (token[count])
		count++;
	num = malloc(count * sizeof(int));
	if (!num)
		return (NULL);
	if (!validate_and_store(token, num, count))
	{
		free(num);
		ft_printf("Error\n");
		return (NULL);
	}
	return (num);
}
