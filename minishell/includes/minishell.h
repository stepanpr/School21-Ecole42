/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 00:40:02 by clauren           #+#    #+#             */
/*   Updated: 2020/12/08 20:59:15 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <signal.h>
# include <string.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct			s_redirect
{
	char				*file;
	int					type;
	struct s_redirect	*next;
}						t_redirect;

typedef struct			s_command
{
	char				**args;
	int					pipe;
	t_redirect			*redirect;
	struct s_command	*next;
}						t_command;

typedef struct			s_sh
{
	char				**env;
	int					status;
	int					from_pipe;
	pid_t				child;
	int					piped;
	int					timer;
	int					old_pipe;
}						t_sh;

typedef struct			s_parser
{
	char				*l;
	char				*c;
	char				**args;
	int					i;
	int					pipe;
	int					esc;
	int					exit;
	int					qq;
	int					q;
	int					status;
	char				*value;
	char				*key;
	char				*file;
	int					tp;
	int					tp_cnt;
	int					ln_nm;
	int					rec;
	char				sym;
	int					k;
	int					j;
	int					q_gsap;
	int					qq_gsap;
	int					err_flag;
}						t_parser;

int						get_next_line(t_sh *sh, int fd, char **line);
int						ft_strequ(char *a, char *b);
int						array_size(char **arr);
int						run(t_sh *sh, t_command *cmd);
void					listener(int code);
void					sighandler(int code);
int						error_p(char *bin, char *subject,
							char *text, char *text1);
int						echo_n(char **argv);
void					set_pwds(t_sh *sh, char ***args);
int						returner(t_sh *sh);
void					unset_swap(char **env, char **key);
void					sort_keys(char ***envp, int count);
char					**only_key_check(char *str);
char					*env_get(char **env, char *key, int only_key);
int						unset(char **env, char **key);
int						export(t_sh *sh, char ***envp, char **args, int f);
void					print_env_line(char **envp, char *line);
int						cd(t_sh *sh, char *path);
int						pwd(t_sh *sh);
int						env(char **envp, int sort);
int						my_exit(t_sh *sh, char **args);
int						redirection(t_sh *sh, t_command *cmd);
int						cmd_switch(t_sh *sh, t_command *cmd);
int						echo(t_sh *sh, char **argv);
int						exec(t_sh *sh, char **argv);
int						bin(t_sh *sh, char **argv);
char					**check_env_name(char *str, int only_key, int *add);
int						find_inset(char c, char *set, int (*is)(int c));
void					env_re(char ***envp, char **a, int add, int i);
void					change_(t_sh *sh, t_command *cmd);
t_command				*parser(t_sh *sh);
t_command				*parser_loop(char **env, t_command *cmd,
							t_redirect *rdr, t_parser *d);
void					parser_lm(char **env, t_redirect **rdr, t_parser *d);
int						parser_data_init(t_parser *d, t_command **cmd,
							t_redirect **rdr);
int						error_exit(t_parser *d, int key, char sym);
int						get_quotes(char c, t_parser *d);
int						quote_mark_closed(t_parser *d);
int						get_dollar(char *l, char **env, t_parser *d);
int						get_dollar_varvalue(char *l, char **env, t_parser *d);
int						get_dollar_isgigit(char *l, t_parser *d);
int						get_smcl_and_pps(char *l, t_parser *d);
int						check_double_smcl_and_pps(char *str,
								t_parser *d);
int						check_double_smcl_and_pps_spaces(char *str,
								t_parser *d);
int						check_double_smcl_and_pps_additional(char *str,
											t_parser *d);
int						check_empty_pipe(char *str, t_parser *d);
int						get_redirect(char *l, t_parser *d, t_redirect **rdr);
int						get_redirect_back(char *l, t_parser *d);
int						get_redirect_forvard(char *l, t_parser *d);
int						get_filename(char *l, t_parser *d);
int						get_filename_loop(char *l, t_parser *d);
int						get_filename_loop_check_symbols(char *l, t_parser *d);
int						count_filename(char *str, t_parser *d);
int						get_escaping(char *l, t_parser *d, int cnt);
int						get_escaping_additional(char *l, t_parser *d);
t_redirect				*rdr_new(char *fl, int tp);
void					free_rdr(t_redirect **rdr);
t_command				*cmdnew(char **arg, int pipe, t_redirect *redirect);
int						free_cmd(t_command **cmd);
void					lab(t_redirect **lstr, t_redirect *newr,
							t_command **lstc, t_command *newc);
char					*ft_addtostr(char *s1, char s2);
int						word_len(char *str);
int						find_inset(char c, char *set, int (*is)(int c));
#endif
