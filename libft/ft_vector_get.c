/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 21:39:43 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/14 23:29:23 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_vector_get(t_vector *v, int index)
{
	if (v && index >= 0 && index < v->total)
		return (v->items[index]);
	return (NULL);
}
