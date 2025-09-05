/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 22:01:22 by okhan             #+#    #+#             */
/*   Updated: 2025/09/03 14:06:42 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

unsigned char	reverse_bits(unsigned char octet)
{
	int i = 7;
	unsigned char result = 0;

	while (i >= 0)
	{
		result = (result << 1) | (octet & 1);
		octet = octet >> 1;
		i--;
	}
	return (result);
}