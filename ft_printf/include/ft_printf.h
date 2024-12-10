/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:31:38 by marvin            #+#    #+#             */
/*   Updated: 2024/12/08 21:31:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_prthexa(unsigned int num, char *base);
int	ft_printnbr(int n);
int	ft_printptr(void *ptr, char *base);
int	ft_putchar(char c);
int	ft_printstr(char *str);
int	ft_prtunsigned(unsigned int num);

#endif