/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:44:30 by okhan             #+#    #+#             */
/*   Updated: 2025/07/09 19:10:28 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;	
}	t_node;

void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
int		is_digit_string(char *str);
int		check_duplicate(int *arr, int size);
int		*parse_and_validate(char **token);
char	*join_args(int argc, char **argv);
char	**join_split(int argc, char **argv);
void	free_split(char **tokens);
t_node	*new_node(int value);
void	add_node_back(t_node **stack, t_node *new);
t_node	*get_last_node(t_node *stack);
int		stack_size(t_node *stack);
void	free_stack(t_node **stack);
void	assign_index(t_node *stack);
int		find_min_index_pos(t_node *head);
int		find_max_index_pos(t_node *head);
void	sort_three(t_node **stack);
void	calculate_cost(t_node *a, t_node *b);
void	calculate_cost_a_to_b(t_node *a, t_node *b);
void	execute_move_a_to_b(t_node **a, t_node **b, int cost_a, int cost_b);
void	execute_move_b_to_a(t_node **a, t_node **b, int cost_a, int cost_b);
void	move_cheapest_b_to_a(t_node **a, t_node **b);
void	move_cheapest_a_to_b(t_node **a, t_node **b);
void	final_rotate(t_node **a);
int		get_target_pos_b_to_a(t_node *a, int b_index);
int		get_target_pos_a_to_b(t_node *b, int a_index);
void	assign_target_positions(t_node *a, t_node *b);
void	assign_target_positions_a_to_b(t_node *a, t_node *b);
void	assign_positions(t_node *stack);
void	turk_sort(t_node **a, t_node **b);
void	sort_stack(t_node **a, t_node **b);
void	init_stack(t_node **a, int argc, char **argv);

#endif
