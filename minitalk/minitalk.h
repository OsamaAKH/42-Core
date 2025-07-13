/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:58:00 by okhan             #+#    #+#             */
/*   Updated: 2025/07/13 15:32:53 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "libft/libft.h"

int	ft_atoi(const char *str);

typedef struct s_server
{
	char	current_char;
	int		bit_index;
	pid_t	client_pid;
	int		message_complete;
}	t_server;

#endif
