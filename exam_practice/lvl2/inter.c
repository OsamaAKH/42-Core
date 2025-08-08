/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:47:18 by okhan             #+#    #+#             */
/*   Updated: 2025/07/21 14:55:04 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int main(int argc, char ** argv)
{
	int i, j, k;

	i = 0;
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
	{
		k = 0;
		while (k < i)
		{
			if (argv[1][k] == argv[1][i])
				break;
			k++;
		}
		if (k != i)
		{
			i++;
			continue;
		}
		j = 0;
		while (argv[2][j])
		{
			if (argv[2][j] == argv[1][i])
			{
				write(1, &argv[1][i], 1);
				break;
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}