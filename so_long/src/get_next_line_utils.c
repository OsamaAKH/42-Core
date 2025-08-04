/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:33:15 by okhan             #+#    #+#             */
/*   Updated: 2025/08/04 16:31:29 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

char	*ft_strdup_gnl(const char *src)
{
	char	*dst;
	size_t	len;
	size_t	i;

	len = ft_strlen_gnl(src);
	dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen_gnl(s);
	if (start >= s_len)
		return (ft_strdup_gnl(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*join;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	if (!s2)
		return (s1);
	len1 = ft_strlen_gnl(s1);
	len2 = ft_strlen_gnl(s2);
	join = malloc(len1 + len2 + 1);
	if (!join)
		return (NULL);
	i = -1;
	while (++i < len1)
		join[i] = s1[i];
	j = -1;
	while (++j < len2)
		join[len1 + j] = s2[j];
	join[len1 + len2] = '\0';
	return (join);
}

int	ft_find_newline(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
