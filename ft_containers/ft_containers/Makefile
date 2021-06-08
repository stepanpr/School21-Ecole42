# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 02:50:38 by emabel            #+#    #+#              #
#    Updated: 2021/06/07 15:34:12 by emabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_containers

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = ./test/main.cpp ./test/vectorTest.cpp ./test/listTest.cpp ./test/mapTest.cpp ./test/stackTest.cpp ./test/queueTest.cpp

OBJS = $(SRCS:.cpp=.o)

#COLORS
RED = \033[1;31m
GREEN = \033[0;32m
GREEN_BOLD= \033[1;32m
YELLOW= \033[0;33m
BLUE = \033[0;34m
BLUE_BOLD= \033[1;34m
CYAN = \033[0;36m
PURPLE = \033[0;35m
PURPLE_BOLD = \033[1;35m
RESET = \033[0m

all: $(NAME)
	
%.o: %.cpp
	@echo "$(GREEN)Compiling...$(RESET)"
	@sleep 0.2
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@echo "$(GREEN_BOLD)Completed!$(RESET)"
	@echo "$(BLUE_BOLD)=======FT_CONTAINERS/emabel/21school=======$(RESET)"
	@echo " $(PURPLE)containers under test:$(RESET)"
	@echo " $(PURPLE)1.$(RESET) $(CYAN)[vector]$(RESET) - контейнер основанный на динамическом массиве"
	@echo " $(PURPLE)2.$(RESET) $(CYAN)[list]$(RESET) - контейнер основанный на двусвязных списках"
	@echo " $(PURPLE)3.$(RESET) $(CYAN)[map]$(RESET) - ассоциативный контейнер"
	@echo " $(PURPLE)4.$(RESET) $(CYAN)[stack]$(RESET) - контейнер адаптер"
	@echo " $(PURPLE)5.$(RESET) $(CYAN)[queue]$(RESET) - контейнер адаптер"
	@echo " $(PURPLE)use $(PURPLE_BOLD)./ft_containers $(PURPLE)for start program$(RESET)"
	@echo " $(PURPLE)or $(PURPLE_BOLD)./ft_containers [container]$(PURPLE) to run with the selected type$(RESET)"


clean:
	$(RM) ./test/*.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
