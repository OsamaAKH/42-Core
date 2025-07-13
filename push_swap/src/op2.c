/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:08:49 by okhan             #+#    #+#             */
/*   Updated: 2025/07/09 18:56:54 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_node **a)
{
	t_node	*first;
	t_node	*last;

	if (!(*a) || !((*a)->next))
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	t_node	*first;
	t_node	*last;

	if (!(*b) || !(*b)->next)
		return ;
	first = *b;
	last = *b;
	while (last->next)
		last = last->next;
	*b = first->next;
	first->next = NULL;
	last->next = first;
	write(1, "rb\n", 3);
}

static	void	rotate_a(t_node **a)
{
	t_node	*first;
	t_node	*last;

	if (!(*a) || !((*a)->next))
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
}

static	void	rotate_b(t_node **b)
{
	t_node	*first;
	t_node	*last;

	if (!(*b) || !(*b)->next)
		return ;
	first = *b;
	last = *b;
	while (last->next)
		last = last->next;
	*b = first->next;
	first->next = NULL;
	last->next = first;
}

void	rr(t_node **a, t_node **b)
{
	rotate_a(a);
	rotate_b(b);
	write(1, "rr\n", 3);
}
