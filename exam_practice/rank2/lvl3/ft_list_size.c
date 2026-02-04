/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:11:47 by okhan             #+#    #+#             */
/*   Updated: 2025/07/21 15:18:51 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "stddef.h"

int	ft_list_size(t_list *begin_list)
{
	int count = 0;
	t_list *current = begin_list;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}