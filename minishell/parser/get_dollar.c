/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dollar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:36:29 by clauren           #+#    #+#             */
/*   Updated: 2020/12/06 17:29:30 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			get_dollar_isgigit(char *l, t_parser *d)
{
	char	*echo0;

	echo0 = "minishell";
	if (ft_isdigit(l[d->i + 1]))
	{
		if (l[d->i + 1] == '0')
		{
			while (echo0 && *echo0)
				d->c = ft_addtostr(d->c, *echo0++);
		}
		d->i += 2;
		if (l[d->i] == '\0')
			return (1);
		return (0);
	}
	return (0);
}

int			get_dollar_varvalue(char *l, char **env, t_parser *d)
{
	if (d->key[0] != '_' && find_inset(d->key[0], "?\\%^&#(", NULL))
	{
		d->i--;
		free(d->key);
		return (0);
	}
	d->value = env_get(env, d->key, 0);
	free(d->key);
	while (d->value && (*d->value == ' '))
		d->value++;
	while (d->value && *d->value)
	{
		if (*d->value++ == ' ' && (*d->value == ' ' || *d->value == '\0'))
			continue ;
		if (*(d->value - 1) == ' ')
		{
			d->c = ft_addtostr(d->c, '*');
			continue ;
		}
		d->c = ft_addtostr(d->c, *(d->value - 1));
	}
	d->i += word_len(l + d->i) - 1;
	return (1);
}

int			get_dollar(char *l, char **env, t_parser *d)
{
	if (l[d->i] == '$' && !d->esc && !d->q && (l[d->i + 1] != '\0'))
	{
		if (l[d->i + 1] == ' ' || l[d->i + 1] == '"' ||
			l[d->i + 1] == '\t' || l[d->i + 1] == '=' ||
			l[d->i + 1] == '\\' || l[d->i + 1] == '<' || l[d->i + 1] == '>')
			return (0);
		if ((get_dollar_isgigit(l, d)))
			return (1);
		d->i++;
		d->key = ft_substr(l, d->i, word_len(l + d->i));
		if (find_inset(d->key[0], "!@#", ft_isdigit))
		{
			free(d->key);
			return (1);
		}
		if (!(get_dollar_varvalue(l, env, d)))
			return (0);
		return (1);
	}
	return (0);
}
