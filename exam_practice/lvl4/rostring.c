/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:22:39 by okhan             #+#    #+#             */
/*   Updated: 2025/08/13 18:37:49 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

static int ft_isspace(char c)
{
	return(c == ' ' || c == '\t');
}

int	main(int ac, char **av)
{
	int i;
	int start;
	int first_word_start;
	int	first_word_end;
	int	printed;

	if (ac < 2 || !av[1][0])
		return(write(1, "\n", 1), 0);
	i = 0;
	while (ft_isspace(av[1][i]))
		i++;
	first_word_start = i;
	while (av[1][i] && !ft_isspace(av[1][i]))
		i++;
	first_word_end = i;
	printed = 0;
	while (av[1][i])
	{
		while (ft_isspace(av[1][i]))
			i++;
		start = i;
		while (av[1][i] && !ft_isspace(av[1][i]))
			i++;
		if (i > start)
		{
			if (printed)
				write(1, " ", 1);
			write(1, av[1] + start, i - start);
			printed = 1;
		}
	}
	if (printed)
		write(1, " ", 1);
	write(1, av[1] + first_word_start, first_word_end - first_word_start);
	write(1, "\n", 1);
	return (0);
}