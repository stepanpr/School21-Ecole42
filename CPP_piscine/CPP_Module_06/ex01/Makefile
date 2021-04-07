
NAME = serialization

CC = clang++

CFLAGS = -Wall -Wextra -Werror

SRCS = main.cpp

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
RESET = \033[0m

all: $(NAME)
	
%.o: %.cpp
	@echo "$(GREEN)Compiling...$(RESET)"
	@sleep 0.2
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(GREEN_BOLD)Completed!$(RESET)"
	@$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
