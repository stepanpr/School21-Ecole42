/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 22:55:33 by clauren           #+#    #+#             */
/*   Updated: 2020/12/06 20:13:44 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			unset(char **env, char **key)
{
	while (*++key)
	{
		if (!(check_env_name(*key, 1, NULL)))
		{
			error_p("unset: `", *key, "': not a valid identifier", NULL);
			return (1);
		}
		unset_swap(env, key);
	}
	return (0);
}

int			env(char **envp, int sort)
{
	char	**keys;
	int		len;

	if (!sort || ((len = array_size(envp)) == 0))
	{
		while (*envp)
			if (ft_strpos(*envp++, '='))
				ft_putendl_fd(*(envp - 1), 1);
		return (0);
	}
	keys = malloc(sizeof(char *) * (len + 1));
	keys[len] = 0;
	while (--len >= 0)
		keys[len] = ft_substr(envp[len], 0, (ft_strpos(envp[len], '=') - 1));
	sort_keys(&keys, array_size(envp) - 1);
	len = 0;
	while (keys[len])
	{
		print_env_line(envp, keys[len]);
		free(keys[len++]);
	}
	free(keys);
	return (0);
}

void		env_new(char ***envp, char **arr)
{
	char	**result;
	int		k;
	int		size;

	k = -1;
	size = array_size(*envp);
	if (!(result = malloc(sizeof(char *) * (size + 2))))
		return ;
	while ((*envp)[++k])
		result[k] = (*envp)[k];
	if (!arr[1])
		result[k++] = ft_strdup(arr[0]);
	else
		result[k++] = ft_strjoin(arr[0], arr[1]);
	result[k] = 0;
	free(*envp);
	*envp = result;
}

void		env_re(char ***envp, char **a, int add, int i)
{
	char	*buff;
	int		key_len;

	while ((*envp)[++i] && (a[1] || ft_strequ(a[0], "OLDPWD")))
	{
		if (!(key_len = ft_strpos((*envp)[i], '=') - 1))
			key_len = ft_strlen((*envp)[i]);
		if (!ft_strncmp(a[0], (*envp)[i], key_len))
		{
			if (!add)
			{
				free((*envp)[i]);
				if (a[1] || !ft_strequ(a[0], "OLDPWD"))
					(*envp)[i] = ft_strjoin(a[0], a[1]);
				else
					(*envp)[i] = ft_strdup(a[0]);
			}
			else if ((buff = ft_strjoin((*envp)[i], a[1] + 1)))
			{
				free((*envp)[i]);
				(*envp)[i] = buff;
			}
			break ;
		}
	}
}

int			export(t_sh *sh, char ***envp, char **args, int f)
{
	char	**arr;
	int		add;
	int		status;

	add = 0;
	if (!*args--)
		return (env(*envp, 1));
	if (!f && (sh->piped || sh->old_pipe))
		return (0);
	while (*++args && !(status = 0))
	{
		if (!(arr = check_env_name(*args, 0, &add)))
		{
			error_p("export: `", *args, "': not a valid identifier", NULL);
			status = 1;
			continue ;
		}
		if (!env_get(*envp, arr[0], 1))
			env_new(envp, arr);
		else
			env_re(envp, arr, add, -1);
		free(arr[0]);
		free(arr);
	}
	return (status);
}
