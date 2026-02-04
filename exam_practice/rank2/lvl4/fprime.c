/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:56:48 by okhan             #+#    #+#             */
/*   Updated: 2025/07/21 19:05:36 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"

int main (int argc, char **argv)
{
	int num;
	int i = 2;


	if (argc == 2)
	{
		num = atoi(argv[1]);
		if (num == 1)
			printf("1");
		while (i <= num)
		{
			if (num % i == 0)
			{
				printf("%d", i);
				if (num != i)
					printf("*");
				num = num / i;
			}
			else
				i++;
		}
	}
	printf("\n");
	return 0;
}