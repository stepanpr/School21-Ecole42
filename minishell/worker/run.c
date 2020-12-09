/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 21:52:32 by clauren           #+#    #+#             */
/*   Updated: 2020/12/08 19:41:16 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		cmd_switch(t_sh *sh, t_command *cmd)
{
	change_(sh, cmd);
	if (ft_strequ("echo", *cmd->args))
		return (echo(sh, cmd->args + 1));
	if (ft_strequ("cd", *cmd->args))
		return (cd(sh, cmd->args[1]));
	if (ft_strequ("pwd", *cmd->args))
		return (pwd(sh));
	if (ft_strequ("export", *cmd->args))
		return (export(sh, &(sh->env), cmd->args + 1, 0));
	if (ft_strequ("unset", *cmd->args))
		return (unset(sh->env, cmd->args));
	if (ft_strequ("env", *cmd->args))
		return (env(sh->env, 0));
	if (ft_strequ("exit", *cmd->args))
		return (my_exit(sh, cmd->args + 1));
	return (bin(sh, cmd->args));
}

int		commutation(t_sh *sh, t_command *cmd)
{
	int		fd_in;
	int		fd_out;

	fd_in = dup(0);
	fd_out = dup(1);
	if (cmd->redirect)
		sh->status = redirection(sh, cmd);
	else
		sh->status = cmd_switch(sh, cmd);
	dup2(fd_in, 0);
	dup2(fd_out, 1);
	return (0);
}

int		magic_work(t_sh *sh, int fd_pipe[2], t_command *cmd, pid_t w[2])
{
	int j;

	w[0] = fork();
	if (w[0] == 0)
	{
		close(fd_pipe[0]);
		dup2(fd_pipe[1], 1);
		sh->status = commutation(sh, cmd);
		close(fd_pipe[1]);
		exit(0);
	}
	w[1] = fork();
	if (w[1] == 0 && !(sh->timer = 0))
	{
		while (sh->timer++ < 555 && !(j = 0))
			while (j < 555)
				j++;
		exit(0);
	}
	w[2] = wait(NULL);
	if (w[2] == w[0])
		kill(w[1], SIGKILL);
	else
		kill(w[0], SIGKILL);
	exit(0);
}

int		pipe_fork(t_sh *sh, t_command *cmd)
{
	pid_t	child;
	pid_t	worker[2];
	int		fd_pipe[2];

	if (pipe(fd_pipe) == -1)
		perror("minishell");
	if ((child = fork()) == 0)
	{
		magic_work(sh, fd_pipe, cmd, worker);
	}
	else
	{
		close(fd_pipe[1]);
		waitpid(child, &sh->status, WUNTRACED);
		dup2(fd_pipe[0], 0);
		close(fd_pipe[0]);
	}
	return (sh->status);
}

int		run(t_sh *sh, t_command *cmd)
{
	int fd_in;

	fd_in = dup(0);
	sh->old_pipe = 0;
	while (cmd)
	{
		if (cmd->pipe)
		{
			sh->piped = 1;
			pipe_fork(sh, cmd);
		}
		else
		{
			sh->piped = 0;
			commutation(sh, cmd);
			dup2(fd_in, 0);
		}
		cmd = cmd->next;
	}
	close(fd_in);
	return (fd_in);
}
