/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 21:40:26 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/12 16:46:52 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_vector_delete(t_vector *v, int index)
{
	int				i;

	if (!v || index < 0 || index >= v->total)
		return (FAILURE);
	v->items[index] = NULL;
	i = index;
	while (i < v->total - 1)
	{
		v->items[i] = v->items[i + 1];
		v->items[i + 1] = NULL;
		++i;
	}
	--v->total;
	if (v->total > 0 && v->total == v->capacity / 4)
		if (ft_vector_resize(v, v->capacity / 2) == FAILURE)
			return (FAILURE);
	return (SUCCESS);
}
