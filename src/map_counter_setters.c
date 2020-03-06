/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_counter_setters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:04:43 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/18 23:11:37 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			set_limits_for_the_counter_by_y(t_filler *filler)
{
	filler->score.counter.y = filler->map.height;
	return ;
}

void			set_limits_for_the_counter_by_x(t_filler *filler)
{
	filler->score.counter.x = filler->map.width;
	return ;
}
