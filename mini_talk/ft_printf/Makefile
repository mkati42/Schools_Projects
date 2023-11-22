# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkati <mkati@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 23:34:19 by mkati             #+#    #+#              #
#    Updated: 2023/03/02 02:57:41 by mkati            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= ft_functions.c \
				ft_functions2.c \
				ft_printf.c

OBJS		= $(SRCS:%.c=%.o)

FLAGS		= -Wall -Werror -Wextra

$(NAME): $(SRCS)
	gcc $(FLAGS) -c $(SRCS) -I ./
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all