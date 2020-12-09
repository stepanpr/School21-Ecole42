cmake_minimum_required(VERSION 3.17)
project(minishell C)

set(CMAKE_C_STANDARD 99)
link_directories(${CMAKE_SOURCE_DIR}/libft/)
add_executable(minishell main.c includes/minishell.h includes/libft.h
        worker/run.c worker/builtins.c worker/env.c worker/utils.c worker/redirect.c gnl/get_next_line.c
        parser/errors.c parser/get_smc_and_pps.c parser/get_quotes.c parser/get_dollar.c parser/save_list.c parser/parser.c parser/parser_utils.c
        parser/get_escaping.c parser/get_redirect.c libft/ft_strtolower.c libft/ft_strequ.c worker/builtins_utils.c worker/env_utils.c
        parser/parser_data_init.c parser/get_redirect_addtl.c)
target_link_libraries(minishell ft)