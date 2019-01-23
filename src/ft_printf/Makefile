# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/03 15:37:26 by gbiebuyc          #+#    #+#              #
#    Updated: 2019/01/21 15:47:19 by gbiebuyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = src/ft_printf.c \
	  src/bignum.c \
	  src/widechar.c \
	  src/parse.c \
	  src/conv_signed.c \
	  src/conv_unsigned.c \
	  src/conv_char.c \
	  src/conv_str.c \
	  src/conv_non_printable_str.c \
	  src/conv_float.c \
	  src/conv_misc.c \
	  src/get_args.c \
	  src/dispatch.c
OBJ = $(SRC:.c=.o)
LIBFTDIR = src/libft
CFLAGS = -I $(LIBFTDIR) -Wall -Wextra -Werror
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/libft.a $(NAME)
	ar rs $(NAME) $(OBJ)

clean:
	make -C $(LIBFTDIR) clean
	rm -rf $(OBJ)

fclean:
	make -C $(LIBFTDIR) fclean
	rm -rf $(OBJ)
	rm -rf $(NAME)

re: fclean all
