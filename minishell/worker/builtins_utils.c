/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 00:08:41 by clauren           #+#    #+#             */
/*   Updated: 2020/12/06 17:10:45 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		echo_n(char **argv)
{
	char	*trimmed;
	int		n;

	n = 0;
	trimmed = NULL;
	while (argv[n] && (trimmed = ft_strtrim(argv[n], "n")))
	{
		if (ft_strequ(trimmed, "-"))
			n += 1;
		else
			break ;
		free(trimmed);
		trimmed = NULL;
	}
	if (trimmed)
		free(trimmed);
	return (n);
}

void	set_pwds(t_sh *sh, char ***args)
{
	char *p;

	p = NULL;
	p = getcwd(p, 0);
	if ((*args[0] = ft_strjoin("OLDPWD=", env_get(sh->env, "PWD", 0))))
	{
		export(sh, &sh->env, *args, 0);
		free(*args[0]);
	}
	else
	{
		*args[0] = "OLDPWD";
		export(sh, &sh->env, *args, 1);
	}
	*args[0] = ft_strjoin("PWD=", p);
	free(p);
	if (*args[0])
		export(sh, &sh->env, *args, 0);
	else
	{
		*args[0] = ft_strjoin("PWD+=", "/.");
		export(sh, &sh->env, *args, 0);
	}
	free(*args[0]);
}

int		returner(t_sh *sh)
{
	if (WIFSIGNALED(sh->status))
	{
		if (WTERMSIG(sh->status) == 2)
			return (130);
		if (WTERMSIG(sh->status) == 3)
			return (131);
	}
	return (WEXITSTATUS(sh->status));
}
