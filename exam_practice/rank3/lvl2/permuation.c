/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permuation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:00:33 by okhan             #+#    #+#             */
/*   Updated: 2026/01/12 18:51:06 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "unistd.h"

int	ft_len(char *s)
{
	int i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	ft_swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void	print(char *s, int n)
{
	write(1, s, n);
	write(1, "\n", 1);
}

void	sort_string(char *s, int start)
{
	int i;
	int j;

	i = start;

	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (s[i] > s[j])
				ft_swap(&s[i], &s[j]);
			j++;
		}
		i++;
	}
	
}

void	permute(char *s, int left, int right)
{
	int i;

	if (left == right)
	{
		print(s, right + 1);
		return ;
	}
	i = left;
	while (i <= right)
	{
		ft_swap(&s[left], &s[i]);
		sort_string(s, left + 1);
		permute(s, left + 1, right);
		ft_swap(&s[left], &s[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	int len;
	char *s;
	int i;

	if (ac != 2)
		return 0;

	len = ft_len(av[1]);
	s = malloc(len + 1);

	if (!s)
		return 0;
	i = 0;
	while (i < len)
	{
		s[i] = av[1][i];
		i++;
	}

	s[i] = '\0';

	sort_string(s, 0);

	permute(s, 0, len - 1);
	free(s);
	return 0;
}