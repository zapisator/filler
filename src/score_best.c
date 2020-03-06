/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_best.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:51:10 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/21 15:35:33 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				is_current_score_better_than_before(t_filler *filler)
{
	int			decision;

	decision =
				filler->result.score < filler->result.best_score;
	return (decision);
}

int				is_the_initial_score(t_filler *filler)
{
	int			decision;

	decision =
				!filler->result.best_score;
	return (decision);
}

void			keep_the_result_in_the_best(t_filler *filler)
{
	filler->result.best_score = filler->result.score;
	filler->result.best_site = filler->result.curr_site;
	return ;
}
