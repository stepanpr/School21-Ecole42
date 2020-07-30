/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 03:45:39 by emabel            #+#    #+#             */
/*   Updated: 2020/07/30 16:21:54 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_s(char *input, t_params *params)
{
	int 	diff;
	int		input_len;

	if (!input || input == NULL)
		input = "";
	input_len = ft_strlen(input);
	if ((params->accuracy < input_len) && params->dote)
		input_len = params->accuracy;
	diff = params->width - input_len;
	if (params->minus)
		params->length += write(1, input, input_len);
	while (diff-- > 0)
		params->length += write(1, " ", 1);
	if (!(params->minus))
		params->length += write(1, input, input_len);
	return (1);
}
