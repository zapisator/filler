/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:52:37 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/21 17:54:38 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void				initialize(t_filler *filler, t_filler_print *p)
{
	p->height = filler->map.height;
	p->y = 0;
	filler->debug_fp = fopen("debug", "a");
	return ;
}

static void				colorize(t_filler *filler, char *point)
{
	if (*point == FOE)
	{
		fprintf(filler->debug_fp, B_RD_L);
		*point = 0;
	}
	if (*point == PAL)
	{
		fprintf(filler->debug_fp, B_CY_L);
		*point = 0;
	}
	return ;
}

static void				terminate(t_filler *filler)
{
	fprintf(filler->debug_fp, "\"\n");
	fprintf(filler->debug_fp, "sleep 0.3\n");
	fprintf(filler->debug_fp, "\e[2J\n");
	fclose(filler->debug_fp);
	return ;
}

void					print_map(t_filler *filler)
{
	t_filler_print		p;

	initialize(filler, &p);
	fprintf(filler->debug_fp, "echo \"");
	while (p.height--)
	{
		p.width = filler->map.width;
		p.x = 0;
		while (p.width--)
		{
			p.point = *point_ptr(filler, p.x, p.y);
			colorize(filler, &p.point);
			fprintf(filler->debug_fp, "%.2i", (int)p.point);
			++p.x;
			if (!p.point)
				fprintf(filler->debug_fp, CL);
			fprintf(filler->debug_fp, "|");
		}
		fprintf(filler->debug_fp, "\n");
		++p.y;
	}
	terminate(filler);
	filler->state = FREE_PROJECT;
	return ;
}
