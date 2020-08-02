/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 12:02:18 by emabel            #+#    #+#             */
/*   Updated: 2020/07/30 23:39:02 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_percent(t_params *params, char c)
{
	char	symbol;

	if (params->minus != 0)
	{
		params->count += write(1, &c, 1);
		ft_putchar_len(' ', params->width - 1, params);
		return (1);
	}
	else
	{
		symbol = (params->zero == 0) ? ' ' : '0';
		ft_putchar_len(symbol, params->width - 1, params);
		params->count += write(1, &c, 1);
		return (1);
	}
}

int			ft_print_c(t_params *params, char c)
{
	if (c == '%')
		return (print_percent(params, c));
	else
	{
		if (params->minus != 0)
			params->count += write(1, &c, 1);
		ft_putchar_len(' ', params->width - 1, params);
		if (params->minus == 0)
			params->count += write(1, &c, 1);
		return (1);
	}
}
