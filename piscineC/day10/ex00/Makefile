# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emabel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/13 20:41:45 by emabel            #+#    #+#              #
#    Updated: 2019/08/13 22:07:20 by emabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
INC_DIR = ./includes
FILES = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
OUT = ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o

all: $(NAME)

$(NAME):
	gcc -Werror -Wall -Wextra -c $(FILES) 
	ar rc $(NAME) $(OUT)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OUT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
