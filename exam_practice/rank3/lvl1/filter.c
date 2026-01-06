/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 00:49:21 by okhan             #+#    #+#             */
/*   Updated: 2025/10/16 01:15:05 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>


int main(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s <word>\n", av[0]);
		return 1;
	}

	char *word = av[1];
	int word_len = strlen(word);

	if (word_len == 0)
	{
		return 0;
	}

	char *inpput = NULL;
	int total = 0;
	char buff[1024];
	int bytes;

	while ((bytes = read(0, buff, sizeof(buff))) > 0)
	{
		char *tmp = realloc(inpput, total + bytes);

		if (!tmp)
		{
			fprintf(stderr, "Error: %s\n", strerror(errno));
			free(inpput);
			return 1;
		}

		inpput = tmp;
		memmove(inpput + total, buff, bytes);
		total += bytes;
	}

	if (bytes < 0)
	{
		fprintf(stderr, "Error: %s\n", strerror(errno));
		free(inpput);
		return 1;
	}
	
	char *p = inpput;
	char *match;

	while ((match = memmem(p, inpput + total - p, word, word_len)))
	{
		write(1, p, match - p);

		int i = 0;
		while (i < word_len)
		{
			write(1, "*", 1);
			i++;
		}
		p = match + word_len;
	}

	write(1, p, inpput + total - p);
	free(inpput);

	return 0;
}