/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:02:56 by okhan             #+#    #+#             */
/*   Updated: 2024/11/15 17:43:54 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*t;

	i = 0;
	t = (unsigned char *)s;
	while (i < n)
	{
		t[i] = 0;
		i++;
	}
}
