/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_plot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:21:08 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/21 15:41:47 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			find_out_the_spatial_characteristics_of_the_plot(
					t_filler *filler)
{
	char		*height;
	char		*width;
	int			reader;

	reader = get_next_line(STDIN, &filler->line);
	if (reader <= 0)
	{
		filler->state = PROJECT_ERROR;
		return ;
	}
	if (DEBUG_LOG)
		debug_logging(filler);
	find_a_substring_for_the_height_value(filler->line, &height, FALSE);
	filler->plot.height = ft_atoi(height);
	find_a_substring_for_the_width_value(height, &width);
	filler->plot.width = ft_atoi(width);
	ft_memdel((void **)&filler->line);
	filler->state = READ_PLOT;
	return ;
}

void			read_plot_initializer(t_filler *filler, int *lines_left_to_read)
{
	*lines_left_to_read = filler->plot.height;
	filler->plot.ofset = !OFSET;
	if (ft_vector_init(&filler->plot.rows))
	{
		filler->state = PROJECT_ERROR;
		return ;
	}
	return ;
}

void			fill_the_plot_vector_with_width_lines(t_filler *filler)
{
	int			lines_left_to_read;
	int			reader;

	read_plot_initializer(filler, &lines_left_to_read);
	if (filler->state != PROJECT_ERROR)
	{
		while (lines_left_to_read--)
		{
			reader = get_next_line(STDIN, &filler->line);
			if (reader <= 0 || ft_vector_add(&filler->plot.rows, filler->line))
			{
				filler->state = PROJECT_ERROR;
				return ;
			}
			if (DEBUG_LOG)
				debug_logging(filler);
		}
		filler->state = PUT_SCORE_TO_MAP;
	}
	return ;
}
