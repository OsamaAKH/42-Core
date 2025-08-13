/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:27:20 by okhan             #+#    #+#             */
/*   Updated: 2025/08/13 19:57:18 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int count_words(const char *s, char c)
{
	int i = 0;
	int count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
		{
			i++;
		}
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char* word_dup(const char *s, int start, int end)
{
	int i = 0;
	char *word;

	word = (char *)malloc((end - start + 1) * sizeof (char*));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i++] = s[start++];
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int i = 0;
	int j = 0;
	int start;

	if (!s)
		return (NULL);
	res = (char **)malloc((count_words(s, c)) * sizeof(char *));
	if (!res)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] !=c)
			i++;
		if (i > start)
			res[j++] = word_dup(s, start, i);
	}
	res[j] = NULL;
	return (res);
}