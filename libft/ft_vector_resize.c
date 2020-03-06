/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 21:28:48 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/09 21:52:29 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_vector_resize(t_vector *v, ssize_t capacity)
{
	if (v && capacity * (sizeof(*v->items)) <= INT_MAX &&
			!ft_realloc_safe((void **)&v->items, v->capacity,
			sizeof(*v->items) * capacity))
	{
		v->capacity = capacity;
		return (SUCCESS);
	}
	return (FAILURE);
}
