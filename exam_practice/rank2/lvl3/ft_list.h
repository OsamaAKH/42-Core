/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhan <okhan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:13:28 by okhan             #+#    #+#             */
/*   Updated: 2025/07/21 18:39:07 by okhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_LIST_H
# define FY_LIST_H

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;


int	ft_list_size(t_list *begin_list);

#endif


