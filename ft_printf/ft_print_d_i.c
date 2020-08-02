/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 16:38:44 by emabel            #+#    #+#             */
/*   Updated: 2020/08/01 13:37:50 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_digit(t_params *params, int digit)
{
	int	acc;

	if (digit < 0)
	{
		acc = (params->accuracy > (len_digit(digit) - 1)) ? (params->accuracy \
													- len_digit(digit) + 1) : 0;
		ft_putchar_len(' ', params->width - acc - len_digit(digit), params);
		params->count += ft_putchar('-');
		ft_putchar_len('0', acc, params);
		ft_putnbr(digit * -1, params);
	}
	else
	{
		acc = (params->accuracy > len_digit(digit)) ? (params->accuracy - \
													len_digit(digit)) : 0;
		ft_putchar_len(' ', params->width - acc - len_digit(digit), params);
		ft_putchar_len('0', acc, params);
		ft_putnbr(digit, params);
	}
	return (1);
}

static int	print_plus(t_params *params, int digit)
{
	char	c;

	if (params->accuracy == -1)
	{
		if (digit < 0)
		{
			if (params->zero != 0)
			{
				params->count += ft_putchar('-');
				ft_putchar_len('0', params->width - len_digit(digit), params);
				ft_putnbr(digit * -1, params);
				return (1);
			}
			ft_putchar_len(' ', params->width - len_digit(digit), params);
			ft_putnbr(digit, params);
		}
		else
		{
			c = (params->zero != 0) ? '0' : ' ';
			ft_putchar_len(c, params->width - len_digit(digit), params);
			ft_putnbr(digit, params);
		}
		return (1);
	}
	return (print_digit(params, digit));
}

static int	print_minus(t_params *params, int digit)
{
	int	acc;

	if (digit >= 0)
	{
		ft_putchar_len('0', params->accuracy - len_digit(digit), params);
		ft_putnbr(digit, params);
		acc = (params->accuracy > len_digit(digit)) ? \
							(params->accuracy - len_digit(digit)) : 0;
		ft_putchar_len(' ', params->width - acc - len_digit(digit), params);
	}
	else
	{
		params->count += ft_putchar('-');
		ft_putchar_len('0', params->accuracy - len_digit(digit) + 1, params);
		ft_putnbr(digit * -1, params);
		acc = (params->accuracy > (len_digit(digit) - 1)) ? (params->accuracy \
													- len_digit(digit) + 1) : 0;
		ft_putchar_len(' ', params->width - acc - len_digit(digit), params);
	}
	return (1);
}

int			ft_print_d_i(t_params *params, va_list *ap)
{
	int	digit;

	digit = va_arg(*ap, int);
	if (digit == 0 && params->accuracy == 0)
	{
		ft_putchar_len(' ', params->width, params);
		return (1);
	}
	if (digit == -2147483648)
		return (print_max_digit(params, digit));
	if (params->minus != 0)
		return (print_minus(params, digit));
	return (print_plus(params, digit));
}
