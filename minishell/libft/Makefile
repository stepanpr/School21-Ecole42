.PHONY: all clean fclean re
NAME = libft.a
BONUS = bonus
FLAGS = -Wall -Werror -Wextra -c
SOURCES_DIR = ./
SOURCES_LIST =	ft_memset.c\
				ft_bzero.c\
				ft_memcpy.c\
				ft_memccpy.c\
				ft_memmove.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_strlen.c\
				ft_strlcpy.c\
				ft_strlcat.c\
				ft_strchr.c\
				ft_strrchr.c\
				ft_strncmp.c\
				ft_strcmp.c\
				ft_strnstr.c\
				ft_isalpha.c\
				ft_isdigit.c\
				ft_isalnum.c\
				ft_isascii.c\
				ft_isprint.c\
				ft_toupper.c\
				ft_tolower.c\
				ft_atoi.c\
				ft_calloc.c\
				ft_strdup.c\
				ft_substr.c\
				ft_strjoin.c\
				ft_strtrim.c\
				ft_split.c\
				ft_putchar_fd.c\
				ft_putstr_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_itoa.c\
				ft_strmapi.c\
                ft_lstnew.c\
				ft_lstadd_back.c\
				ft_lstadd_front.c\
				ft_lstlast.c\
				ft_lstsize.c\
				ft_lstclear.c\
				ft_lstiter.c\
				ft_lstdelone.c\
				ft_lstmap.c\
				ft_strpos.c\
				ft_strcmp.c\
				ft_strequ.c

SOURCES = $(addprefix $(SOURCES_DIR), $(SOURCES_LIST))
OBJECTS_DIR = obj/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))

all: $(NAME)
$(NAME): $(OBJECTS_DIR) $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "$(NAME) compiled"

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)
	@echo "$(NAME)'s $(OBJECTS_DIR) created"

$(OBJECTS_DIR)%.o : $(SOURCES_DIR)%.c
	@gcc $(FLAGS) $< -o $@
	@echo "$< compiled to $@"

clean:
	@rm -rf $(OBJECTS_DIR)
	@echo "$(NAME)'s $(OBJECTS_DIR) deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re:
	@$(MAKE) fclean
	@$(MAKE) all