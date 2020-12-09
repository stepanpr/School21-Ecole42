/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 16:12:17 by emabel            #+#    #+#             */
/*   Updated: 2020/12/08 20:43:20 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		parser_replace_for_split(t_parser *d)
{
	if ((d->l[d->i] == ' ' || d->l[d->i] == '\t') && d->qq != 1 && d->q != 1)
	{
		if (((d->l[d->i + 1] == '"' && d->l[d->i + 2] == '"') || \
(d->l[d->i + 1] == '\'' && d->l[d->i + 2] == '\'')) && d->l[d->i + 3] == ' ')
			d->c = ft_addtostr(d->c, ' ');
		d->l[d->i] = '*';
	}
}

void		parser_lm(char **e, t_redirect **rdr, t_parser *d)
{
	d->c = ft_strdup("");
	while (d->l[++d->i] && !(d->exit))
	{
		if (get_smcl_and_pps(d->l, d))
			break ;
		if (get_quotes(d->l[d->i], d) || get_escaping(d->l, d, 0)
			|| get_dollar(d->l, e, d) || get_redirect(d->l, d, rdr))
			continue ;
		parser_replace_for_split(d);
		d->c = ft_addtostr(d->c, d->l[d->i]);
	}
	quote_mark_closed(d);
	d->args = ft_split(d->c, '*');
	if (!*d->args && (d->exit == 0))
		d->exit = 1;
	if (d->exit && (d->j = -1))
	{
		while (d->args[++d->j])
			free(d->args[d->j]);
		free(d->args);
	}
	free(d->c);
}

t_command	*parser_loop(char **env, t_command *cmd,
						t_redirect *rdr, t_parser *d)
{
	if (d->exit == 2 && (d->i += ft_strlen(d->l)))
		return (NULL);
	d->exit = 0;
	cmd = NULL;
	rdr = NULL;
	parser_lm(env, &rdr, d);
	if (d->err_flag == 1)
	{
		if (d->file)
			free(d->file);
		if (rdr->file)
			free(&rdr->file);
	}
	if (d->exit)
		return (cmd);
	cmd = cmdnew(d->args, d->pipe, rdr);
	if (cmd->pipe == 1)
	{
		lab(NULL, NULL, &cmd, parser_loop(env, NULL, rdr, d));
		if (!cmd->next && (free_cmd(&cmd)))
			cmd = NULL;
	}
	return (cmd);
}

t_command	*parser_read_line(t_sh *sh, t_command *cmd,
							t_redirect *rdr, t_parser *d)
{
	while (d->i == -1 || d->l[d->i])
	{
		if (!*d->l)
			continue ;
		cmd = parser_loop(sh->env, cmd, rdr, d);
		if (cmd)
		{
			run(sh, cmd);
			free_rdr(&cmd->redirect);
			free_cmd(&cmd);
		}
		else
			sh->status = 2;
	}
	return (0);
}

t_command	*parser(t_sh *sh)
{
	t_command	*cmd;
	t_redirect	*rdr;
	t_parser	*d;
	int			ret;

	d = (t_parser*)malloc(sizeof(t_parser));
	parser_data_init(d, &cmd, &rdr);
	if ((ret = get_next_line(sh, 0, &d->l)) > 0 && (d->l[0] != '\0'))
		parser_read_line(sh, cmd, rdr, d);
	if (ret == -1)
		error_p(NULL, "malloc: ", "error", NULL);
	if (ret == 0)
		my_exit(sh, NULL);
	free(d->l);
	free(d);
	return (cmd);
}
