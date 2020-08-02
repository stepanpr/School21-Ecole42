/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 12:49:03 by emabel            #+#    #+#             */
/*   Updated: 2020/08/02 00:17:45 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_params	ft_parser_init(t_params *params)
{
	params->minus = 0;
	params->zero = 0;
	params->accuracy = -1;
	params->acc = 0;
	params->width = 0;
	params->type = 0;
	params->hash = 0;
	params->space = 0;
	params->plus = 0;
	return (*params);
}

static char		*parser_flags(char *string, t_params *params)
{
	while (string)
	{
		if (*string == '-')
			params->minus = '-';
		else if (*string == '0')
			params->zero = '0';
		else if (*string == '#')
			params->hash = 1;
		else if (*string == ' ')
			params->space = 1;
		else if (*string == '+')
			params->plus = 1;
		else
			return (string);
		string++;
	}
	return (NULL);
}

static char		*parser_width(char *string, va_list *ap, t_params *params)
{
	int	width;

	width = 0;
	if (*string == '*')
	{
		if ((params->width = va_arg(*ap, int)) < 0)
		{
			params->width *= -1;
			params->minus = '-';
		}
		return (++string);
	}
	if (*string == '.' || !ft_isdigit(*string))
	{
		params->width = 0;
		return (string);
	}
	while (ft_isdigit(*string))
	{
		width = width * 10 + *string - 48;
		string++;
	}
	params->width = width;
	return (string);
}

static char		*parser_accuracy(char *string, t_params *params, va_list *ap)
{
	int	accuracy;

	accuracy = 0;
	if (*string == '*')
	{
		if ((params->accuracy = va_arg(*ap, int)) < 0)
			params->accuracy = -1;
		return (++string);
	}
	if (ft_isdigit(*string))
	{
		while (ft_isdigit(*string))
		{
			accuracy = accuracy * 10 + *string - 48;
			string++;
		}
		params->accuracy = accuracy;
	}
	else
		params->accuracy = 0;
	return (string);
}

int				ft_parser(char **string, t_params *params, va_list *ap)
{
	ft_parser_init(params);
	*string = parser_flags((*string) + 1, params);
	*string = parser_width(*string, ap, params);
	if (**string == '.')
		*string = parser_accuracy((*string) + 1, params, ap);
	else
		params->accuracy = -1;
	params->type = **string;
	(*string)++;
	return (parser_type(params, ap));
}
