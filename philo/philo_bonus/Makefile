NAME_BNS = philo_bonus

SRC_BNS = ./src_bonus/main_bonus.c \
		./src_bonus/utils_bonus.c \
		./src_bonus/create_bonus.c \
		./src_bonus/routine_bonus.c

OBJ_BNS = $(SRC_BNS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

RED=\033[31m
YELLOW=\033[33m
GREEN=\033[32m
CYAN=\033[36m
BLUE=\033[34m
MAGENTA=\033[35m
RESET=\033[0m


all: title $(NAME_BNS)
	@echo "$(GREEN)****** Philosophers Compiled Succesfuly ******"

title :
	@clear
	@echo "$(RED)																					   ";
	@echo "▓█████▄  ▒█████   ██ ▄█▀▄▄▄█████▓ ▒█████   ██▀███      ▄▄▄▄    █    ██     ███▄    █ ▓█████           ░░░░░░░░░░░░░░░░░░░░░░";
	@echo "▒██▀ ██▌▒██▒  ██▒ ██▄█▒ ▓  ██▒ ▓▒▒██▒  ██▒▓██ ▒ ██▒   ▓█████▄  ██  ▓██▒    ██ ▀█   █ ▓█   ▀       ░░░░███████████████████░░░░░";
	@echo "░██   █▌▒██░  ██▒▓███▄░ ▒ ▓██░ ▒░▒██░  ██▒▓██ ░▄█ ▒   ▒██▒ ▄██▓██  ▒██░   ▓██  ▀█ ██▒▒███       ░░░███████████████████████████░░░";
	@echo "░▓█▄   ▌▒██   ██░▓██ █▄ ░ ▓██▓ ░ ▒██   ██░▒██▀▀█▄     ▒██░█▀  ▓▓█  ░██░   ▓██▒  ▐▌██▒▒▓█  ▄    ░░████████████████████████████████░";
	@echo "░▒████▓ ░ ████▓▒░▒██▒ █▄  ▒██▒ ░ ░ ████▓▒░░██▓ ▒██▒   ░▓█  ▀█▓▒▒█████▓    ▒██░   ▓██░░▒████▒  ░███████████████████████████████████░";
	@echo " ▒▒▓  ▒ ░ ▒░▒░▒░ ▒ ▒▒ ▓▒  ▒ ░░   ░ ▒░▒░▒░ ░ ▒▓ ░▒▓░   ░▒▓███▀▒░▒▓▒ ▒ ▒    ░ ▒░   ▒ ▒ ░░ ▒░ ░ ░░░░░█████████████████████████████░░░█░";
	@echo " ░ ▒  ▒   ░ ▒ ▒░ ░ ░▒ ▒░    ░      ░ ▒ ▒░   ░▒ ░ ▒░   ▒░▒   ░ ░░▒░ ░ ░    ░ ░░   ░ ▒░ ░ ░  ░ ░█░ ░█████████████████████████████░ ░█░";
	@echo " ░ ░  ░ ░ ░ ░ ▒  ░ ░░ ░   ░      ░ ░ ░ ▒    ░░   ░     ░    ░  ░░░ ░ ░       ░   ░ ░    ░    ░░░ ░█████████████████████████████░ ░█░";
	@echo "   ░        ░ ░  ░  ░                ░ ░     ░         ░         ░                 ░    ░  ░  ░░░ ░██░░░░░░░░░██████░░░░░░░░██░ ░█░";
	@echo " ░                                                          ░                                  ░░ ░░░░       ░░████░        ░░░ ░░";
	@echo "                                                                                                  ░░         ░█████░         ░█░ ";
	@echo "                                                                                                  ░░█░       ░███████░░      ░░█░";
	@echo "                          ██▓███   ██░ ██  ██▓ ██▓     ▒█████                                     ░███░░░░░░░██░░░░░██░░░░░░░░██░";
	@echo "                         ▓██░  ██▒▓██░ ██▒▓██▒▓██▒    ▒██▒  ██▒                                   ░░████░░░███░     ░░███░░████░░";
	@echo "                         ▓██░ ██▓▒▒██▀▀██░▒██▒▒██░    ▒██░  ██▒                                   ░░░░░█████░░      ░█████░░░░░░";
	@echo "                         ▒██▄█▓▒ ▒░▓█ ░██ ░██░▒██░    ▒██   ██░                                        ░░░██░░ ░░░░ ░██░░░░░";
	@echo "                         ▒██▒ ░  ░░▓█▒░██▓░██░░██████▒░ ████▓▒░                                          ░░██░░███░░██░░";
	@echo "                         ▒▓▒░ ░  ░ ▒ ░░▒░▒░▓  ░ ▒░▓  ░░ ▒░▒░▒░                                        ░░  ░█░░██░░█░░█░░ ░░";
	@echo "                         ░▒ ░      ▒ ░▒░ ░ ▒ ░░ ░ ▒  ░  ░ ▒ ▒░                                        ░░  ░░          ░░ ░░";
	@echo "                         ░░        ░  ░░ ░ ▒ ░  ░ ░   ░ ░ ░ ▒                                         ░█░░░░░ ░  ░ ░ ░░░░░░";
	@echo "                                    ░  ░  ░ ░      ░  ░    ░ ░                                        ░░█░██░░██░░█░░██░██░";
	@echo "                                                                                                       ░░███████████████░░";
	@echo "                                                                                                         ░░░░░░░░░░░░░░░";
	@echo "                                                                                                              ░░░░░";
	@echo "                                                                                    $(CYAN)By MKati42$(RESET)";
	@echo "                                                                                                             ";	
	

$(NAME_BNS) : $(SRC_BNS)
	@$(CC) $(CFLAGS) $(SRC_BNS) -o $(NAME_BNS)

clean : 
	@rm -rf $(OBJ_BNS)

fclean : clean
	@rm -rf $(NAME_BNS)

re : fclean all

.PHONY : all clean fclean re