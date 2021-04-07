NAME = replace
CC = clang++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = main.cpp
OBJS = $(SRCS:%.cpp=%.o)

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
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN_BOLD)Completed!$(RESET)"

%.o : %.c
	@echo "$(GREEN)Compiling...$(RESET)"
	@sleep 0.2
	@$(CC) $(CFLAGS) -o $@ -c $<

all: $(NAME)

clean:
	rm -rf $(OBJS)
fclean:
	rm -rf $(OBJS) 
	rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re
