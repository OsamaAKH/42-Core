/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:47:18 by okhan             #+#    #+#             */
/*   Updated: 2025/09/05 11:59:01 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int printed(char *s, char c, int pos)
{
    int i = 0;
    while (i < pos)
    {
        if (s[i] == c)
            return 1;
        i++;
    }
    return 0;
}

int exists(char *s, char c)
{
    int i = 0;
    while (s[i])
    {
        if (s[i] == c)
            return 1;
        i++;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        int i = 0;
        while (av[1][i])
        {
            if (!printed(av[1], av[1][i], i) && exists(av[2], av[1][i]))
                write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}
