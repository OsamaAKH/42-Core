/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:37:34 by okhan             #+#    #+#             */
/*   Updated: 2024/11/15 18:42:41 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_length(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	space;

	dest_len = ft_length(dest);
	src_len = ft_length(src);
	if (size <= dest_len)
		return (size + src_len);
	i = 0;
	space = size - dest_len -1;
	while (i < space && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
