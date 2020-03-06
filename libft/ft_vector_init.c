/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:44:23 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/20 16:38:14 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_vector_init(t_vector *v)
{
	if (!v || !(v->items = (void **)ft_memalloc(sizeof(*v->items) *
			VECTOR_INIT_CAP)))
		return (FAILURE);
	v->capacity = VECTOR_INIT_CAP;
	v->total = 0;
	return (SUCCESS);
}
