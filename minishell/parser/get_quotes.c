/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 05:28:27 by emabel            #+#    #+#             */
/*   Updated: 2020/12/06 05:28:30 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_quotes(char c, t_parser *d)
{
	if (c == '\'' && !d->qq)
	{
		d->q = (d->q == 0) ? 1 : 0;
		return (1);
	}
	if (c == '"' && !d->q)
	{
		d->qq = (d->qq == 0) ? 1 : 0;
		return (1);
	}
	return (0);
}

int	quote_mark_closed(t_parser *d)
{
	if (d->q == 1)
		error_exit(d, 2, '\'');
	if (d->qq == 1)
		error_exit(d, 2, '"');
	return (0);
}
