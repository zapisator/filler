/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:02:15 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/20 18:54:01 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				initialize(int fd, char **line, t_buffer *buf)
{
	if (fd < 0 || !line || BUFF_SIZE <= 0 || BUFF_SIZE > 8388608 ||
			read(fd, NULL, 0) == FAILURE)
		return (FAILURE);
	if ((*buf->data && (buf->data + buf->load - 1 > buf->tip) &&
				fd != buf->fd) ||
			(*buf->data && (buf->data + buf->load - 1 == buf->tip)) ||
			buf->size < 0 || !buf->load)
		ft_bzero((void *)buf, sizeof(*buf));
	buf->fd = fd;
	*line = NULL;
	buf->line = line;
	buf->state = EXAMINE_STATUS;
	buf->size = 0;
	return (SUCCESS);
}

static int				examine_status(t_buffer *buf)
{
	if (!*buf->data || (*buf->data && (buf->data + buf->load - 1 == buf->tip)))
		buf->state = FILL;
	else
	{
		if (!buf->top)
			buf->top = buf->data;
		else
			buf->top = buf->tip + 1;
		buf->state = PARSE_CONCATENATE;
	}
	return (buf->state);
}

static int				fill(t_buffer *buf)
{
	if ((buf->load = read(buf->fd, buf->data, BUFF_SIZE)) <= 0)
	{
		buf->state = !buf->load ? SUCCESSFULL_END : ERRONEOUS_END;
		if (buf->state == SUCCESSFULL_END && !*buf->data)
			buf->size = 0;
	}
	else
	{
		buf->state = EXAMINE_STATUS;
		buf->top = NULL;
		buf->tip = NULL;
	}
	return (buf->state);
}

static int				parse_and_concatenate(t_buffer *buf)
{
	long				additive;

	if (!(buf->tip = ft_strnchr(buf->top, '\n',
			buf->load - (buf->top - buf->data))))
		buf->tip = buf->data + buf->load - 1;
	additive = buf->tip - buf->top + 1 +
				(!*buf->tip || *buf->tip == '\n' ? 0 : 1);
	if (ft_realloc_safe((void *)buf->line, buf->size, buf->size + additive))
		return (buf->state = ERRONEOUS_END);
	(void)ft_memcpy((void *)*buf->line + buf->size, buf->top, additive - 1);
	buf->size += additive;
	if (!*buf->tip || *buf->tip == '\n')
	{
		buf->state = SUCCESSFULL_END;
		if (*buf->tip == '\n')
			*(*buf->line + buf->size - 1) = '\0';
	}
	else
		buf->state = EXAMINE_STATUS;
	return (buf->state);
}

int						ft_getline(int fd, char **line)
{
	static t_buffer	buf;

	if (!initialize(fd, line, &buf))
	{
		while (buf.state < SUCCESSFULL_END)
		{
			if (buf.state == EXAMINE_STATUS)
				buf.state = examine_status(&buf);
			if (buf.state == FILL)
				buf.state = fill(&buf);
			if (buf.state == PARSE_CONCATENATE)
				buf.state = parse_and_concatenate(&buf);
		}
	}
	else
		buf.state = ERRONEOUS_END;
	if (buf.state == ERRONEOUS_END)
		buf.size = FAILURE;
	return (buf.size);
}
