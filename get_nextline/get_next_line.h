/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:07:41 by okhan             #+#    #+#             */
/*   Updated: 2025/02/07 22:13:37 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(const char *str);
char	*ft_strdup_gnl(const char *src);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_find_newline(const char *str);

#endif