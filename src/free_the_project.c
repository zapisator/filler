/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_the_project.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:48:16 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/21 15:50:27 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void					free_plot(t_filler *filler)
{
	ft_vector_free_data(&filler->plot.rows, ft_memdel);
	ft_vector_free(&filler->plot.rows);
	filler->plot.rows.capacity = 0;
	return ;
}

void					free_map(t_filler *filler)
{
	ft_vector_free_data(&filler->map.rows, ft_memdel);
	ft_vector_free(&filler->map.rows);
	filler->map.rows.capacity = 0;
	return ;
}

void					free_all_allocated_space(t_filler *filler)
{
	free_map(filler);
	free_plot(filler);
	if (filler->state == PROJECT_ERROR)
		print_calculation_results(filler);
	else
		filler->state = PRINT_RESULT;
	return ;
}
