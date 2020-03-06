# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 18:21:00 by ftothmur          #+#    #+#              #
#    Updated: 2019/11/21 17:03:02 by ftothmur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#================================COLORS & Co===================================#
GREEN =		\033[1;32m
RED =		\033[1;31m
RST =		\033[0m
BOLD =		\033[1m
CYAN =		\033[1;36m
PREFIX =	[$(CYAN)filler$(RST)]:\t

#====================================LIB=======================================#
#---------------------------------directories----------------------------------#
LIB_DIR			:=	./libft/
LIB_HDR_DIR		:=	$(LIB_DIR)
#---------------------------------ftothmur lib---------------------------------#
LIB				:=	$(LIB_DIR)libft.a
#===================================PROJECT====================================#
#---------------------------------directories----------------------------------#
NAME_DIR		:=	./
NAME_HDR_DIR	:=	$(NAME_DIR)includes/
NAME_OBJ_DIR	:=	$(NAME_DIR)
NAME_SRC_DIR	:=	$(NAME_DIR)src/
#------------------------------------files-------------------------------------#
NAME			:=	ftothmur.filler
MAIN_SRC		:=	$(addprefix $(NAME_SRC_DIR),filler.c)
READ_SRC		:=	$(addprefix $(NAME_SRC_DIR),read_initial.c read_map.c \
read_plot.c read_skip_coordinate_line.c)
MAP_SRC			:=	$(addprefix $(NAME_SRC_DIR),map_counter_setters.c \
map_point_getter.c map_score_assignment_initial.c map_score_setter_detailed.c \
map_score_assignment_advanced.c map_point_score_logic.c \
map_score_setter_common.c)
PLOT_SRC		:=	$(addprefix $(NAME_SRC_DIR),plot_counter_setters.c \
plot_placement.c plot_runs_through_points.c)
SCORE_SRC		:=	$(addprefix $(NAME_SRC_DIR),score_best.c \
score_count.c score_count_logic.c score_counter_setters.c)
FREE_PROJECT	:=	$(addprefix $(NAME_SRC_DIR),free_the_project.c)
VISUALIZER		:=	$(addprefix $(NAME_SRC_DIR),visualizer.c)
SRC				:=	$(MAIN_SRC) $(READ_SRC) $(MAP_SRC) $(PLOT_SRC) \
$(SCORE_SRC) $(FREE_PROJECT) $(VISUALIZER)
OBJ				:=	$(patsubst %.c,%.o, $(SRC))
#----------------------------------includes------------------------------------#
LIB_HDR			:=	$(LIB_HDR_DIR)libft.h
NAME_HDR		:=	$(NAME_HDR_DIR)filler.h
HEADERS			:=	$(LIB_HDR) $(NAME_HDR)
#------------------------------------flags-------------------------------------#
ifeq ($(DEBUG), 1)
	CFLAGS		:=	-Wall -Wextra -Werror -g
	DEBUGMSG	:= $(PREFIX)⚠️  \033[1;33mDebug mode $(GREEN)enabled.$(RST)\n
else
	CFLAGS		:=	-Wall -Wextra -Werror
	DEBUGMSG	:= $(PREFIX)⚠️  \033[1;33mDebug mode $(RED)disabled.$(RST)\n
endif
LIB_FLAGS		:=	-L$(LIB_DIR) -lft
HDR_FLAGS		:=	-I$(NAME_HDR_DIR) -I$(LIB_HDR_DIR)
#===================================RULES======================================#
all:				lib $(NAME)
				@echo "$(PREFIX)✅  $(GREEN)All files up-to-date or \
rebuilded.$(RST)"

$(NAME):			$(SRC) $(OBJ) $(HEADERS) $(LIB)
				@printf "%-145c\r$(PREFIX)✅  $(GREEN)All \
obj-files accepted.$(RST)\n" ' '
				@printf "$(PREFIX)📦  Building filler...\n"
				@gcc -o $(NAME) $(OBJ) $(HDR_FLAGS) $(LIB_FLAGS) $(CFLAGS)

$(LIB):				lib

lib:
				@printf "$(DEBUGMSG)$(PREFIX)$(BOLD)🔎  Checkig \
for libft updates...$(RST)\n"
				@make -C $(LIB_DIR) DEBUG=$(DEBUG)

%.o:				%.c
				@printf "%-145c\r$(PREFIX)🕐  Compiling file:\t \
%-25s=>\t%-25s\r" ' ' "$<" "$@"
				@gcc $(CFLAGS) -c $< $(HDR_FLAGS) -o $@

clean_lib:
				@make clean -C $(LIB_DIR)

clean_this:
				@rm -rf $(OBJ)
				@echo "$(PREFIX)♻️  $(RED)Removing obj-files...$(RST)"

clean: 				clean_lib clean_this

fclean_lib:
				@make fclean -C $(LIB_DIR)

fclean_this:
				@rm -rf $(NAME)
				@echo "$(PREFIX)♻️  $(RED)Removing executable file...$(RST)"

fclean:				fclean_lib clean_this fclean_this

re_lib:
				make re -C $(LIB_DIR) DEBUG=$(DEBUG)

re_this:			fclean_this all

re:					fclean all

.PHONY:			all clean  fclean re \
clean_this fclean_this \
lib clean_lib fclean_lib
