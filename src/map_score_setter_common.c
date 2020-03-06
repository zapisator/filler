/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_score_setter_common.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:12:41 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/21 15:32:45 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			assign_score_to_each_point_on_the_map(t_filler *filler)
{
	assign_initial_score_to_points_for_each_x_and_y(filler);
	put_top_score_end_to_end_with_the_foe(filler);
	put_other_scores(filler);
	filler->state = FIND_PLACEMENT;
	return ;
}
