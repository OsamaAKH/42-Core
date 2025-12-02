/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:15:47 by okhan             #+#    #+#             */
/*   Updated: 2025/12/02 15:20:34 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"


int main(int ac, char **av, char **envp)
{
	 t_data data;
    t_command cmd;

    // 1️⃣ Initialize data
    data.env_list = init_env(envp);
    data.user_input = NULL;
    data.working_dir = NULL;
    data.last_exit_code = 0;

    if (!data.env_list)
    {
        printf("Failed to initialize env list\n");
        return 1;
    }

    // 2️⃣ Test builtin_env
    printf("====== Testing builtin_env() ======\n");

    char *args1[] = {"env", NULL};
    cmd.args = args1;
    builtin_env(&cmd, &data);

    // 3️⃣ Test get_env_value
    printf("\n====== Testing get_env_value() ======\n");
    printf("HOME = %s\n", get_env_value(&data, "HOME"));
    printf("PATH = %s\n", get_env_value(&data, "PATH"));
    printf("SHELL = %s\n", get_env_value(&data, "SHELL")); // may be NULL depending on system

    // 4️⃣ Free environment list
    printf("\n====== Freeing env list ======\n");
    free_env_list(data.env_list);

    printf("Done.\n");
    return 0;
}