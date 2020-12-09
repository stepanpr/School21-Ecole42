/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 05:26:47 by emabel            #+#    #+#             */
/*   Updated: 2020/12/06 05:51:08 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			error_exit(t_parser *d, int key, char sym)
{
	if (key == 2)
	{
		ft_putstr_fd(
"\e[1;32mminishell:\e[0m \e[1;33msyntax error near unexpected token \'\e[0m",
								1);
		if (sym == '\0')
			ft_putstr_fd("\e[1;33mnewline\'\e[0m\n", 1);
		if (sym != '\0')
		{
			ft_putstr_fd("\e[1;33m", 1);
			ft_putchar_fd(sym, 1);
			ft_putstr_fd("\'\e[0m\n", 1);
		}
	}
	if (key == 1)
	{
		ft_putstr_fd("\e[1;32mminishell:\e[0m \e[1;33msyntax error\e[0m\n", 1);
	}
	d->exit = 2;
	d->status = 2;
	return (0);
}
