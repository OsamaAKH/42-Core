/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 20:11:26 by okhan             #+#    #+#             */
/*   Updated: 2026/01/12 20:38:36 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

typedef struct s_city
{
	float x;
	float y;
}t_city;

float dis(t_city a, t_city b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	return(sqrtf(dx * dx + dy * dy));
}

static float g_min = -1;

void	backtrack(t_city *city, int *used, int n, int cur, int count, float total)
{
	int i ;
	if (count == n)
	{
		total += dis(city[cur], city[0]);
		if (g_min < 0 ||total < g_min)
			g_min = total;
		return ;
	}
	i = 1;
	while (i < n)
	{
		if (!used[i])
		{
			used[i] = 1;
			backtrack(city, used, n, i, count + 1, total + dis(city[cur], city[i]));
			used[i] = 0;
		}
		i++;
	}
	
}

int main(int ac, char ** av)
{
	t_city *city;
	int *used;
	int n;

	n = 0;
	city = malloc(sizeof(t_city)*11);
	used= calloc (11, sizeof(int));
	if (!used || city)
		return 1;
	while (fscanf(stdin, "%f, %f\n", &city[n].x, &city[n].y) == 2)
	{
		n++;
	}
	if (n < 2)
	{
		printf("0.00\n");
		return 0;
	}
	used[0] = 1;
	backtrack(city, used, n, 0, 1, 0.00);
	printf("%.2f\n", g_min);
	free(city);
	free(used);
	return 0;
}