/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 02:11:49 by okhan             #+#    #+#             */
/*   Updated: 2025/07/28 19:35:31 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	*extract_line(char *buffer)
{
	char	*line;
	int		len;

	if (!buffer)
		return (NULL);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	len += (buffer[len] == '\n');
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
	{
		line[len] = buffer[len];
		len++;
	}
	if (buffer[len] == '\n')
		line[len++] = '\n';
	line[len] = '\0';
	return (line);
}

static char	*trim_remainder(char *buffer)
{
	char	*new_buffer;
	int		len;
	int		start;

	if (!buffer)
		return (NULL);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (!buffer[len])
	{
		free(buffer);
		return (NULL);
	}
	start = len + 1;
	new_buffer = ft_strdup_gnl(buffer + start);
	free(buffer);
	return (new_buffer);
}

static char	*read_buffer(int fd, char *remainder)
{
	char	*buffer;
	char	*temp;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_find_newline(remainder))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			return (remainder);
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin_gnl(remainder, buffer);
		free (remainder);
		remainder = temp;
	}
	free(buffer);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = read_buffer(fd, remainder);
	if (!remainder || !*remainder)
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	line = extract_line(remainder);
	remainder = trim_remainder(remainder);
	return (line);
}
