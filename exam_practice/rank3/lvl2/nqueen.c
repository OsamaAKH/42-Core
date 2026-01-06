/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nqueen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 15:03:21 by okhan             #+#    #+#             */
/*   Updated: 2026/01/02 14:27:27 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"

int	is_safe(int col, int row, int *pos)
{
	int i; 

	i = 0;
	while (i < col)
	{
		if (pos[i] == row)
			return 0;
		if ((pos[i] - row == i - col) || (row - pos[i] == i - col))
			return 0;
		i++;
	}
	return 1;
}

void	print_solution(int *pos, int n)
{
	int i;
	char c;

	i = 0;
	while(i < n)
	{
		c = pos[i] + '0';
		write(1, &c, 1);
		if (i + 1 < n)
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}
void	solve(int col, int n, int *pos)
{
	int row;

	if (col == n)
	{
		print_solution(pos, n);
		return ;
	}
	row = 0;
	while(row < n)
	{
		if(is_safe(col, row, pos))
		{
			pos[col] = row;
			solve(col + 1, n, pos);
		}
		row++;
	}
}

int	main(int ac, char **av)
{
	int n;
	int pos[10];

	if (ac != 2)
		return 0;
	n = atoi(av[1]);
	if (n <= 0 || n > 10)
		return 0;
	solve(0, n, pos);
	return 0;
}