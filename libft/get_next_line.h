/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:18:38 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/21 14:15:47 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
** including system and own libraries
**		stdlib			malloc(), free()
**		unistd			read(), ssize_t
*/
# include "libft.h"

/*
** BUFF_SIZE for read function
** BUFF_SIZE 4096 because optimum I/O blocksize $>: stat -f %k filename
** return values of GNL:
**		FD_LIMIT		maximum fd nuber is result of "?> ulimit -Sn"
**		END_OF_LINE		heapens when '\n' or '\0', or EOF has been reached
**		ITER_DONE		no errors, but there were not an end of line
**		ERROR			error occured during execution
*/
# define BUFF_SIZE			16
# define FD_LIMIT			4864
# define NO_MORE_LINES		0
# define ONE_MORE_LINE		1

# define EXAMINE_STATUS		0
# define FILL				1
# define PARSE_CONCATENATE	2
# define SUCCESSFULL_END	3
# define ERRONEOUS_END		4

# define GL_OPERATIONS		10

/*
** Structure synonym for input file.
*/
typedef struct				s_file
{
	int						fd;
	char					*file;
	ssize_t					file_size;
	const char				*mark;
}							t_file;

typedef struct				s_buffer
{
	int						fd;
	char					**line;
	int						state;
	long					size;
	char					data[BUFF_SIZE];
	long					load;
	char					*top;
	char					*tip;
}							t_buffer;

typedef struct				s_line
{
	int						fd;
	char					*line;
	struct s_line			*next;
}							t_line;

/*
**typedef void				(*t_gl_ops)(t_gl *gl);
**
**typedef						s_gnl_reader
**{
**	int						fd;
**	char					**line;
**	int						line_len;
**}							t_gnl_reader;
*/

/*
**typedef struct				s_gl
**{
**	int						state;
**	t_gnl_reader			reader;
**	char					buffer[BUFF_SIZE + 1];
**	int						load;
**	int						drop;
**	char					*section;
**	int						section_len;
**}							t_gl;
*/

/*
** system functions. Other functions definitions or declarations with needed
** lib are in libft.h
**		malloc, free
**
** Here we need to use read(). It`s protoripe is
** ssize_t	read(int fd, void *buf, size_t count);
*/

int							ft_get_next_line(const int fd, char **line);
t_line						*ft_linedelone(t_line *start, t_line *todel);

#endif
