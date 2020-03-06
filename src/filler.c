/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:13:31 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/21 17:52:05 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void					print_calculation_results(t_filler *filler)
{
	ft_putnbr(filler->result.best_site.y);
	write(1, " ", 1);
	ft_putnbr(filler->result.best_site.x);
	write(1, "\n", 1);
	if (filler->state == PROJECT_ERROR)
		filler->state = FAILURE;
	else
		filler->state = CLEAR_STRUCT;
	return ;
}

void					debug_logging(t_filler *filler)
{
	filler->debug_fp = fopen("debug", "a");
	fprintf(filler->debug_fp, "%s\n", filler->line);
	fclose(filler->debug_fp);
	return ;
}

void					project_error_management(t_filler *filler)
{
	free_all_allocated_space(filler);
	return ;
}

void					initialize_filler_to_zero(t_filler *filler)
{
	ft_bzero((void *)filler, sizeof(*filler));
	return ;
}

int						main(void)
{
	t_filler			filler;
	static t_operation	dispatcher[OPERATIONS] = {
		figure_out_pal_and_foe_symbols,
		clean_the_working_structure_of_the_filler,
		find_out_the_spatial_characteristics_of_the_map,
		skip_coordinate_line,
		fill_the_map_vector_with_width_lines,
		find_out_the_spatial_characteristics_of_the_plot,
		fill_the_plot_vector_with_width_lines,
		assign_score_to_each_point_on_the_map,
		find_the_best_placement,
		print_map,
		free_all_allocated_space,
		print_calculation_results,
		project_error_management
	};

	initialize_filler_to_zero(&filler);
	while (TRUE)
	{
		(*dispatcher[filler.state])(&filler);
		if (filler.state <= SUCCESS)
			break ;
	}
	return (filler.state);
}
