/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 09:25:48 by emabel            #+#    #+#             */
/*   Updated: 2020/07/30 16:53:28 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_value(va_list *ap, t_params *params)
{	
	if (*params->specificator == 'd' || *params->specificator == 'i')		
		ft_print_d_i(va_arg(*ap, int), params);

	if (*params->specificator  == 'c' || *params->specificator  == '%')
		ft_print_c(ap, params);

	if (*params->specificator  == 's')
		ft_print_s((va_arg(*ap, char *)), params);
		
	if (*params->specificator  == 'x' || *params->specificator  == 'X')
		ft_print_x(params, ap);

	if (*params->specificator  == 'u')
		ft_print_u(params, ap);

	if (*params->specificator  == 'p')
		ft_print_p(params, ap);
	return (1);
}

int ft_printf(const char *format, ...)   
{
	va_list			ap;
	t_params		params;
	int				total_length;
	int 			len_spec;
	int				len_cicle;

	if(!format)
		return (-1);
	va_start(ap, format);
	total_length = 0;
	len_cicle = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{	
			format++;
			if (parser(format, &ap, &params, &len_spec, &len_cicle))
				return (-1);
			format += len_spec;
		}
		else 
		{
			total_length += write(1, format++, 1);
		}
	}
	
	va_end(ap);
	return (total_length + len_cicle);
}
