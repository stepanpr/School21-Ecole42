/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 00:40:31 by clauren           #+#    #+#             */
/*   Updated: 2020/12/08 20:42:58 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

static int		copy_2arr(char ***dst, char **src)
{
	int	i;

	i = 0;
	if (!(*dst = malloc(sizeof(char *) * (array_size(src) + 1))))
		return (0);
	while (src[i])
	{
		if (!((*dst)[i] = ft_strdup(src[i])))
			return (0);
		i++;
	}
	(*dst)[i] = 0;
	return (1);
}

static void		detect_pipe(t_sh *sh)
{
	char		**arr;
	char		*p;
	struct stat fd0;

	fstat(0, &fd0);
	p = NULL;
	if (S_ISCHR(fd0.st_mode))
		sh->from_pipe = 0;
	else
		sh->from_pipe = 1;
	arr = ft_calloc(2, sizeof(char *));
	arr[0] = "OLDPWD";
	export(sh, &sh->env, arr, 1);
	p = getcwd(p, 0);
	arr[0] = ft_strjoin("PWD=", p);
	free(p);
	export(sh, &sh->env, arr, 1);
	free(arr[0]);
	free(arr);
}

int				main(int argc, char *argv[], char *envp[])
{
	t_sh *sh;

	(void)argc;
	(void)argv;
	if (!(sh = malloc(sizeof(t_sh))) || !copy_2arr(&sh->env, envp))
		return (0);
	sh->status = 0;
	detect_pipe(sh);
	while (1)
	{
		if (!sh->from_pipe)
			ft_putstr_fd("\e[1;32mminishell$\e[0m ", 1);
		signal(SIGINT, sighandler);
		signal(SIGQUIT, sighandler);
		parser(sh);
	}
	return (0);
}
