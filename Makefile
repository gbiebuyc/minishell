# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/17 11:35:12 by gbiebuyc          #+#    #+#              #
#    Updated: 2019/02/11 07:55:36 by gbiebuyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC = src/main.c \
	  src/execute_line.c \
	  src/environment.c \
	  src/var_lengths.c \
	  src/expansions.c \
	  src/builtin_cd.c \
	  src/builtin_echo_exit.c \
	  src/builtin_set_unset_env.c \
	  src/path_operations.c \
	  src/misc.c
OBJ = $(SRC:.c=.o)
FTPRINTF_DIR = src/ft_printf
CFLAGS = -I $(FTPRINTF_DIR) -Wall -Wextra -Werror
LDFLAGS = -L $(FTPRINTF_DIR) -lftprintf
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(FTPRINTF_DIR)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	make -C $(FTPRINTF_DIR) clean
	rm -rf $(OBJ)

fclean:
	make -C $(FTPRINTF_DIR) fclean
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: fclean all
