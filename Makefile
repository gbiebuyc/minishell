# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/17 11:35:12 by gbiebuyc          #+#    #+#              #
#    Updated: 2019/01/23 23:20:04 by gbiebuyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC = src/minishell.c \
	  src/split_line.c \
	  src/execute_line.c
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
