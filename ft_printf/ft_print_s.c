/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 03:45:39 by emabel            #+#    #+#             */
/*   Updated: 2020/08/01 22:39:48 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_plus(t_params *params, char *string)
{
	int	count;
	int	len;

	count = 0;
	if (params->accuracy != -1)
	{
		if (params->accuracy == 0)
		{
			ft_putchar_len(' ', params->width, params);
			return (1);
		}
		len = (params->accuracy > ft_strlen(string)) ? ft_strlen(string) : \
													params->accuracy;
		ft_putchar_len(' ', params->width - len, params);
		while (count < len)
			params->count += ft_putchar(string[count++]);
		return (1);
	}
	ft_putchar_len(' ', params->width - ft_strlen(string), params);
	while (count < ft_strlen(string))
		params->count += ft_putchar(string[count++]);
	return (1);
}

static int	print_minus(t_params *params, char *string)
{
	int	count;

	count = 0;
	if (params->accuracy != -1)
	{
		while (string[count] != '\0' && count < params->accuracy)
			params->count += ft_putchar(string[count++]);
		while (count++ < params->width)
			params->count += ft_putchar(' ');
		return (1);
	}
	while (count < ft_strlen(string))
		params->count += ft_putchar(string[count++]);
	ft_putchar_len(' ', params->width - ft_strlen(string), params);
	return (1);
}

int			ft_print_s(t_params *par, va_list *ap)
{
	char	*string;

	if (!(string = va_arg(*ap, char *)))
		string = "(null)";
	if (par->minus != 0)
		return (print_minus(par, string));
	return (print_plus(par, string));
}
