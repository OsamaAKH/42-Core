/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:05:50 by okhan             #+#    #+#             */
/*   Updated: 2025/08/13 19:24:42 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int	tmp;
	t_list *cur;

	if(!lst)
		return (0);
	cur = lst;
	while (lst->next)
	{
		if (!(cmp(lst->data, lst->next->data)))
		{
			tmp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = tmp;
			lst = cur;
		}
		else
			lst = lst->next;
	}
	return (cur);
}