# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emabel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/22 08:44:04 by emabel            #+#    #+#              #
#    Updated: 2019/08/22 11:49:12 by emabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRCS = first_bsq.c second_bsq.c third_bsq.c

OBJECTS = first_bsq.o second_bsq.o third_bsq.o

INC = bsq.h

all: $(NAME)

$(NAME):
		gcc -c -Wall -Wextra -Werror $(SRCS)
		gcc $(OBJECTS) -o $(NAME) -I $(INC)

clean: 
		/bin/rm -f $(OBJECTS)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

