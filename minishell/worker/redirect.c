/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 22:31:26 by clauren           #+#    #+#             */
/*   Updated: 2020/12/08 20:17:33 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		change_(t_sh *sh, t_command *cmd)
{
	char	**args;
	int		i;
	int		k;
	char	*command;

	k = 0;
	if (sh->piped)
		return ;
	i = array_size(cmd->args) - 1;
	command = cmd->args[i];
	if (ft_strequ(cmd->args[0], "export")
		&& (k = ft_strpos(cmd->args[i], '=')))
		command = ft_substr(cmd->args[i], 0, --k);
	args = ft_calloc(2, sizeof(char *));
	args[0] = ft_strjoin("_=", command);
	if (args[0])
		export(sh, &sh->env, args, 0);
	if (k)
		free(command);
	free(args[0]);
	free(args);
}

int			get_fd(t_redirect *f, int fd)
{
	if (fd > 0)
		close(fd);
	if (f->type == 0)
		fd = open(f->file, O_RDONLY);
	else if (f->type == 1)
		fd = open(f->file, O_CREAT | O_RDWR | O_TRUNC, 00644);
	else if (f->type == 2)
		fd = open(f->file, O_CREAT | O_RDWR | O_APPEND, 00644);
	else
		fd = -1;
	if (fd != -1)
		(f->type == 0) ? dup2(fd, 0) : dup2(fd, 1);
	else
		error_p(f->file, ": ", strerror(errno), NULL);
	return (fd);
}

int			redirection(t_sh *sh, t_command *cmd)
{
	int			fd_read;
	int			fd_write;
	t_redirect	*rdr;

	fd_read = 0;
	fd_write = 0;
	rdr = cmd->redirect;
	while (rdr)
	{
		if (rdr->type == 0)
		{
			if ((fd_read = get_fd(rdr, fd_read)) == -1)
				return (1);
		}
		else
		{
			if ((fd_write = get_fd(rdr, fd_write)) == -1)
				return (1);
		}
		rdr = rdr->next;
	}
	return (cmd_switch(sh, cmd));
}

static int	find_exe(t_sh *sh, char *path_o, char **argv, int j)
{
	char *ppath;
	char *spath;
	char **paths;

	if (!(paths = ft_split(path_o, ':')))
		return (0);
	while (paths[++j])
	{
		spath = ft_strjoin("/", *argv);
		if ((ppath = ft_strjoin(paths[j], spath)))
			if (execve(ppath, argv, sh->env) != -1)
			{
				free(spath);
				free(ppath);
				while (paths[j])
					free(paths[j++]);
				free(paths);
				return (1);
			}
		free(spath);
		free(ppath);
		free(paths[j]);
	}
	free(paths);
	return (0);
}

int			exec(t_sh *sh, char **argv)
{
	char *path;
	char *tmp;

	tmp = NULL;
	path = NULL;
	if (**argv == '/')
		return (execve(*argv, argv, sh->env));
	if (ft_strncmp(*argv, "./", 2) == 0)
	{
		tmp = getcwd(tmp, 0);
		path = ft_strjoin(tmp, ft_strtrim(*argv, "."));
		free(tmp);
		if (execve(path, argv, sh->env) != -1)
		{
			free(path);
			return (1);
		}
		free(path);
	}
	else if ((path = env_get(sh->env, "PATH", 0)))
	{
		if (find_exe(sh, path, argv, -1))
			return (1);
	}
	return (-1);
}
