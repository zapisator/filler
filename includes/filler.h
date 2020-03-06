/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:17:41 by ftothmur          #+#    #+#             */
/*   Updated: 2019/11/21 17:52:28 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

/*
**==============================================================================
**-------------------------MACRO- AND ENUM CONSTANTS----------------------------
*/

# define DEBUG_LOG	0
# define PRINT_OUT	1

# define EXEC_STR	"$$$ exec p"
# define EXEC_LEN	10
# define PLATE_LEN	7
# define OFSET		4
# define PIECE_LEN	5

# define OPERATIONS	14

typedef enum		e_ops
{
	READ_PAL_FOE,
	CLEAR_STRUCT,
	READ_MAP_INFO,
	SKIP_COORD_LINE,
	READ_MAP,
	READ_PLOT_INFO,
	READ_PLOT,
	PUT_SCORE_TO_MAP,
	FIND_PLACEMENT,
	PRINT_MAP,
	FREE_PROJECT,
	PRINT_RESULT,
	PROJECT_ERROR
}					t_ops;

typedef enum		e_scores
{
	TOP_VALUE = 1,
	TIP_VALUE = 99,
	FOE = 126,
	PAL = 127
}					t_scores;

typedef enum		e_neighbors
{
	LEFT_NEIGHBOR,
	UPPER_NEIGHBOR,
	RIGHT_NEIGHBOR,
	LOWER_NEIGHBOR
}					t_neighbor;

/*
**----------------------END OF MACRO- AND ENUM CONSTANTS------------------------
**==============================================================================
*/

/*
**==============================================================================
**------------------------------ARBITRARY TYPES---------------------------------
*/

typedef struct		s_site
{
	int				x;
	int				y;
}					t_site;

typedef struct		s_plan
{
	int				height;
	int				width;
	int				ofset;
	t_vector		rows;
}					t_plan;

typedef struct		s_score
{
	t_site			counter;
	char			dst;
	char			src;
}					t_score;

typedef struct		s_result
{
	int				state;
	t_site			counter;
	int				pal_intersection;
	t_site			curr_site;
	int				score;
	t_site			best_site;
	int				best_score;
}					t_result;

typedef struct		s_filler_print
{
	int				x;
	int				y;
	int				width;
	int				height;
	char			point;
}					t_filler_print;

typedef struct		s_filler
{
	int				state;
	char			*line;
	char			pal;
	char			foe;
	t_plan			map;
	t_plan			plot;
	t_score			score;
	t_result		result;
	char			*point;
	FILE			*debug_fp;
}					t_filler;

typedef void		(*t_operation)(t_filler *filler);

/*
**---------------------------END OF ARBITRARY TYPES-----------------------------
**==============================================================================
*/

/*
**==============================================================================
**---------------------------FUNCTION DEFINITIONS-------------------------------
*/

/*
**-----------------------------heap management----------------------------------
*/

/*
**								  symmetric
*/
void				figure_out_pal_and_foe_symbols(t_filler *filler);
void				find_out_the_spatial_characteristics_of_the_map(
						t_filler *filler);
void				skip_coordinate_line_for_x(t_filler *filler);
void				find_out_the_spatial_characteristics_of_the_plot(
						t_filler *filler);

/*
**			                       allocate
*/
void				fill_the_map_vector_with_width_lines(t_filler *filler);
void				fill_the_plot_vector_with_width_lines(t_filler *filler);

/*
**                                deallocate
*/
void				free_map(t_filler *filler);
void				free_plot(t_filler *filler);

/*
**---------------------------------common---------------------------------------
*/
void				clean_the_working_structure_of_the_filler(t_filler *filler);
void				figure_out_pal_and_foe_symbols(t_filler *filler);
void				find_out_the_spatial_characteristics_of_the_map(
						t_filler *filler);
void				skip_coordinate_line(t_filler *filler);
void				fill_the_map_vector_with_width_lines(t_filler *filler);
void				find_out_the_spatial_characteristics_of_the_plot(
						t_filler *filler);
void				fill_the_plot_vector_with_width_lines(t_filler *filler);
void				assign_score_to_each_point_on_the_map(t_filler *filler);
void				find_the_best_placement(t_filler *filler);
void				print_calculation_results(t_filler *filler);
void				free_all_allocated_space(t_filler *filler);
void				print_calculation_results(t_filler *filler);

/*
**-----------------------------------read---------------------------------------
*/
void				find_a_substring_for_the_width_value(char *line,
						char **width);
void				find_a_substring_for_the_height_value(char *line,
						char **height, int ismap);
/*
**-----------------------------------map----------------------------------------
*/
void				set_limits_for_the_counter_by_y(t_filler *filler);
void				set_limits_for_the_counter_by_x(t_filler *filler);
void				set_point_by_x_and_y(t_filler *filler);
void				score_points_to_four_neighbors(t_filler *filler);
char				*point_ptr(t_filler *filler, int x, int y);
int					allowed_to_replace_the_score(t_filler *filler,
						t_site neighbor);
int					is_pal_point(t_filler *filler);
int					is_foe_point(t_filler *filler);
void				assign_initial_score_to_points_for_each_x_and_y(
						t_filler *filler);
void				put_top_score_end_to_end_with_the_foe(t_filler *filler);
void				put_other_scores(t_filler *filler);

/*
**-----------------------------------plot---------------------------------------
*/
void				set_y_plot_placment_limits(t_filler *filler);
void				set_x_plot_placment_limits(t_filler *filler);
void				count_scores_for_each_x_and_y_placement(t_filler *filler);
char				*point_ptr_from_plot(t_filler *filler, int x, int y);
/*
**----------------------------------score---------------------------------------
*/
void				add_current_score_to_the_score_pool(t_filler *filler);
void				set_limits_for_the_counter_by_y_for_plot(t_filler *filler);
void				set_limits_for_the_counter_by_x_for_plot(t_filler *filler);
void				set_counter_to_bypass_plot_at_y(t_filler *filler);
void				set_counter_to_bypass_plot_at_x(t_filler *filler);
int					is_current_score_better_than_before(t_filler *filler);
int					is_the_initial_score(t_filler *filler);
void				keep_the_result_in_the_best(t_filler *filler);
int					had_find_proper_location(t_filler *filler);
int					is_allowed_to_score(t_filler *filler);
void				clean_current_score_statistics(t_filler *filler);
void				write_down_the_coordinates_of_the_plot_placement(
						t_filler *filler);

/*
**----------------------------------result--------------------------------------
*/

/*
**--------------------------------visualizer------------------------------------
*/
void				print_map(t_filler *filler);
/*
**----------------------------------debug---------------------------------------
*/
void				debug_logging(t_filler *filler);

/*
**------------------------END OF FUNCTION DEFINITIONS---------------------------
**==============================================================================
*/

#endif
