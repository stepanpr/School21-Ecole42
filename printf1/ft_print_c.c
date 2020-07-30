/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 12:02:18 by emabel            #+#    #+#             */
/*   Updated: 2020/07/30 15:36:00 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int c_type_min(unsigned char c, t_params *params)
{
	int		i;
	char	space;

	space = ' ';
	i = 0;
	i += write(1, &c, 1);
	while ((params->width > 1) && (i < params->width))
		i += write(1, &space, 1);
	params->length += i;
	return (1);
}

static int c_type_width(unsigned char c, t_params *params)
{
	int 	j;
	char	space;

	if (params->zero && params->type == '%')
		space = '0';
	else
		space = ' ';
	j = 0;
	while ((params->width > 1) && (j< (params->width - 1)))
		j += write(1, &space, 1);
	j += write(1, &c, 1);
	params->length += j;
	return (1);
}

int		ft_print_c(va_list *ap, t_params *params)
{
	unsigned char 	c;

	if (params->type == '%')
		c = '%';
	else 
		c = (unsigned char)va_arg(*ap, int);
	if (params->minus)
		c_type_min(c, params);
	else if (params->width >= 0)
		c_type_width(c, params);	
	return (1);
}
