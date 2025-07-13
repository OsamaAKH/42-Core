/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:55:29 by okhan             #+#    #+#             */
/*   Updated: 2025/07/13 14:56:01 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_target_pos_b_to_a(t_node *a, int b_index)
{
	t_node	*tmp;
	int		target_index;
	int		target_pos;
	int		found;

	tmp = a;
	target_index = INT_MAX;
	target_pos = 0;
	found = 0;
	while (tmp)
	{
		if (tmp->index > b_index)
		{
			if (!found || tmp->index < target_index)
			{
				target_index = tmp->index;
				target_pos = tmp->pos;
				found = 1;
			}
		}
		tmp = tmp->next;
	}
	if (!found)
		return (find_min_index_pos(a));
	return (target_pos);
}

int	get_target_pos_a_to_b(t_node *b, int a_index)
{
	t_node	*tmp;
	int		target_index;
	int		target_pos;
	int		found;

	tmp = b;
	target_index = INT_MIN;
	target_pos = 0;
	found = 0;
	while (tmp)
	{
		if (tmp->index < a_index)
		{
			if (!found || tmp->index > target_index)
			{
				target_index = tmp->index;
				target_pos = tmp->pos;
				found = 1;
			}
		}
		tmp = tmp->next;
	}
	if (!found)
		return (find_max_index_pos(b));
	return (target_pos);
}

void	assign_target_positions(t_node *a, t_node *b)
{
	while (b)
	{
		b->target_pos = get_target_pos_b_to_a(a, b->index);
		b = b->next;
	}
}

void	assign_target_positions_a_to_b(t_node *a, t_node *b)
{
	while (a)
	{
		a->target_pos = get_target_pos_a_to_b(b, a->index);
		a = a->next;
	}
}

void	assign_positions(t_node *stack)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		stack->pos = pos++;
		stack = stack->next;
	}
}
