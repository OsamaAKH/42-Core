/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:08:21 by okhan             #+#    #+#             */
/*   Updated: 2025/07/21 16:14:33 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int     *ft_range(int start, int end)
{
	int i = 0;
	int *arr;
	int	size;

	if (start <= end)
		size = end - start + 1;
	else
		size = start - end + 1;
	arr = (int *)malloc(size * sizeof(int));
	if(!arr)
		return NULL;
	if (start <= end)
	{
		while (i < size)
		{
			arr[i] = start + i;
			i++;
		}
	}
	else
	{
		while (i < size)
		{
			arr[i] = start - i;
			i++;
		}
	}
	return (arr);
}