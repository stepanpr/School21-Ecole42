/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 05:34:23 by emabel            #+#    #+#             */
/*   Updated: 2020/12/08 20:10:56 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			get_filename_loop(char *l, t_parser *d)
{
	while (l[d->i++] != '\0')
	{
		if (ft_isalnum(l[d->i]) || l[d->i] == '.' ||
				l[d->i] == '#' || l[d->i] == ',' || l[d->i] == '?')
		{
			if (d->rec == 0)
			{
				d->ln_nm = count_filename(l, d);
				if (!(d->file = malloc(d->ln_nm * sizeof(char) + 1)))
					return (0);
			}
			d->file[d->rec++] = l[d->i];
			if (find_inset(l[d->i + 1], "; |<>", NULL) ||
					l[d->i + 1] == '\t' || l[d->i + 1] == '\0')
			{
				d->file[d->rec] = '\0';
				break ;
			}
		}
		if ((get_filename_loop_check_symbols(l, d)))
			break ;
	}
	return (1);
}

int			get_filename(char *l, t_parser *d)
{
	d->file = NULL;
	d->sym = 0;
	d->ln_nm = 0;
	d->rec = 0;
	get_filename_loop(l, d);
	if (d->file == NULL || d->file[0] == '\0')
	{
		error_exit(d, 2, d->sym);
		return (0);
	}
	return (1);
}

int			get_redirect_forvard(char *l, t_parser *d)
{
	if (l[d->i] == '>')
	{
		if (l[d->i + 2] == '>' && l[d->i + 1] == '>')
		{
			error_exit(d, 2, '>');
			return (0);
		}
		if (l[d->i + 1] == '>' && d->i++)
			d->tp = 2;
		else
			d->tp = 1;
		d->tp_cnt += 1;
		if (get_filename(l, d))
			return (1);
	}
	return (0);
}

int			get_redirect_back(char *l, t_parser *d)
{
	if (l[d->i] == '<')
	{
		if (l[d->i + 1] == '<')
		{
			error_exit(d, 2, '<');
			return (0);
		}
		d->tp = 0;
		d->tp_cnt += 1;
		if (get_filename(l, d))
			return (1);
	}
	return (0);
}

int			get_redirect(char *l, t_parser *d, t_redirect **rdr)
{
	if ((l[d->i] == '>' || l[d->i] == '<') && !d->q && !d->qq)
	{
		if ((get_redirect_forvard(l, d) || (get_redirect_back(l, d))))
		{
			if (d->tp_cnt <= 1)
				*rdr = rdr_new(d->file, d->tp);
			if (d->tp_cnt > 1)
				lab(rdr, rdr_new(d->file, d->tp), NULL, NULL);
			return (1);
		}
		if (d->file)
			free(d->file);
	}
	return (0);
}
