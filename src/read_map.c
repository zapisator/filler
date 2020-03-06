/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:22:21 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/21 15:43:37 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			find_a_substring_for_the_height_value(char *line, char **height,
					int ismap)
{
	*height = line + (ismap ? PLATE_LEN : PIECE_LEN);
	return ;
}

void			find_a_substring_for_the_width_value(char *line, char **width)
{
	while (ft_isspace(*line))
		++line;
	while (ft_isdigit(*line))
		++line;
	*width = line;
	return ;
}

void			find_out_the_spatial_characteristics_of_the_map(
					t_filler *filler)
{
	char		*height;
	char		*width;
	int			reader;

	reader = get_next_line(STDIN, &filler->line);
	if (reader <= 0)
	{
		filler->state = !reader ? SUCCESS : FAILURE;
		return ;
	}
	if (DEBUG_LOG)
		debug_logging(filler);
	find_a_substring_for_the_height_value(filler->line, &height, TRUE);
	filler->map.height = ft_atoi(height);
	find_a_substring_for_the_width_value(height, &width);
	filler->map.width = ft_atoi(width);
	ft_memdel((void **)&filler->line);
	filler->state = SKIP_COORD_LINE;
	return ;
}

void			read_map_initializer(t_filler *filler, int *lines_left_to_read)
{
	*lines_left_to_read = filler->map.height;
	filler->map.ofset = OFSET;
	if (ft_vector_init(&filler->map.rows))
	{
		filler->state = FAILURE;
		return ;
	}
	return ;
}

void			fill_the_map_vector_with_width_lines(t_filler *filler)
{
	int			lines_left_to_read;
	int			reader;

	read_map_initializer(filler, &lines_left_to_read);
	if (filler->state != FAILURE)
	{
		while (lines_left_to_read--)
		{
			reader = get_next_line(STDIN, &filler->line);
			if (reader <= 0 || ft_vector_add(&filler->map.rows, filler->line))
			{
				filler->state = PROJECT_ERROR;
				return ;
			}
			if (DEBUG_LOG)
				debug_logging(filler);
		}
		filler->state = READ_PLOT_INFO;
	}
	return ;
}
