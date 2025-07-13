/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:50:51 by okhan             #+#    #+#             */
/*   Updated: 2025/07/13 14:51:54 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	push_and_sort_a(t_node **a, t_node **b)
{
	int	size;

	size = stack_size(*a);
	if (size > 3)
	{
		pb(a, b);
		if (size > 4)
			pb(a, b);
	}
	while (stack_size(*a) > 3)
	{
		assign_positions(*a);
		assign_positions(*b);
		assign_target_positions_a_to_b(*a, *b);
		calculate_cost_a_to_b(*a, *b);
		move_cheapest_a_to_b(a, b);
	}
	sort_three(a);
}

void	turk_sort(t_node **a, t_node **b)
{
	push_and_sort_a(a, b);
	while (*b)
	{
		assign_positions(*a);
		assign_positions(*b);
		assign_target_positions(*a, *b);
		calculate_cost(*a, *b);
		move_cheapest_b_to_a(a, b);
	}
	final_rotate(a);
}

void	sort_stack(t_node **a, t_node **b)
{
	int	size;

	size = stack_size(*a);
	if (is_sorted(*a))
		return ;
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
	else if (size == 3)
		sort_three(a);
	else
		turk_sort(a, b);
}
