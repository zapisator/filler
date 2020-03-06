/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_runs_through_points.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:16:02 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/21 15:46:05 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		count_scores_for_each_x_placement(t_filler *filler)
{
	set_counter_to_bypass_plot_at_x(filler);
	while (filler->result.counter.x-- && filler->result.state != FAILURE)
	{
		write_down_the_coordinates_of_the_plot_placement(filler);
		if (is_allowed_to_score(filler))
			add_current_score_to_the_score_pool(filler);
	}
	if (filler->result.state == FAILURE)
	{
		ft_bzero((void *)&filler->result.curr_site,
				sizeof(filler->result.curr_site));
		filler->result.score = 0;
	}
	return ;
}

void			count_scores_for_each_x_and_y_placement(t_filler *filler)
{
	clean_current_score_statistics(filler);
	set_counter_to_bypass_plot_at_y(filler);
	while (filler->result.counter.y-- && filler->result.state != FAILURE)
		count_scores_for_each_x_placement(filler);
	if (had_find_proper_location(filler))
	{
		if (is_the_initial_score(filler) ||
				is_current_score_better_than_before(filler))
			keep_the_result_in_the_best(filler);
	}
	return ;
}
