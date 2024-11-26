/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:58:52 by okhan             #+#    #+#             */
/*   Updated: 2024/11/20 21:12:14 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	final_size;
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	final_size = nmemb * size;
	if (nmemb != final_size / size)
		return (NULL);
	ptr = malloc(final_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, final_size);
	return (ptr);
}
