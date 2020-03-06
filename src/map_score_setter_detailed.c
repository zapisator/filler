/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_score_setter_detailed.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:13:18 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/21 15:35:05 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		for_the_point_put_score_for_its_four_neighbors_if_possible(
					t_filler *filler)
{
	filler->point = point_ptr(filler,
				filler->score.counter.x, filler->score.counter.y);
	if (*filler->point == filler->score.dst)
		score_points_to_four_neighbors(filler);
	return ;
}

static void		put_scores_for_each_x(t_filler *filler)
{
	set_limits_for_the_counter_by_x(filler);
	while (filler->score.counter.x--)
		for_the_point_put_score_for_its_four_neighbors_if_possible(filler);
	return ;
}

static void		put_scores_for_each_x_and_y(t_filler *filler)
{
	set_limits_for_the_counter_by_y(filler);
	while (filler->score.counter.y--)
		put_scores_for_each_x(filler);
	return ;
}

void			put_top_score_end_to_end_with_the_foe(t_filler *filler)
{
	filler->score.dst = FOE;
	filler->score.src = TOP_VALUE;
	put_scores_for_each_x_and_y(filler);
	return ;
}

void			put_other_scores(t_filler *filler)
{
	filler->score.dst = TOP_VALUE;
	filler->score.src = TOP_VALUE + 1;
	while (filler->score.src < TIP_VALUE)
	{
		put_scores_for_each_x_and_y(filler);
		++filler->score.dst;
		++filler->score.src;
	}
	return ;
}
