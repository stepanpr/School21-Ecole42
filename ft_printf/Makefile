# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/29 14:33:50 by emabel            #+#    #+#              #
#    Updated: 2020/07/31 00:38:49 by emabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	ft_print_c.c \
		ft_print_s.c \
		ft_print_p.c \
		ft_print_d_i.c \
		ft_print_u.c \
		ft_print_x.c \
		ft_printf.c \
		ft_parser.c \
		ft_subfunc_cnt.c \
		ft_subfunc_put.c  

FLAGS = -Wall -Werror -Wextra

HEADER = ft_printf.h

OBJ = $(SRC:%.c=%.o)

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c $(HEADER)
	@gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all