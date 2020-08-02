/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 14:46:03 by emabel            #+#    #+#             */
/*   Updated: 2020/07/31 00:57:00 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_minus(t_params *params, unsigned int digit)
{
	int acc;

	ft_putchar_len('0', params->accuracy - len_u_digit(digit, 'u'), params);
	ft_putunbr(digit, params);
	acc = (params->accuracy > len_u_digit(digit, 'u')) ? (params->accuracy - \
											len_u_digit(digit, 'u')) : 0;
	ft_putchar_len(' ', params->width - acc - len_u_digit(digit, 'u'), params);
	return (1);
}

static int	print_plus(t_params *params, unsigned int digit)
{
	int		acc;
	char	c;

	if (params->accuracy != -1)
	{
		acc = (params->accuracy > len_u_digit(digit, 'u')) ? (params->accuracy \
											- len_u_digit(digit, 'u')) : 0;
		ft_putchar_len(' ', params->width - acc - \
											len_u_digit(digit, 'u'), params);
		ft_putchar_len('0', acc, params);
		ft_putunbr(digit, params);
		return (1);
	}
	c = (params->zero != 0) ? '0' : ' ';
	ft_putchar_len(c, params->width - len_u_digit(digit, 'u'), params);
	ft_putunbr(digit, params);
	return (1);
}

int			ft_print_u(t_params *params, va_list *arg)
{
	unsigned int	digit;

	digit = va_arg(*arg, unsigned int);
	if (digit == 0 && params->accuracy == 0)
	{
		ft_putchar_len(' ', params->width, params);
		return (1);
	}
	if (params->minus != 0)
		return (print_minus(params, digit));
	return (print_plus(params, digit));
}
