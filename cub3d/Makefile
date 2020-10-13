# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/06 16:42:04 by emabel            #+#    #+#              #
#    Updated: 2020/10/08 19:15:54 by emabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = cub3D

SRCS    = $(shell find srcs -type f -name '*.c')

OBJS	= $(SRCS:.c=.o)
LIBS    = -L./minilibx -lmlx -lXext -lX11 -lm
MLX		= minilibx/libmlx.a

.PHONY: clean fclean all bonus

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	@gcc -Wall -Wextra -Werror ${OBJS} ${LIBS} $(MLX) -o ${NAME}

$(MLX):
	$(MAKE) -C minilibx

%.o : %.c
	gcc -Iheaders -Iminilibx -o $@ -c $<

bonus: all

clean:
	rm -f $(OBJS)
	make -C minilibx/ clean

fclean: clean
	rm -f $(NAME)

re: fclean all
