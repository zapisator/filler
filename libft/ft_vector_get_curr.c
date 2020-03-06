/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_get_curr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 23:29:11 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/14 23:31:38 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_vector_get_curr(t_vector *v)
{
	if (v && v->total > 0)
		return (v->items[v->total - 1]);
	return (NULL);
}
