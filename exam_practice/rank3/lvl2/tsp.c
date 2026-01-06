/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 00:54:11 by okhan             #+#    #+#             */
/*   Updated: 2026/01/05 01:10:05 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

typedef struct s_city
{
	float x;
	float y;
} t_city;

static	float g_min = -1;

float	dist(t_city a, t_city b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	return(sqrtf(dx * dx + dy * dy));
}

void	backtrack(t_city *city, int *used, int n, int cur, int count, float total)
{
	int i;
	if (count == n)
	{
		total += dist(city[cur], city[0]);
		if (g_min < 0 || total < g_min)
			g_min = total;
		return;
	}
	i = 1;
	while (i < n)
	{
		if (!used[i])
		{
			used[i] = 1;
			backtrack(city, used, n, i, count + 1, total + dist(city[cur], city[i]));
			used[i] = 0;
		}
		i++;
	}
	
}

int	main(int ac, char **av)
{
	t_city *city;
	int *used;
	int n;

	n = 0;
	city = malloc(sizeof(t_city) * 11);
	used = calloc(11, sizeof(int));

	if (!city || !used)
		return 1;
	
	while (fscanf(stdin, "%f, %f\n", &city[n].x, &city[n].y) == 2)
		n++;

	if (n < 2)
	{
		printf("0.00\n");
		return 0;
	}
	used[0] = 1;

	backtrack(city, used, n, 0, 1, 0.0);

	printf("%.2f\n", g_min);
	free(city);
	free(used);
	return 0;
}