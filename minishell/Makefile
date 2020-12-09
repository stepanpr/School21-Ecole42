.PHONY: all clean fclean re
NAME = minishell
FLAGS = -Wall -Werror -Wextra
SOURCES_DIR = ./
SOURCES_LIST =	main.c\
				worker/run.c\
				worker/builtins.c\
				worker/env.c\
				worker/utils.c\
				worker/redirect.c\
				worker/builtins_utils.c\
				worker/env_utils.c\
				gnl/get_next_line.c\
				parser/errors.c\
				parser/get_smc_and_pps.c\
				parser/get_quotes.c\
				parser/get_dollar.c\
				parser/save_list.c\
				parser/parser.c\
				parser/parser_data_init.c\
				parser/parser_utils.c\
				parser/get_escaping.c\
				parser/get_redirect.c\
				parser/get_redirect_addtl.c

SOURCES = $(addprefix $(SOURCES_DIR), $(SOURCES_LIST))
OBJECTS_SUBDIR = 	worker\
					parser\
					gnl
OBJECTS_DIR = obj/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))
OBJECTS_SD = $(addprefix $(OBJECTS_DIR), $(OBJECTS_SUBDIR))
HEADER = includes/minishell.h includes/libft.h
LIB = -Llibft -lft

all: $(NAME)
$(NAME): $(OBJECTS_DIR) $(OBJECTS) $(HEADER)
	make -C libft/
	@gcc $(FLAGS) -o $(NAME) $(OBJECTS) $(LIB)
	@echo "$(NAME) compiled"

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)
	@mkdir -p $(OBJECTS_SD)
	@echo "$(NAME)'s $(OBJECTS_DIR) created"

$(OBJECTS_DIR)%.o : $(SOURCES_DIR)%.c $(HEADER)
	@gcc $(FLAGS) -c $< -o $@
	@echo "$< compiled to $@"

clean:
	@rm -rf $(OBJECTS_DIR)
	@echo "$(NAME)'s $(OBJECTS_DIR) deleted"
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"
	@make -C libft/ fclean

re:
	@$(MAKE) fclean
	@$(MAKE) all