/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanke_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 22:32:06 by okhan             #+#    #+#             */
/*   Updated: 2025/07/21 14:55:07 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int	main(int argc, char **argv)
{
	int	i = 0;
	int	capitalize = 0;
	char	c;

	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == '_')
				capitalize = 1;
			else
			{
				c = argv[1][i];
				if (capitalize && c >= 'a' && c <= 'z')
					c -= 32;
				write(1, &c, 1);
				capitalize = 0;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}