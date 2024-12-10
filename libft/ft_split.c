/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:26:00 by okhan             #+#    #+#             */
/*   Updated: 2024/11/26 16:41:11 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(const char *s, char c)
{
	size_t	wordcount;
	size_t	i;

	wordcount = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			wordcount++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (wordcount);
}

static void	free_all(char **result, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static char	*next_word(const char *s, char c, size_t *i)
{
	size_t	len;
	char	*word;

	while (s[*i] && s[*i] == c)
		(*i)++;
	len = 0;
	while (s[*i + len] && s[*i + len] != c)
		len++;
	word = ft_substr(s, *i, len);
	*i += len;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	count;
	size_t	start;

	if (!s)
		return (NULL);
	count = ft_countwords(s, c);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	i = 0;
	start = 0;
	while (i < count)
	{
		result[i] = next_word(s, c, &start);
		if (!result[i])
		{
			free_all(result, i);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
