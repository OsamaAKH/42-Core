/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 23:43:49 by okhan             #+#    #+#             */
/*   Updated: 2026/01/12 16:55:55 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char buff[BUFFER_SIZE];
	static int i = 0, r = 0;
	char *line;
	int j = 0;

	if (fd < 0 || BUFFER_SIZE <= 0 || !(line = malloc(10000)))
		return (NULL);

	while (1)
	{
		if (i >= r)
		{	
			i = 0;
			r = read(fd, buff, BUFFER_SIZE);
			if ( r <= 0)
				break;
		}
		line[j++] = buff[i++];
		if (line[j - 1] == '\n')
			break; 
	}
	if (j)
	{
		line[j] = 0;
		return (line);
	}
	else
	{
		free(line);
		return (NULL);
	}
}