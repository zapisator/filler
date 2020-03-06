/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigitnstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:54:28 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/26 17:33:27 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_isdigitnstr(char *str, int n)
{
	int				decision;

	decision = !TRUE;
	if (str)
	{
		str += (*str == '+' || *str == '-') ? 1 : 0;
		while (*str && n--)
		{
			decision = ft_isdigit(*str);
			++str;
		}
	}
	return (decision);
}
