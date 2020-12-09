/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirect_addtl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 05:31:31 by emabel            #+#    #+#             */
/*   Updated: 2020/12/06 05:34:02 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			count_filename(char *str, t_parser *d)
{
	int		k;
	int		len;

	k = d->i;
	len = 0;
	while (str[k] != '\0')
	{
		if (str[k + 1] == ';' || str[k + 1] == '\t'
			|| str[k + 1] == ' ' || str[k + 1] == '|')
			break ;
		len++;
		k++;
	}
	return (len);
}

int			get_filename_loop_check_symbols(char *l, t_parser *d)
{
	if (d->file && (l[d->i] == ';' || l[d->i] == '\t' || l[d->i] == ' ' || \
	l[d->i] == '|' || l[d->i] == '\0' || l[d->i] == '<' || l[d->i] == '>'))
	{
		d->file[d->rec] = '\0';
		return (1);
	}
	else if (!d->file && (l[d->i] == ';' || l[d->i] == '\t' \
				|| l[d->i] == ' ' || l[d->i] == '|' || l[d->i] == '\0' \
							|| l[d->i] == '<' || l[d->i] == '>'))
	{
		if (l[d->i] == ';')
		{
			d->sym = ';';
			return (1);
		}
		if (l[d->i] == '|')
		{
			d->sym = '|';
			return (1);
		}
	}
	return (0);
}
