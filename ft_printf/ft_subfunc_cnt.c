/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subfunc_cnt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 14:20:41 by emabel            #+#    #+#             */
/*   Updated: 2020/08/02 00:19:51 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_strlen(char *str)
{
	int	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int			len_u_digit(size_t digit, char type)
{
	int	count;
	int	point;

	count = 1;
	point = (type == 'x' || type == 'X' || type == 'p') ? 16 : 10;
	while (digit / point)
	{
		digit /= point;
		count++;
	}
	return (count);
}

int			len_digit(int digit)
{
	int				count;
	unsigned int	num;

	count = 1;
	if (digit < 0)
	{
		count++;
		num = digit * -1;
	}
	else
		num = digit;
	while (num / 10)
	{
		count++;
		num /= 10;
	}
	return (count);
}

static int	print_max_digit_ret(t_params *params, int digit)
{
	if (params->zero != 0)
	{
		params->count += ft_putchar('-');
		ft_putchar_len('0', params->width - len_digit(digit), params);
		params->count += ft_putchar('2');
		ft_putnbr(147483648, params);
		return (1);
	}
	ft_putchar_len(' ', params->width - len_digit(digit), params);
	params->count += ft_putchar('-');
	params->count += ft_putchar('2');
	ft_putnbr(147483648, params);
	return (1);
}

int			print_max_digit(t_params *params, int digit)
{
	if (params->minus != 0)
	{
		params->count += ft_putchar('-');
		ft_putchar_len('0', params->accuracy - len_digit(digit) + 1, params);
		params->count += ft_putchar('2');
		ft_putnbr(147483648, params);
		params->accuracy = (params->accuracy > (len_digit(digit) - 1)) ? \
								(params->accuracy - len_digit(digit) + 1) : 0;
		ft_putchar_len(' ', params->width - params->accuracy - \
											len_digit(digit), params);
		return (1);
	}
	if (params->accuracy != -1)
	{
		params->acc = (params->accuracy > (len_digit(digit) - 1)) ? \
						(params->accuracy - len_digit(digit) + 1) : 0;
		ft_putchar_len(' ', params->width - params->acc - \
										len_digit(digit), params);
		params->count += ft_putchar('-');
		ft_putchar_len('0', params->accuracy - len_digit(digit) + 1, params);
		params->count += ft_putchar('2');
		ft_putnbr(147483648, params);
		return (1);
	}
	return (print_max_digit_ret(params, digit));
}
