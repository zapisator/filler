/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_safe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 20:46:27 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/09 21:06:28 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_realloc_safe(void **buf1, size_t size1, size_t size2)
{
	void		*buf2;

	buf2 = NULL;
	if ((size2 && size1 && *buf1) || (size2 && !size1 && !*buf1))
		if (!(buf2 = ft_memalloc(size2)))
			return (FAILURE);
	if (*buf1 && buf2 && size1 && size2)
		(void)ft_memcpy(buf2, *buf1, size1 > size2 ? size2 : size1);
	free(*buf1);
	*buf1 = buf2;
	return (SUCCESS);
}
