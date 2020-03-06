/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 21:30:23 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/12 16:46:44 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_vector_add(t_vector *v, void *item)
{
	if (!v ||
			(v->capacity == v->total &&
			ft_vector_resize(v, (ssize_t)v->capacity * 2) == FAILURE))
		return (FAILURE);
	v->items[v->total++] = item;
	return (SUCCESS);
}
