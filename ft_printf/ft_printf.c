/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 09:25:48 by emabel            #+#    #+#             */
/*   Updated: 2020/08/02 00:06:57 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strchr_print_c(const char *s, int c, t_params *params)
{
	if ((char)c == '\0')
	{
		while (*s != '\0')
		{
			ft_putchar(*s);
			s++;
			params->count++;
		}
		return ((char *)s);
	}
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		ft_putchar(*s);
		s++;
		params->count++;
	}
	return (NULL);
}

int			parser_type(t_params *params, va_list *ap)
{
	if (params->type == 'c')
		return (ft_print_c(params, (char)va_arg(*ap, int)));
	else if (params->type == 's')
		return (ft_print_s(params, ap));
	else if (params->type == 'p')
		return (ft_print_p(params, ap));
	else if (params->type == 'd' || params->type == 'i')
		return (ft_print_d_i(params, ap));
	else if (params->type == 'u')
		return (ft_print_u(params, ap));
	else if (params->type == 'x' || params->type == 'X')
		return (ft_print_x(params, ap));
	else if (params->type == '%')
		return (ft_print_c(params, '%'));
	return (-1);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_params	*params;
	int			length;
	char		*string;

	length = 0;
	string = (char*)format;
	if (!(params = (t_params*)malloc(sizeof(t_params))))
		return (-1);
	params->count = 0;
	va_start(ap, format);
	while (string && *string != '\0')
	{
		if ((string = ft_strchr_print_c(string, '%', params)))
		{
			if (ft_parser(&string, params, &ap) == -1)
				break ;
		}
		else
			break ;
	}
	length = params->count;
	free(params);
	va_end(ap);
	return (length);
}
