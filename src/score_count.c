/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:54:25 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/21 15:38:07 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			write_down_the_coordinates_of_the_plot_placement(
					t_filler *filler)
{
	filler->result.curr_site.x =
				filler->score.counter.x;
	filler->result.curr_site.y =
				filler->score.counter.y;
	return ;
}

void			clean_current_score_statistics(t_filler *filler)
{
	t_site		best_site;
	int			best_score;

	best_site = filler->result.best_site;
	best_score = filler->result.best_score;
	ft_bzero(&filler->result, sizeof(filler->result));
	filler->result.best_site = best_site;
	filler->result.best_score = best_score;
	return ;
}

void			add_current_score_to_the_score_pool(t_filler *filler)
{
	int			x;
	int			y;
	char		point;

	x = filler->result.curr_site.x + filler->result.counter.x;
	y = filler->result.curr_site.y + filler->result.counter.y;
	point = *point_ptr(filler, x, y);
	filler->result.score += point;
	return ;
}
