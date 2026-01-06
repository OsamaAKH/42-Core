/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:41:11 by okhan             #+#    #+#             */
/*   Updated: 2026/01/04 15:51:22 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	putstr(char *s)
{
	int i = 0;
	while(s[i])
		write(1, &s[i++], 1);
	write(1, "\n", 1);
}

void	count_remove(char *s, int *rm_open, int *rm_close)
{
	int i = 0;
	int open = 0;

	*rm_open = 0;
	*rm_close = 0;

	while (s[i])
	{
		if (s[i] == '(')
			open++;
		else if (s[i] == ')')
		{
			if (s[i] == ')' && open > 0)
				open--;
			else
				(*rm_close)++;
		}
		i++;
	}
	*rm_open = open;
}

void	backtrack(char *s, int open, int i, int rm_open, int rm_close, char *res)
{
	if (!s[i])
	{
		if (open == 0 && rm_open == 0 && rm_close == 0)
			putstr(res);
		return ;
	}
	if (s[i] == '(' && rm_open > 0)
	{
		res[i] = ' ';
		backtrack(s, open, i + 1, rm_open - 1, rm_close, res);
	}
	if (s[i] == ')' && rm_close > 0)
	{
		res[i] = ' ';
		backtrack(s, open, i + 1, rm_open, rm_close - 1, res);
	}
		if (s[i] == '(' )
	{
		res[i] = '(';
		backtrack(s, open + 1, i + 1, rm_open, rm_close, res);
	}
		if (s[i] == ')' && open > 0)
	{
		res[i] = ')';
		backtrack(s, open - 1, i + 1, rm_open, rm_close, res);
	}
		if (s[i] != '(' && s[i] != ')')
	{
		res[i] = s[i];
		backtrack(s, open, i + 1, rm_open, rm_close, res);
	}
}

int main(int ac, char **av)
{
	int rm_open;
	int rm_close;
	char res[1024];
	int i;

	if (ac != 2)
		return 0;
	i = 0;
	while (av[1][i])
	{
		res[i] = av[1][i];
		i++;
	}
	res[i] = '\0';
	count_remove(av[1], &rm_open, &rm_close);
	backtrack(av[1], 0, 0, rm_open, rm_close, res);
	return 0;
}