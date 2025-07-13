/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:43:38 by okhan             #+#    #+#             */
/*   Updated: 2025/07/13 14:46:33 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static	void	ft_bubble_sort(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size -1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] > arr[j + 1])
				ft_swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

static int	*create_sorted_array(t_node *stack, int size)
{
	int		*arr;
	int		i;
	t_node	*tmp;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	tmp = stack;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	ft_bubble_sort(arr, size);
	return (arr);
}

static int	binary_search(int *arr, int size, int target)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] == target)
			return (mid);
		if (arr[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

void	assign_index(t_node *stack)
{
	int		*sorted_arr;
	int		size;
	t_node	*tmp;

	if (!stack)
		return ;
	size = stack_size(stack);
	sorted_arr = create_sorted_array(stack, size);
	if (!sorted_arr)
		return ;
	tmp = stack;
	while (tmp)
	{
		tmp->index = binary_search(sorted_arr, size, tmp->value);
		tmp = tmp->next;
	}
	free(sorted_arr);
}
