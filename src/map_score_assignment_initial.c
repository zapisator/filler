/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_score_assignment_initial.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:15:20 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/18 21:10:11 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		assign_the_appropriate_score_to_the_point(t_filler *filler)
{
	set_point_by_x_and_y(filler);
	if (is_pal_point(filler))
		*filler->point = PAL;
	else if (is_foe_point(filler))
		*filler->point = FOE;
	else
		*filler->point = TIP_VALUE;
	return ;
}

static void		assign_initial_score_to_points_for_each_x(t_filler *filler)
{
	set_limits_for_the_counter_by_x(filler);
	while (filler->score.counter.x--)
		assign_the_appropriate_score_to_the_point(filler);
	return ;
}

void			assign_initial_score_to_points_for_each_x_and_y(
					t_filler *filler)
{
	set_limits_for_the_counter_by_y(filler);
	while (filler->score.counter.y--)
		assign_initial_score_to_points_for_each_x(filler);
	return ;
}
