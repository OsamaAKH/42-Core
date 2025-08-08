/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:02:39 by okhan             #+#    #+#             */
/*   Updated: 2025/07/21 17:33:41 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"

int	gcd(int a, int b)
{
	int temp;

	while (b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return (a);
}

int main(int argc, char **argv)
{
	int a, b;

	if (argc != 3)
	{
		printf("\n");
		return 0;
	}
	a = atoi(argv[1]);
	b = atoi(argv[2]);

	if (a <= 0 || b <= 0)
	{
		printf("\n");
		return (0);
	}
	printf("%d\n", gcd(a,b));
	return (0);
}