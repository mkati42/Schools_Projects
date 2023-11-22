# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkati <mkati@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 15:37:11 by mkati             #+#    #+#              #
#    Updated: 2023/03/02 03:47:55 by mkati            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMESERVER = server
NAMECLIENT = client
NAME_C_BONUS = client_bonus
NAME_S_BONUS = server_bonus
LIB = ./ft_printf/libftprintf.a
SRCSERVER = server.c
SRCCLIENT = client.c
SRCCLIENT_BONUS = client_bonus.c
SRCSERVER_BONUS = server_bonus.c
FLAGS = -Wall -Wextra -Werror
CC = gcc
OBJSERVER = $(SRCSERVER:.c=.o)
OBJCLIENT = $(SRCCLIENT:.c=.o)
OBJCLIENT_BONUS = $(SRCCLIENT_BONUS:.c=.o)
OBJSERVER_BONUS = $(SRCSERVER_BONUS:.c=.o)
all: $(LIB) $(NAMESERVER) $(NAMECLIENT) $(NAME_C_BONUS) $(NAME_S_BONUS)
$(LIB):
	make -C ./ft_printf
$(NAMESERVER) : $(OBJSERVER)
	$(CC) $(OBJSERVER) -o $(NAMESERVER) $(LIB)
$(NAMECLIENT) : $(OBJCLIENT)
	$(CC) $(OBJCLIENT) -o $(NAMECLIENT) $(LIB)
$(NAME_C_BONUS) : $(OBJCLIENT_BONUS)
	$(CC) $(OBJCLIENT_BONUS) -o $(NAME_C_BONUS) $(LIB)
$(NAME_S_BONUS) : $(OBJSERVER_BONUS)
	$(CC) $(OBJSERVER_BONUS) -o $(NAME_S_BONUS) $(LIB)
clean:
	rm -rf $(OBJSERVER) $(OBJCLIENT) $(OBJCLIENT_BONUS)  $(OBJSERVER_BONUS)
	rm -rf ./ft_printf/*.o
fclean: clean
	rm -rf $(NAMESERVER) $(NAMECLIENT) $(NAME_C_BONUS) $(NAME_S_BONUS)
	rm -rf ./ft_printf/*.o
	rm -rf ./ft_printf/libftprintf.a
re:fclean all
.PHONY : re fclean clean all