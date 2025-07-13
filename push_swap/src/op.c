/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 23:43:07 by okhan             #+#    #+#             */
/*   Updated: 2025/07/09 18:51:44 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_node **a)
{
	t_node	*first;
	t_node	*second;

	if (!(*a) || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	t_node	*first;
	t_node	*second;

	if (!(*b) || ! (*b)->next)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	write (1, "sb\n", 3);
}

static	void	swap_a(t_node **a)
{
	t_node	*first;
	t_node	*second;

	if (!(*a) || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
}

static	void	swap_b(t_node **b)
{
	t_node	*first;
	t_node	*second;

	if (!(*b) || ! (*b)->next)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
}

void	ss(t_node **a, t_node **b)
{
	swap_a(a);
	swap_b(b);
	write(1, "ss\n", 3);
}
