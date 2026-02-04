/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:57:08 by okhan             #+#    #+#             */
/*   Updated: 2025/07/20 21:15:25 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int main( int argc, char **argv)
{
	int i = 0;
	int end;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	while (argv[1][i])
		i++;
	i--;
	while ( i >= 0 && (argv[1][i] == ' ' || argv[1][i] == '\t'))
		i--;
	end = i;
	while(i >= 0 && argv[1][i] != ' ' && argv[1][i] != '\t')
		i--;
	i++;
	while (i <= end)
	{
		write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
}