/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:46:15 by okhan             #+#    #+#             */
/*   Updated: 2026/01/12 17:59:49 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


int	main(int ac, char **av)
{
	char *input = NULL;
	char buff[1024];
	ssize_t bytes;
	size_t len = 0, i , j;

	if (ac != 2 || !(*av[1]))
		return 1;
	while ((bytes = read(0, buff, sizeof(buff))) > 0)
	{
		char *tmp = realloc(input, len + bytes);
		if (!tmp)
			return(perror("Error"), free(input), 1);
		input = tmp;
		i = 0;
		while (i < (size_t)bytes)
		{
			input[len++] = buff[i++];
		}
	}
	if (bytes < 0)
		return (perror("Error"), free(input), 1);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (av[1][j] && i + j < len && input[i + j] == av[1][j])
		{
			j++;
		}
		if (!(av[1][j]))
		{
			while (j--)
			{
				printf("*");
			}
			i += strlen(av[1]);
		}
		else
		{
			printf("%c", input[i++]);
		}
	}
	free(input);
	return 0;
}