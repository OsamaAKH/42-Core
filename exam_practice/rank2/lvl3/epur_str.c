/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:25:57 by okhan             #+#    #+#             */
/*   Updated: 2025/07/21 14:52:23 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int main(int argc, char **argv)
{
	int i = 0;
	int print_spaces = 0;

	if (argc == 2)
	{
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
		{
			i++;
		}
		while (argv[1][i])
		{
			if (argv[1][i] != ' ' && argv[1][i] != '\t')
			{
				if (print_spaces)
					write(1, " ", 1);
				while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
				{
					write(1, &argv[1][i], 1);
					i++;
				}
				print_spaces = 1;
			}
			else
				i++;
		}
	}
	write(1 , "\n", 1);
	return(0);
}