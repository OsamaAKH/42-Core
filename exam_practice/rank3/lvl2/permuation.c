/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permuation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:00:33 by okhan             #+#    #+#             */
/*   Updated: 2026/01/19 21:05:09 by okhan            ###   ########.fr       */
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

void	sort_string(char *s)
{
	int i;
	int j;

	i = 0;

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
		sort_string(s + left + 1);
		permute(s, left + 1, right);
		sort_string(s + left + 1);
		ft_swap(&s[left], &s[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	
	int i;

	if (ac != 2)
		return 0;

	sort_string(av[1]);
	permute(av[1], 0, ft_len(av[1]) - 1);
	return 0;
}