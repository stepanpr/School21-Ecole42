/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 22:01:20 by clauren           #+#    #+#             */
/*   Updated: 2020/12/08 18:24:29 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		pwd(t_sh *sh)
{
	char	*cwd;
	int		freeme;

	freeme = 0;
	cwd = env_get(sh->env, "PWD", 0);
	if (!cwd || !ft_strpos(cwd, '/'))
	{
		cwd = NULL;
		freeme = 1;
		cwd = getcwd(cwd, 0);
	}
	ft_putendl_fd(cwd, 1);
	if (freeme)
		free(cwd);
	return (0);
}

int		echo(t_sh *sh, char **argv)
{
	int n;
	int shift;

	n = echo_n(argv);
	argv += n;
	while (*argv)
	{
		shift = 0;
		if (*argv && !ft_strncmp(*argv, "$?", 2) && (shift = 1))
			ft_putstr_fd(ft_itoa(sh->status), 1);
		*argv += (shift) ? 2 : 0;
		ft_putstr_fd(*argv, 1);
		*argv -= (shift) ? 2 : 0;
		if (*++argv)
			ft_putchar_fd(' ', 1);
	}
	if (!n)
		ft_putchar_fd('\n', 1);
	return (0);
}

int		my_exit(t_sh *sh, char **args)
{
	int status;

	if (!sh->from_pipe)
		ft_putendl_fd("exit", 1);
	if (args && array_size(args) > 1)
	{
		error_p("exit: ", NULL, "too many arguments", NULL);
		return (1);
	}
	if (args && args[0])
	{
		status = ft_atoi(args[0]);
		while (*args[0])
		{
			if (!find_inset(*args[0]++, "- +\t\f\r", ft_isdigit))
			{
				error_p("exit: ", args[0],
				": numeric argument required", NULL);
				exit(255);
			}
		}
		exit(status > 255 ? status - 256 : status);
	}
	else
		exit(sh->status);
}

int		cd(t_sh *sh, char *path)
{
	char **args;

	args = ft_calloc(2, sizeof(char *));
	if (!path || !*path || ft_strequ(path, "~"))
		if (!(path = env_get(sh->env, "HOME", 0)))
		{
			error_p("cd: ", "HOME not set", NULL, NULL);
			return (1);
		}
	if (ft_strequ(path, "-"))
	{
		path = env_get(sh->env, "OLDPWD", 0);
		if (!path && (error_p("cd: ", "OLDPWD not set", NULL, NULL)))
			return (1);
		ft_putendl_fd(path, 1);
	}
	if (chdir(path) != 0)
	{
		error_p("cd: ", path, ": ", strerror(errno));
		free(args);
		return (1);
	}
	set_pwds(sh, &args);
	free(args);
	return (0);
}

int		bin(t_sh *sh, char **argv)
{
	sh->child = fork();
	if (sh->child < 0)
		perror("minishell");
	else if (sh->child == 0)
	{
		if (exec(sh, argv) == -1)
		{
			if (ft_strpos(*argv, '/'))
				error_p(*argv, ": ", "No such file or directory", NULL);
			else
				error_p(*argv, ": ", "command not found", NULL);
			exit(127);
		}
	}
	else
	{
		signal(SIGQUIT, listener);
		signal(SIGINT, listener);
		waitpid(sh->child, &sh->status, WUNTRACED);
	}
	return (returner(sh));
}
