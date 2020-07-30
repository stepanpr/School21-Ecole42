/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 14:46:03 by emabel            #+#    #+#             */
/*   Updated: 2020/07/30 13:31:03 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	u_minus(t_params *params, unsigned int digit)
{
	int accuracy;

	ft_putchar_len('0', params->accuracy - len_u_digit(digit, 'u'), params);
	ft_putunbr(digit, params);
	accuracy = (params->accuracy > len_u_digit(digit, 'u')) ? (params->accuracy - \
											len_u_digit(digit, 'u')) : 0;
	ft_putchar_len(' ', params->width - accuracy - len_u_digit(digit, 'u'), params);
	return (1);
}

static int	u_plus(t_params *params, unsigned int digit)
{
	int		accuracy;
	char	c;

	if (params->accuracy != 0)
	{
		accuracy = (params->accuracy > len_u_digit(digit, 'u')) ? (params->accuracy - \
											len_u_digit(digit, 'u')) : 0;
		ft_putchar_len(' ', params->width - accuracy - \
											len_u_digit(digit, 'u'), params);
		ft_putchar_len('0', accuracy, params);
		ft_putunbr(digit, params);
		return (1);
	}
	c = (params->zero != 0) ? '0' : ' ';
	ft_putchar_len(c, params->width - len_u_digit(digit, 'u'), params);
	ft_putunbr(digit, params);
	return (1);
}

int			ft_print_u(t_params *params, va_list *ap)
{
	unsigned int	digit;

	digit = va_arg(*ap, unsigned int);
	if (digit == 0 && params->accuracy == 0)
	{
		ft_putchar_len(' ', params->width, params);
		return (1);
	}
	if (params->minus != 0)
		return (u_minus(params, digit));
	return (u_plus(params, digit));
}
