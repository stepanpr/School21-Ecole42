/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_escaping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:05:48 by clauren           #+#    #+#             */
/*   Updated: 2020/12/03 14:12:32 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_escaping_additional(char *l, t_parser *d)
{
	if (d->qq)
	{
		if (find_inset(l[d->i + 1], "$\'\"", NULL))
		{
			d->i++;
			d->c = ft_addtostr(d->c, l[d->i]);
			return (1);
		}
		if (l[d->i + 1] != '\\')
			d->c = ft_addtostr(d->c, l[d->i]);
		else
			d->c = ft_addtostr(d->c, l[++d->i]);
		return (1);
	}
	else if (find_inset(l[d->i + 1], "$\'\"\";><\\", NULL))
	{
		d->i++;
		d->c = ft_addtostr(d->c, l[d->i]);
		return (1);
	}
	return (0);
}

int	get_escaping(char *l, t_parser *d, int cnt)
{
	int i;

	i = d->i;
	if (l[d->i] == '\\' && !d->q)
	{
		if (l[d->i + 1] == '\0')
			return (1);
		if (l[d->i + 1] == '\\' && !d->qq)
		{
			while (l[i++] == '\\')
				cnt++;
			if (cnt % 2 != 0 && cnt != 1)
				error_exit(d, 2, '\\');
		}
		if ((l[d->i + 1] == ' ' || l[d->i + 1] == '\t') && d->qq)
			return (0);
		if (l[d->i + 1] == '\'' && d->qq)
			return (0);
		if ((get_escaping_additional(l, d)))
			return (1);
		d->c = ft_addtostr(d->c, l[++d->i]);
		return (1);
	}
	return (0);
}
