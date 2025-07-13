/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:16:49 by okhan             #+#    #+#             */
/*   Updated: 2025/07/13 14:59:41 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	calculate_cost(t_node *a, t_node *b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (b)
	{
		if (b->pos <= size_b / 2)
			b->cost_b = b->pos;
		else
			b->cost_b = (size_b - b->pos) * -1;
		if (b->target_pos <= size_a / 2)
			b->cost_a = b->target_pos;
		else
			b->cost_a = (size_a - b->target_pos) * -1;
		b = b->next;
	}
}

void	calculate_cost_a_to_b(t_node *a, t_node *b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (a)
	{
		if (a->pos <= size_a / 2)
			a->cost_a = a->pos;
		else
			a->cost_a = (size_a - a->pos) * -1;
		if (a->target_pos <= size_b / 2)
			a->cost_b = a->target_pos;
		else
			a->cost_b = (size_b - a->target_pos) * -1;
		a = a->next;
	}
}

static	void	rotate(t_node **a, t_node **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	execute_move_a_to_b(t_node **a, t_node **b, int cost_a, int cost_b)
{
	rotate(a, b, &cost_a, &cost_b);
	while (cost_a > 0)
	{
		ra(a);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(a);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(b);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b);
		cost_b++;
	}
	pb(a, b);
}

void	execute_move_b_to_a(t_node **a, t_node **b, int cost_a, int cost_b)
{
	rotate(a, b, &cost_a, &cost_b);
	while (cost_a > 0)
	{
		ra(a);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(a);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(b);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b);
		cost_b++;
	}
	pa(a, b);
}
