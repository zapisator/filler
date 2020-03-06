/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_void_arithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:16:01 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/12 16:19:51 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			**ft_void_arithm(void **ptr, int offset)
{
	void		**offset_ptr;

	offset_ptr = ptr + offset * sizeof(void *);
	return (offset_ptr);
}
