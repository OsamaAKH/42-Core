/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:58:34 by okhan             #+#    #+#             */
/*   Updated: 2025/07/13 15:03:54 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_node	*find_cheapest_node(t_node *stack)
{
	t_node	*cheapest;
	t_node	*tmp;
	int		cheapest_cost;
	int		current_cost;

	if (!stack)
		return (NULL);
	tmp = stack;
	cheapest = tmp;
	cheapest_cost = abs(tmp->cost_a) + abs(tmp->cost_b);
	tmp = tmp->next;
	while (tmp)
	{
		current_cost = abs(tmp->cost_a) + abs(tmp->cost_b);
		if (current_cost < cheapest_cost)
		{
			cheapest_cost = current_cost;
			cheapest = tmp;
		}
		tmp = tmp->next;
	}
	return (cheapest);
}

void	move_cheapest_b_to_a(t_node **a, t_node **b)
{
	t_node	*cheapest;

	if (!b || !*b)
		return ;
	cheapest = find_cheapest_node(*b);
	if (cheapest)
		execute_move_b_to_a(a, b, cheapest->cost_a, cheapest->cost_b);
}

void	move_cheapest_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest;

	if (!a || !*a)
		return ;
	cheapest = find_cheapest_node(*a);
	if (cheapest)
		execute_move_a_to_b(a, b, cheapest->cost_a, cheapest->cost_b);
}

void	final_rotate(t_node **a)
{
	int	min_pos;
	int	size;
	int	moves;

	assign_positions(*a);
	min_pos = find_min_index_pos(*a);
	size = stack_size(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a);
	}
	else
	{
		moves = size - min_pos;
		while (moves-- > 0)
			rra(a);
	}
}
