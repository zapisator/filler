/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_skip_coordinate_line.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:42:50 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/21 15:43:10 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			skip_coordinate_line(t_filler *filler)
{
	int			reader;

	reader = get_next_line(STDIN, &filler->line);
	if (reader <= 0)
	{
		filler->state = PROJECT_ERROR;
		return ;
	}
	if (DEBUG_LOG)
		debug_logging(filler);
	ft_memdel((void **)&filler->line);
	filler->state = READ_MAP;
	return ;
}
