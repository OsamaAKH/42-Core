/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:59:52 by okhan             #+#    #+#             */
/*   Updated: 2025/07/21 18:07:12 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

char	isspace(char c)
{
	return(c == ' ' || c == '\t' || c == '\0');
}

void	r_capitalizer(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		else if(str[i] >= 'a' && str[i] <= 'z' && isspace(str[i + 1]))
			str[i] -= 32;
		ft_putchar(str[i++]);
	}
}

int	main(int argc, char **argv)
{
	int i = 1;
	if (argc < 2)
		ft_putchar('\n');
	else
	{
		while (i < argc)
		{
			r_capitalizer(argv[i]);
			ft_putchar('\n');
			i++;
		}
	}
	return 0;	
}