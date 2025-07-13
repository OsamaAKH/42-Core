/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:41:18 by okhan             #+#    #+#             */
/*   Updated: 2025/04/17 13:36:23 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_server	g_server;

void	init_server(void)
{
	g_server.current_char = 0;
	g_server.bit_index = 0;
	g_server.client_pid = 0;
	g_server.message_complete = 0;
}

void	print_received_message(void)
{
	ft_printf("\nMessage received from client %d\n", g_server.client_pid);
	g_server.client_pid = 0;
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (g_server.client_pid == 0)
		g_server.client_pid = info->si_pid;
	g_server.current_char |= (sig == SIGUSR2) << g_server.bit_index;
	g_server.bit_index++;
	if (g_server.bit_index == 8)
	{
		if (g_server.current_char == '\0')
			print_received_message();
		else
			write(1, &g_server.current_char, 1);
		g_server.current_char = 0;
		g_server.bit_index = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	init_server();
	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error setting up signal handlers\n");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
