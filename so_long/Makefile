# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkati <mkati@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 15:59:33 by mkati             #+#    #+#              #
#    Updated: 2023/06/05 14:59:13 by mkati            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################  NAME  ###################
NAME = so_long
BONUS = so_long_bonus
##############################################
#################  SOURCES  #################
SRCS =	./sources/so_long.c ./sources/map_data/create_map.c \
			./sources/map_data/data_mapn_img.c \
			./sources/map_data/player_data.c \
			./sources/map_control/map_file_control.c \
			./sources/map_control/error_message.c \
			./sources/map_control/valid_map.c \
			./sources/map_control/valid_map2.c \
			./sources/window_img/xpm_file_and_put.c \
			./sources/moves/close_window.c \
			./sources/moves/move_hook.c
BONUS_SRCS =   ./bonus/sources/so_long_bonus.c ./bonus/sources/map_control/error_message_bonus.c \
					./bonus/sources/map_control/map_file_control_bonus.c \
					./bonus/sources/map_control/valid_map_bonus.c \
					./bonus/sources/map_control/valid_map2_bonus.c \
					./bonus/sources/map_data/create_map_bonus.c \
					./bonus/sources/map_data/data_mapn_img_bonus.c \
					./bonus/sources/map_data/player_data_bonus.c \
					./bonus/sources/moves/close_window_bonus.c \
					./bonus/sources/moves/move_hook_bonus.c \
					./bonus/sources/moves/count_flags.c	\
					./bonus/sources/window_img/render_bonus.c \
					./bonus/sources/window_img/xpm_to_file_bonus.c \
					./bonus/sources/window_img/foe_img.c \
##############################################
###################  OBJS  ###################
OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
##############################################
###################  PATH  ###################
PATH_SRCS = ./sources/
BONUS_PATH_SRCS = ./bonus/sources/
PATH_PRINT = ./printf/
PATH_GNL = ./gnl/
PATH_MLX = ./mlx/
PATH_LIB = ./libft/
PATH_MLX_A = ./mlx/libmlx.a
PATH_LIB_A = ./libft/libft.a
PATH_PRINT_A = ./printf/libftprintf.a
PATH_GNL_A = ./gnl/libftgnl.a
##############################################
################# DEFINE ####################
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx -O3
MFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
GNL_OBJS = ./gnl/*.o
LIB_OBJS = ./libft/*.o
PRINT_OBJS = ./printf/*.o
MLX_OBJS = ./minilibx/*.o
##############################################
################ ALL & AND ########################
all : $(NAME) $(PATH_MLX_A) $(PATH_LIB_A) $(PATH_PRINT_A) $(PATH_GNL_A)

$(NAME): $(OBJS)
	@make -C $(PATH_PRINT)
	@make -C $(PATH_GNL)
	@make -C $(PATH_MLX) 2>/dev/null
	@make -C $(PATH_LIB)
	@$(CC) $(CFLAGS) $(MFLAGS) $(OBJS) $(GNL_OBJS) $(LIB_OBJS) $(PRINT_OBJS) -I $(PATH_SRCS) -o $(NAME)

bonus : $(BONUS) $(PATH_MLX_A) $(PATH_LIB_A) $(PATH_PRINT_A) $(PATH_GNL_A)

$(BONUS): $(BONUS_OBJS)
	@make -C $(PATH_PRINT)
	@make -C $(PATH_GNL)
	@make -C $(PATH_MLX)
	@make -C $(PATH_LIB)
	@$(CC) $(CFLAGS) $(MFLAGS) $(BONUS_OBJS) $(GNL_OBJS) $(LIB_OBJS) $(PRINT_OBJS) -L $(BONUS_PATH_SRCS) -o $(BONUS)
##############################################
################ CLEAN #######################
clean:
		@make clean -C $(PATH_PRINT)
		@make clean -C $(PATH_GNL)
		@make clean -C $(PATH_LIB)
		@make clean -C $(PATH_MLX)
		@rm -rf $(OBJS)
		@rm -rf $(BONUS_OBJS)

fclean:
		@make fclean -C $(PATH_PRINT)
		@make fclean -C $(PATH_GNL)
		@make fclean -C $(PATH_LIB)
		@rm -rf $(NAME)
		@rm -rf $(BONUS)

re: clean fclean all

.PHONY: all clean fclean re bonus
		