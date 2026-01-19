/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 20:50:34 by okhan             #+#    #+#             */
/*   Updated: 2026/01/19 20:58:56 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void put_str(char *s)
{
	int i= 0;
	while (s[i])
		write(1, &s[i++], 1);
	write(1, "\n", 1);
}

int val(char *s)
{
	int open = 0;
	int close = 0;
	int i = 0;

	while (s[i])
	{
		if (s[i] == '(')
			open++;
		else if (s[i] == ')')
		{
			if (open > 0)
				open--;
			else 
				close++;
		}
		i++;
	}
	return (open + close);
}

void	solve(char *s, int m_fix, int to_fix, int pos)
{
	int i;
	char c;

	if (m_fix == to_fix && val(s) == 0)
	{
		put_str(s);
		return ;
	}

	i = pos;
	while (s[i])
	{
		if (s[i] == '(' || s[i] == ')')
		{
			c = s[i];
			s[i] = ' ';
			solve(s, m_fix, to_fix + 1, i + 1);
			s[i] = c;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	int m_fix;

	if (ac != 2)
		return 1;
	m_fix = val(av[1]);
	solve(av[1], m_fix, 0, 0);
	return 0;
}