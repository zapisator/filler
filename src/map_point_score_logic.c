/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_point_score_logic.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:17:07 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/21 15:33:25 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				is_pal_point(t_filler *filler)
{
	int			result;

	result = *filler->point == filler->pal ||
			ft_toupper(*filler->point) == (int)filler->pal;
	return (result);
}

int				is_foe_point(t_filler *filler)
{
	int			result;

	result = *filler->point == filler->foe ||
			ft_toupper(*filler->point) == (int)filler->foe;
	return (result);
}

int				allowed_to_replace_the_score(t_filler *filler,
					t_site neighbor)
{
	int			decision;
	char		point;

	decision =
				neighbor.x >= 0 &&
				neighbor.x <= filler->map.width - 1 &&
				neighbor.y >= 0 &&
				neighbor.y <= filler->map.height - 1;
	if (decision)
	{
		point = *point_ptr(filler, neighbor.x, neighbor.y);
		decision =
				point != FOE &&
				point != PAL &&
				point > filler->score.src;
	}
	return (decision);
}
