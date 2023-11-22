NAME = push_swap

SRCS = main.c \
		args_control.c \
		init_lst.c \
		utils.c \
		ft_error.c \
		index_lst.c \
		sort_control.c \
		sort_lst.c \
		ft_push.c \
		ft_r_reverse.c \
		ft_reverse.c \
		ft_swap.c \
		radix.c



OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
		@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean : 
		rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re