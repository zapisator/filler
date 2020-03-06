/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 21:38:55 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/09 21:44:20 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_vector_set(t_vector *v, int index, void *item)
{
	if (!v || index < 0 || v->total <= index)
		return (FAILURE);
	v->items[index] = item;
	return (SUCCESS);
}
