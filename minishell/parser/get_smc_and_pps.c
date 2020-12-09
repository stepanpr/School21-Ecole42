/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_smc_and_pps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 22:22:37 by clauren           #+#    #+#             */
/*   Updated: 2020/12/03 15:32:04 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			check_empty_pipe(char *str, t_parser *d)
{
	int		i;
	int		count;

	i = d->i;
	i++;
	count = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
			count++;
		i++;
	}
	if (count == 0)
		return (1);
	return (0);
}

int			check_double_smcl_and_pps_additional(char *str, t_parser *d)
{
	if (str[d->k] == '"')
		d->qq_gsap = (d->qq_gsap == 0) ? 1 : 0;
	if (str[d->k] == '\'')
		d->q_gsap = (d->q_gsap == 0) ? 1 : 0;
	if ((str[d->k] == ';' || str[d->k] == '|') && !d->qq_gsap && !d->q_gsap)
	{
		d->k++;
		while (str[d->k] == ' ' || str[d->k] == '\t')
			d->k++;
		if ((str[d->k] == ';' || (str[d->k] == '|' &&
			str[d->k - 1] != '|')) && d->qq_gsap != 1 && d->q_gsap != 1)
			return (1);
	}
	return (0);
}

int			check_double_smcl_and_pps_spaces(char *str, t_parser *d)
{
	if (str[0] == ';' || str[0] == '|')
		return (1);
	if ((str[0] == ' ' || str[0] == '\t') && str[d->j + 1] != '\0')
	{
		d->j = 0;
		while (str[d->j] && (str[d->j] == ' ' || str[d->j] == '\t'))
		{
			if (find_inset(str[d->j + 1], ";&|", NULL))
				return (1);
			d->j++;
		}
	}
	return (0);
}

int			check_double_smcl_and_pps(char *str, t_parser *d)
{
	d->k = d->i;
	d->q_gsap = 0;
	d->qq_gsap = 0;
	while (str[d->k] && !d->q && !d->qq)
	{
		if (str[d->k] == '|' && str[d->k + 1] == '|')
			return (1);
		if (str[0] == ';' || str[0] == '|')
			return (1);
		if ((check_double_smcl_and_pps_spaces(str, d)))
			return (1);
		if ((check_double_smcl_and_pps_additional(str, d)))
			return (1);
		d->k++;
	}
	return (0);
}

int			get_smcl_and_pps(char *l, t_parser *d)
{
	d->pipe = 0;
	if ((l[d->i] == ';' || l[d->i] == '|') && !d->q && !d->qq)
	{
		if ((check_double_smcl_and_pps(l, d)))
		{
			error_exit(d, 1, '\0');
			return (0);
		}
		else if (l[d->i] == '|')
		{
			if ((check_empty_pipe(l, d)))
			{
				error_exit(d, 2, '|');
				d->err_flag = 1;
				return (0);
			}
			else
				d->pipe = 1;
		}
		return (1);
	}
	return (0);
}
