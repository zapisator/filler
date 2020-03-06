/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_counter_setters.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:01:06 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/18 23:40:37 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			set_limits_for_the_counter_by_y_for_plot(t_filler *filler)
{
	filler->score.counter.y = filler->map.height - (filler->plot.height - 1);
	return ;
}

void			set_limits_for_the_counter_by_x_for_plot(t_filler *filler)
{
	filler->score.counter.x = filler->map.width - (filler->plot.width - 1);
	return ;
}

void			set_counter_to_bypass_plot_at_y(t_filler *filler)
{
	filler->result.counter.y = filler->plot.height;
	return ;
}

void			set_counter_to_bypass_plot_at_x(t_filler *filler)
{
	filler->result.counter.x = filler->plot.width;
	return ;
}
