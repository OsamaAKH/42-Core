/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:09:29 by okhan             #+#    #+#             */
/*   Updated: 2025/07/20 20:15:47 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;
	size_t j;
	size_t found;

	while (s[i])
	{
		j = 0; 
		found = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
			{
				found = 1;
				break;
			}
			j++;
		}
		if (!found)
			break;
		i++;
	}
	return (i);
}