/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:14:01 by okhan             #+#    #+#             */
/*   Updated: 2025/11/18 15:17:34 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"
#include <limits.h>

int	my_pwd(t_command *cmd)
{
	char	cwd[CWD_BUFFER_SIZE];

	if(cmd->args[1] != NULL)
	{
		fprintf(stderr, "minishell: pwd. Too many arguments!\n");
		return (1);
	}

	if (getcwd(cwd, CWD_BUFFER_SIZE) != NULL)
	{
		printf("%s\n", cwd);
		return (0);
	}
	else
	{
		perror("pwd");
		return (1);
	}
}

