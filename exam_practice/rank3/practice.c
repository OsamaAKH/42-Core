/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:54:01 by okhan             #+#    #+#             */
/*   Updated: 2026/01/15 11:51:37 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdlib.h"

void	print(char *s)
{
	int i = 0;
	while (s[i])
	{
		write(1, &s[i++], 1);
	}
	write (1, "\n", 1);
}

void	count_rm(char *s, int *rm_o, int *rm_c)
{
	int open = 0;
	int i = 0;

	*rm_o = 0;
	*rm_c = 0;
	while (s[i])
	{
		if (s[i] == '(')
			open++;
		else if (s[i] == ')')
		{
			if (open > 0)
				open--;
			else
				(*rm_c)++;
		}
		i++;
	}
	*rm_o = open;
}

void backtrack(char *s, int i, int open, int rm_open, int rm_close, char *res)
{
    if (!s[i])
    {
        if (open == 0) // The rm_open/rm_close check is implicitly handled by the recursion
            print(res);
        return;
    }

    // Decision for the current character s[i]
    if (s[i] == '(')
    {
        // Path 1: Remove it (if we still have removals left)
        if (rm_open > 0)
        {
            res[i] = ' ';
            backtrack(s, i + 1, open, rm_open - 1, rm_close, res);
        }
        
        // Path 2: Keep it
        res[i] = '(';
        backtrack(s, i + 1, open + 1, rm_open, rm_close, res);
    }
    else if (s[i] == ')')
    {
        // Path 1: Remove it (if we still have removals left)
        if (rm_close > 0)
        {
            res[i] = ' ';
            backtrack(s, i + 1, open, rm_open, rm_close - 1, res);
        }

        // Path 2: Keep it (only if it's valid to do so)
        if (open > 0)
        {
            res[i] = ')';
            backtrack(s, i + 1, open - 1, rm_open, rm_close, res);
        }
    }
    else // Character is not a parenthesis
    {
        res[i] = s[i];
        backtrack(s, i + 1, open, rm_open, rm_close, res);
    }
}


int main (int ac, char **av)
{
	int rm_open;
	int rm_close;
	char res[1024];
	int i;
	if (ac != 2)
		return 0;
	count_rm(av[1], &rm_open, &rm_close);
	i = 0;
	while (av[1][i])
	{
		res[i] = av[1][i];
		i++;
	}
	res[i] = '\0';
	backtrack(av[1], 0, 0, rm_open, rm_close, res);
	return 0;
}