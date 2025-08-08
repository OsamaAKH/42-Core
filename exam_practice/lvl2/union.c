/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 22:37:56 by okhan             #+#    #+#             */
/*   Updated: 2025/07/20 22:45:51 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int	is_printed(char *str, char c, int pos)
{
	int i = 0;
	while(i < pos)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int i, j;
	
	i = 0;
	if (argc == 3)
	{
		while(argv[1][i])
		{
			if(!is_printed(argv[1], argv[1][i], i))
				write(1, &argv[1][i], 1);
			i++;
		}
		j = 0;
		while (argv[2][j])
		{
			if (!is_printed(argv[1], argv[2][j], i) && !is_printed(argv[2], argv[2][j], j))
				write(1, &argv[2][j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}