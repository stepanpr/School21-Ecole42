/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 00:12:49 by clauren           #+#    #+#             */
/*   Updated: 2020/12/07 03:34:33 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		unset_swap(char **env, char **key)
{
	int		i;
	int		key_len;

	key_len = 0;
	i = 0;
	while (env[i])
	{
		if (!(key_len = ft_strpos(env[i], '=') - 1))
			key_len = ft_strlen(env[i]);
		if (ft_strncmp(env[i], *key, key_len) == 0)
		{
			free(env[i]);
			env[i] = env[i + 1];
			while (env[++i])
				env[i] = env[i + 1];
			break ;
		}
		i++;
	}
}

void		print_env_line(char **envp, char *line)
{
	char *value;

	value = env_get(envp, line, 0);
	ft_putstr_fd("declare -x ", 1);
	ft_putstr_fd(line, 1);
	if (value)
	{
		ft_putstr_fd("=\"", 1);
		ft_putstr_fd(value, 1);
		ft_putstr_fd("\"", 1);
	}
	ft_putchar_fd('\n', 1);
}

void		sort_keys(char ***envp, int count)
{
	char	*buff;
	int		end;
	int		i;

	end = 1;
	while (end)
	{
		i = 0;
		end = 0;
		while (i < count)
			if (ft_strcmp((*envp)[i], (*envp)[i + 1]) > 0)
			{
				end = 1;
				buff = (*envp)[i];
				(*envp)[i] = (*envp)[i + 1];
				(*envp)[i + 1] = buff;
			}
			else
				i++;
	}
}

char		*env_get(char **env, char *key, int only_key)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(key);
	if (only_key)
	{
		while (env[i])
		{
			if (ft_strncmp(env[i], key, len) == 0 &&
				(((env[i])[len] == '\0') || ((env[i])[len] == '=')))
				return (env[i]);
			i++;
		}
		return (NULL);
	}
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], key, len) == 0 && ((env[i])[len] == '='))
			return (env[i] + len + 1);
		i++;
	}
	return (NULL);
}

char		**check_env_name(char *str, int only_key, int *add)
{
	char	**result;
	char	*key;
	char	*value;

	if (only_key)
		return (only_key_check(str));
	value = ft_strchr(str, '=');
	if (ft_strnstr(str, "+=", ft_strlen(str)) && (*add = 1))
		key = ft_substr(str, 0, ft_strlen(str) - ft_strlen(value) - 1);
	else
		key = ft_substr(str, 0, ft_strlen(str) - ft_strlen(value));
	if (!check_env_name(key, 1, NULL))
	{
		free(key);
		return (NULL);
	}
	result = malloc(sizeof(char *) * 2);
	result[0] = key;
	result[1] = value;
	return (result);
}
