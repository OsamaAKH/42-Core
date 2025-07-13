/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:45:21 by okhan             #+#    #+#             */
/*   Updated: 2025/07/13 14:47:37 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_min_index_pos(t_node *head)
{
	int	lowest_index;
	int	lowest_pos;
	int	pos;

	if (!head)
		return (0);
	lowest_index = head->index;
	lowest_pos = 0;
	pos = 0;
	while (head)
	{
		if (head->index < lowest_index)
		{
			lowest_index = head->index;
			lowest_pos = pos;
		}
		head = head->next;
		pos++;
	}
	return (lowest_pos);
}

int	find_max_index_pos(t_node *head)
{
	int	highest_index;
	int	highest_pos;
	int	pos;

	if (!head)
		return (0);
	highest_index = head->index;
	highest_pos = 0;
	pos = 0;
	while (head)
	{
		if (head->index > highest_index)
		{
			highest_index = head->index;
			highest_pos = pos;
		}
		head = head->next;
		pos++;
	}
	return (highest_pos);
}
