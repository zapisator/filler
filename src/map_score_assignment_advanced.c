/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_score_assignment_advanced.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:11:30 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/21 15:33:45 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			set_point_by_x_and_y(t_filler *filler)
{
	filler->point = point_ptr(filler,
			filler->score.counter.x, filler->score.counter.y);
	return ;
}

static void		replace_the_score(t_filler *filler, t_site neighbor)
{
	char		*point;

	point = point_ptr(filler, neighbor.x, neighbor.y);
	*point = filler->score.src;
	return ;
}

static void		set_neighbors(t_filler *filler, t_site neighbors[4])
{
	neighbors[LEFT_NEIGHBOR].x = filler->score.counter.x - 1;
	neighbors[LEFT_NEIGHBOR].y = filler->score.counter.y;
	neighbors[UPPER_NEIGHBOR].x = filler->score.counter.x;
	neighbors[UPPER_NEIGHBOR].y = filler->score.counter.y - 1;
	neighbors[RIGHT_NEIGHBOR].x = filler->score.counter.x + 1;
	neighbors[RIGHT_NEIGHBOR].y = filler->score.counter.y;
	neighbors[LOWER_NEIGHBOR].x = filler->score.counter.x;
	neighbors[LOWER_NEIGHBOR].y = filler->score.counter.y + 1;
	return ;
}

void			score_points_to_four_neighbors(t_filler *filler)
{
	t_site		neighbors[4];
	int			neighbor_i;

	set_neighbors(filler, neighbors);
	neighbor_i = LEFT_NEIGHBOR;
	while (neighbor_i <= LOWER_NEIGHBOR)
	{
		if (allowed_to_replace_the_score(filler, neighbors[neighbor_i]))
			replace_the_score(filler, neighbors[neighbor_i]);
		++neighbor_i;
	}
	return ;
}
