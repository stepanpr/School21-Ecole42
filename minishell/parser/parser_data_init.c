/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_data_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:05:48 by clauren           #+#    #+#             */
/*   Updated: 2020/12/07 02:17:01 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	parser_data_init(t_parser *d, t_command **cmd, t_redirect **rdr)
{
	d->pipe = 0;
	d->qq = 0;
	d->q = 0;
	d->tp_cnt = 0;
	d->file = NULL;
	d->i = -1;
	d->c = NULL;
	d->args = NULL;
	d->esc = 0;
	d->exit = 0;
	d->l = NULL;
	*cmd = NULL;
	*rdr = NULL;
	d->key = NULL;
	d->value = NULL;
	d->err_flag = 0;
	return (1);
}
