/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:26:47 by okhan             #+#    #+#             */
/*   Updated: 2025/07/20 18:37:25 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		int a = atoi(argv[1]);
		int b = atoi(argv[3]);
		char op = argv[2][0];

		if (op == '+')
			printf("%d\n", a + b);
		else if (op == '-')
			printf("%d\n", a - b);
		else if (op == '*')
			printf("%d\n", a * b);
		else if (op == '/')
			printf("%d\n", a / b);
		else if (op == '%')
			printf("%d\n", a % b);
	}
	else
		printf("\n");
	return (0);
}