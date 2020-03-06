/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_counter_setters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:01:20 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/18 22:59:54 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			set_y_plot_placment_limits(t_filler *filler)
{
	filler->result.counter.y = filler->score.counter.y + 1;
	return ;
}

void			set_x_plot_placment_limits(t_filler *filler)
{
	filler->result.counter.x = filler->score.counter.x + 1;
	return ;
}
