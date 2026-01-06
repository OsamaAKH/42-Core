/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:15:54 by okhan             #+#    #+#             */
/*   Updated: 2026/01/03 16:22:55 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"

void	print_sol(int *subset, int size)
{
	int i = 0;

	while (i < size)
	{
		printf("%d", subset[i]);
		if (i + 1 < size)
			printf(" ");
		i++;
	}
	printf("\n");
}

void	backtrack(int *arr, int *subset, int len, int target, int index, int subsize, int sum)
{
	if(index == len)
	{
		if(sum == target)
			print_sol(subset, subsize);
		return ;
	}
	subset[subsize] = arr[index];
	backtrack(arr,subset, len, target, index + 1, subsize + 1, sum + arr[index]);
	backtrack(arr, subset,len, target, index + 1, subsize, sum);
}

int	main(int ac, char **av)
{
	int *arr;
	int *subset;
	int target;
	int len;
	int i;

	if (ac < 2)
		return 0;
	
	len = ac - 2;
	target = atoi(av[1]);
	arr = malloc(sizeof(int) * len);
	subset = malloc(sizeof(int) * len);
	if (!arr || !subset)
		return 1;
	i = 0;
	while (i < len)
	{
		arr[i] = atoi(av[i + 2]);
		i++;
	}
	backtrack(arr, subset, len, target, 0, 0, 0);
	free(arr);
	free(subset);
	return 0;
}