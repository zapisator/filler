/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_initial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:24:11 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/21 15:39:58 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			clean_the_working_structure_of_the_filler(t_filler *filler)
{
	char		pal;
	char		foe;

	pal = filler->pal;
	foe = filler->foe;
	ft_bzero(filler, sizeof(*filler));
	filler->pal = pal;
	filler->foe = foe;
	filler->state = READ_MAP_INFO;
	return ;
}

void			figure_out_pal_and_foe_symbols(t_filler *filler)
{
	int			reader;

	while ((reader = get_next_line(STDIN, &filler->line)) > 0)
	{
		if (DEBUG_LOG)
			debug_logging(filler);
		if (ft_strstr(filler->line, EXEC_STR))
		{
			filler->pal = *(filler->line + EXEC_LEN) == '1' ? 'O' : 'X';
			filler->foe = filler->pal == 'O' ? 'X' : 'O';
			break ;
		}
		ft_memdel((void **)&filler->line);
	}
	ft_memdel((void **)&filler->line);
	if (reader <= SUCCESS)
		filler->state = PROJECT_ERROR;
	else
		filler->state = CLEAR_STRUCT;
	return ;
}
