# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/21 16:23:39 by emabel            #+#    #+#              #
#    Updated: 2021/01/21 21:35:09 by emabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_two
CC = clang
CFLAGS = -Wall -Werror -Wextra
INC = philo_three.h
SRCS =	main.c data_init.c life.c utils.c print_actions.c\

OBJS = $(SRCS:%.c=%.o)

#COLORS
RED = \033[1;31m
GREEN = \033[0;32m
GREEN_BOLD= \033[1;32m
YELLOW= \033[0;33m
BLUE = \033[0;34m
BLUE_BOLD= \033[1;34m
CYAN = \033[0;36m
PURPLE = \033[0;35m
RESET = \033[0m

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) -I $(INC) -pthread -o $(NAME) $(OBJS)
	@echo "$(GREEN_BOLD)Completed!$(RESET)"
	@echo "$(BLUE_BOLD)=======PHILOSHPHERS/21school/emabel=======$(RESET)"
	@echo " $(PURPLE)PHILO_TWO's arguments:$(RESET)"
	@echo " $(PURPLE)1.$(RESET) $(CYAN)[number_of_philosophers]$(RESET) - количество философов"
	@echo " $(PURPLE)2.$(RESET) $(CYAN)[time_to_die]$(RESET) - время в ms до смерти"
	@echo " $(PURPLE)3.$(RESET) $(CYAN)[time_to_eat]$(RESET) - время в ms на прием пищи"
	@echo " $(PURPLE)4.$(RESET) $(CYAN)[time_to_sleep]$(RESET) - время в ms на сон"
	@echo " $(PURPLE)optional argument:$(RESET)"
	@echo " $(PURPLE)5.$(RESET) $(CYAN)[number_of_times_each_philosopher_must_eat]$(RESET) - количество приемов пищи"

%.o : %.c
	@echo "$(GREEN)Compiling...$(RESET)"
	@sleep 0.2
	@$(CC) $(CFLAGS) -I $(INC) -pthread -o $@ -c $<

all:	$(NAME)		
clean:
	rm -rf $(OBJS)
fclean:
	rm -rf $(OBJS)
	rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re
