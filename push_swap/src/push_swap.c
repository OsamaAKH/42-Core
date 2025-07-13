/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:42:57 by okhan             #+#    #+#             */
/*   Updated: 2025/07/13 14:51:30 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->index;
	b = (*stack)->next->index;
	c = (*stack)->next->next->index;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
}

void	init_stack(t_node **a, int argc, char **argv)
{
	char	**token;
	int		*value;
	int		count;
	int		i;

	token = join_split(argc, argv);
	if (!token)
		exit(EXIT_FAILURE);
	value = parse_and_validate(token);
	if (!value)
	{
		free_split(token);
		exit(EXIT_FAILURE);
	}
	count = 0;
	while (token[count])
		count++;
	i = 0;
	while (i < count)
		add_node_back(a, new_node(value[i++]));
	free(value);
	free_split(token);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	init_stack(&a, argc, argv);
	assign_index(a);
	sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
