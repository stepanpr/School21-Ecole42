/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 15:15:11 by emabel            #+#    #+#             */
/*   Updated: 2020/08/01 22:55:03 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_p(size_t pointer, t_params *params)
{
	size_t	num;

	if (pointer > 15)
		print_p(pointer / 16, params);
	num = pointer % 16 + 48;
	if (ft_isdigit(num))
		params->count += ft_putchar(num);
	else
		params->count += ft_putchar(num + 39);
}

static int	p_minus(t_params *params, size_t pointer)
{
	params->count += ft_putchar('0');
	params->count += ft_putchar('x');
	print_p(pointer, params);
	ft_putchar_len(' ', params->width - len_u_digit(pointer, 'p') - 2, params);
	return (1);
}

static int	p_plus(t_params *params, size_t pointer)
{
	if (params->zero != 0)
	{
		params->count += ft_putchar('0');
		params->count += ft_putchar('x');
		ft_putchar_len('0', params->width - len_u_digit(pointer, 'p') - 2, \
																params);
		print_p(pointer, params);
		return (1);
	}
	ft_putchar_len(' ', params->width - len_u_digit(pointer, 'p') - 2, params);
	params->count += ft_putchar('0');
	params->count += ft_putchar('x');
	print_p(pointer, params);
	return (1);
}

int			ft_print_p(t_params *params, va_list *ap)
{
	size_t	pointer;

	pointer = va_arg(*ap, size_t);
	if (params->minus != 0)
		return (p_minus(params, pointer));
	return (p_plus(params, pointer));
}
