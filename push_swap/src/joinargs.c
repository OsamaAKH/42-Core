/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joinargs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 18:09:26 by okhan             #+#    #+#             */
/*   Updated: 2025/07/09 18:45:10 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*join_args(int argc, char **argv)
{
	char	*joined;
	char	*temp;
	int		i;

	joined = ft_strdup("");
	if (!joined)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		temp = ft_strjoin (joined, argv[i]);
		free(joined);
		joined = ft_strjoin(temp, " ");
		free(temp);
		i++;
	}
	return (joined);
}

char	**join_split(int argc, char **argv)
{
	char	*join;
	char	**split;

	join = join_args(argc, argv);
	if (!join)
		return (NULL);
	split = ft_split(join, ' ');
	free(join);
	return (split);
}

void	free_split(char **tokens)
{
	int	i;

	i = 0;
	if (!tokens)
		return ;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
