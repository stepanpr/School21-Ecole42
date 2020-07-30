/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 12:49:03 by emabel            #+#    #+#             */
/*   Updated: 2020/07/30 15:35:47 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_params	ft_parser_init(void)
{
	t_params params;
	
	params.specificator = 0;
	// params.value = 0;
	// params.flags = 0;
	params.minus = 0;
	params.zero = 0;
	params.type = '\0';
	params.dote = 0;
	params.accuracy = 0;
	params.width = 0;
	params.length = 0;
	// params.value_c = 0;
	
	return (params);
}

static void parser_flags(t_params *params)
{
	while (*params->specificator)
	{
		if (*params->specificator == '-' && ft_isalpha((*params->specificator) + 1))  
			break ;
		if (*params->specificator == '-')
			params->minus = '-';
		else if (*params->specificator == '0')
			params->zero = '0';
		else 
			break ;
		params->specificator++;
	}
}

static void parser_width(t_params *params, va_list *ap)
{
	if (*params->specificator== '*')
	{
		params->width = va_arg(*ap, int);
		params->specificator++;
		if (params->width < 0)
		{
			params->minus = '-';
			if (params->zero == '0')
				params->zero = '\0';
			params->width *= -1; 
		}
	}
	else
	{
		params->width = ft_atoi(params->specificator);
		while (ft_isdigit(*params->specificator))
			params->specificator++;	
	}
}

static int 	parser_prec(t_params *params, va_list *ap)
{
	params->dote = 1;
	params->specificator++;
	if (ft_isalpha(*params->specificator))
		return(1);
	else if (*params->specificator == '*')
	{
		params->accuracy = va_arg(*ap, int);
		if (params->accuracy < 0)
			params->dote = 0;
		params->specificator++;
	} 
	else
	{
		params->accuracy = ft_atoi(params->specificator);
		if (params->accuracy < 0)
		{
			params->dote = -1;
			return (0);
		}
		while (ft_isdigit(*params->specificator))
			params->specificator++;
	}
	return (1);
}

int	parser(const char *format, va_list *ap, t_params *params, int *len_spec, int *len_cicle)
{

	*params = ft_parser_init();
	params->specificator = ft_get_spec((char *)format);
	*len_spec = ft_strlen(params->specificator);
	parser_flags(params);
	parser_width(params, ap);
	if (*params->specificator == '.' && !(parser_prec(params, ap)))
		return (1);
	else
		params->type = *params->specificator;
	if (params->minus && params->zero)
		params->zero = 0;
	
	ft_get_value(ap, params); 
	*len_cicle += params->length;
	
	return (0);
}
