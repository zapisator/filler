/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_count_logic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:56:23 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/21 15:37:39 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				had_find_proper_location(t_filler *filler)
{
	int			decision;

	decision =
				filler->result.state != FAILURE &&
				filler->result.pal_intersection == 1;
	return (decision);
}

static char		*get_appropriate_point_from_map(t_filler *filler)
{
	int			x;
	int			y;
	char		*point_map;

	x = filler->result.curr_site.x + filler->result.counter.x;
	y = filler->result.curr_site.y + filler->result.counter.y;
	point_map = point_ptr(filler, x, y);
	return (point_map);
}

static char		*get_appropriate_point_from_plot(t_filler *filler)
{
	int			x;
	int			y;
	char		*point_plot;

	x = filler->result.counter.x;
	y = filler->result.counter.y;
	point_plot = point_ptr_from_plot(filler, x, y);
	return (point_plot);
}

int				is_allowed_to_score(t_filler *filler)
{
	int			decision;
	char		point_map;
	char		point_plot;

	point_map = *get_appropriate_point_from_map(filler);
	point_plot = *get_appropriate_point_from_plot(filler);
	filler->result.pal_intersection +=
				(point_map == PAL) && (point_plot == '*');
	if (!(filler->result.pal_intersection <= 1) ||
			(point_map == FOE && point_plot == '*'))
		filler->result.state = FAILURE;
	decision =
				point_plot == '*' &&
				filler->result.state != FAILURE;
	return (decision);
}
