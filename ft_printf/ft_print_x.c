/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:12:54 by emabel            #+#    #+#             */
/*   Updated: 2020/07/31 01:01:31 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_x(unsigned int digit, t_params *params)
{
	int	num;
	int	symbol;

	symbol = (params->type == 'x') ? 39 : 7;
	if (digit > 15)
		print_x(digit / 16, params);
	num = digit % 16 + 48;
	if (ft_isdigit(num))
		params->count += ft_putchar(num);
	else
		params->count += ft_putchar(num + symbol);
}

static int	x_minus(t_params *params, unsigned int digit)
{
	int	acc;

	ft_putchar_len('0', params->accuracy - len_u_digit(digit, 'x'), params);
	print_x(digit, params);
	acc = (params->accuracy > len_u_digit(digit, 'x')) ? (params->accuracy - \
											len_u_digit(digit, 'x')) : 0;
	ft_putchar_len(' ', params->width - acc - len_u_digit(digit, 'x'), params);
	return (1);
}

static int	x_plus(t_params *params, unsigned int digit)
{
	int		acc;
	char	c;

	if (params->accuracy != -1)
	{
		acc = (params->accuracy > len_u_digit(digit, 'x')) ? \
						(params->accuracy - len_u_digit(digit, 'x')) : 0;
		ft_putchar_len(' ', params->width - acc - \
										len_u_digit(digit, 'x'), params);
		ft_putchar_len('0', acc, params);
		print_x(digit, params);
		return (1);
	}
	c = (params->zero != 0) ? '0' : ' ';
	ft_putchar_len(c, params->width - len_u_digit(digit, 'x'), params);
	print_x(digit, params);
	return (1);
}

int			ft_print_x(t_params *params, va_list *ap)
{
	unsigned int	digit;

	digit = va_arg(*ap, unsigned int);
	if (digit == 0 && params->accuracy == 0)
	{
		ft_putchar_len(' ', params->width, params);
		return (1);
	}
	if (params->minus != 0)
		return (x_minus(params, digit));
	return (x_plus(params, digit));
}
