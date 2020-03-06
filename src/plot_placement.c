/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_placement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:13:31 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/21 17:51:34 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		count_score_for_each_x_plot_placement_and_remember_the_best(
					t_filler *filler)
{
	set_limits_for_the_counter_by_x_for_plot(filler);
	while (filler->score.counter.x--)
		count_scores_for_each_x_and_y_placement(filler);
	return ;
}

void			find_the_best_placement(t_filler *filler)
{
	set_limits_for_the_counter_by_y_for_plot(filler);
	while (filler->score.counter.y--)
		count_score_for_each_x_plot_placement_and_remember_the_best(filler);
	filler->state = PRINT_OUT ? PRINT_MAP : FREE_PROJECT;
	return ;
}
