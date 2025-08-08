/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:15:35 by okhan             #+#    #+#             */
/*   Updated: 2025/07/21 16:20:46 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int     *ft_rrange(int start, int end)
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
	while (i < size)
	{
		arr[i] = end;
		if (end > start)
			end--;
		else
			end++;
		i++;
	}
	return (arr);
}