# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/20 15:12:22 by emabel            #+#    #+#              #
#    Updated: 2020/10/25 03:10:59 by emabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#RUN: make test

NAME=libasm.a

SRC=ft_write.s \
	ft_read.s \
	ft_strlen.s \
	ft_strcmp.s \
	ft_strcpy.s \
	ft_strdup.s

OBJ=$(SRC:.s=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.s
	nasm -f elf64 -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f write.txt main $(NAME) 

re: fclean all

test: $(NAME)
	gcc main.c -L. -lasm -no-pie -o main
	./main
