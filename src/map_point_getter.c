/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_point_getter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:09:38 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/21 15:30:50 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char			*point_ptr(t_filler *filler, int x, int y)
{
	void		**items;
	char		*substr;

	items = filler->map.rows.items;
	substr = ((char *)items[y]) + x + filler->map.ofset;
	return (substr);
}

char			*point_ptr_from_plot(t_filler *filler, int x, int y)
{
	void		**items;
	char		*substr;

	items = filler->plot.rows.items;
	substr = ((char *)items[y]) + x + filler->plot.ofset;
	return (substr);
}
