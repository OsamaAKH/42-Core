/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 02:11:49 by okhan             #+#    #+#             */
/*   Updated: 2025/01/10 15:44:42 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str)
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_left_str(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(ft_strlen(left_str) - i);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}

int	read_buffer(int fd, char **left_str, char *buff)
{
	int	rd_bytes;

	rd_bytes = 1;
	while ((!*left_str || !ft_strchr(*left_str, '\n')) && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			if (*left_str)
				free(*left_str);
			*left_str = NULL;
			return (-1);
		}
		buff[rd_bytes] = '\0';
		*left_str = ft_strjoin(*left_str, buff);
	}
	free(buff);
	return (rd_bytes);
}

char	*get_next_line(int fd)
{
	static char	*left_str;
	char		*line;
	char		*buff;
	int			rd_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = read_buffer(fd, &left_str, buff);
	if (rd_bytes == -1)
		return (NULL);
	if (rd_bytes == 0 && (!left_str || left_str[0] == '\0'))
		return (NULL);
	line = get_line(left_str);
	left_str = new_left_str(left_str);
	return (line);
}
