/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 16:38:44 by emabel            #+#    #+#             */
/*   Updated: 2020/07/30 16:53:11 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	d_i_zero(int input, int len, t_params *params)
{
	int 	zero_count;
	int i = 0;

	zero_count = 0;
	if (params->width > len)
		zero_count = params->width - len - (input < 0 ? 1 : 0);
	if (input < 0)
	{
		input = input * -1;
		zero_count = zero_count + 1;
		params->length += write(1, "-", 1);
	}
	if (zero_count > 0)
	{
		while (i < zero_count)
		{
			params->length += write(1, "0", 1);
			i++;
		}
		
	}
	ft_putnbr(input, params);
}

static void	d_i_dote(int input, int len, t_params *params)
{
	int spaces_count;
	int zero_count;
	
	spaces_count = 0;
	zero_count = 1;
	if (params->accuracy > len)
		(zero_count = params->accuracy - len) ;
	if (params->width > (len + zero_count + (input < 0 ? 1 : 0)))
		spaces_count = params->width - len - zero_count - (input < 0 ? 0 : 0);
	if (input < 0 && params->width > params->accuracy)
	{
	 	spaces_count--;
	}
	if (params->minus)
	{
		if (input < 0)
		{
			input = input * -1;
			ft_putnchar('-', 1, params);  
			if (params->width > params->accuracy)
				zero_count++;
		}
		if (params->accuracy <= len && input > 0)
			(zero_count--);    
		ft_putnchar('0', zero_count, params);
		ft_putnbr(input, params);
		ft_putnchar(' ', spaces_count, params);
	}
	else
	{
		if(params->accuracy == 0 && params->dote == 1)
			zero_count = zero_count - 1;
		if (params->accuracy > len && input < 0)
			zero_count++;
		if (params->accuracy <= len && input > 0)
		{
			zero_count--; 
			spaces_count++;
		}  
		if ((params->accuracy - len == 1) && input < 0)
			len++;
		ft_putnchar(' ', spaces_count, params);
		if (input < 0)
		{
		input = input * -1;
			ft_putnchar('-', 1, params);
		}
		ft_putnchar('0', zero_count, params);
		ft_putnbr(input, params);
	}
	
}

static void d_i_minus(int input, int len, t_params *params)
{
	int space_count;

	space_count = params->width - len;
	if (input < 0)
	{
		input = input * -1;
		ft_putnchar('-', 1, params);
	}
	if (len != 0)
	 	ft_putnbr(input, params);
	if (space_count > 0)
		ft_putnchar(' ', space_count , params);
}

static void		d_i_width(int input, int len, t_params *params)
{
	int 		space_count;

	space_count = params->width - len;
	if (space_count > 0)
		ft_putnchar(' ', space_count, params);
	if (input < 0)
	{
		input = input * -1;
		ft_putnchar('-', 1, params);
	}
	if (len != 0)
		ft_putnbr(input, params);
}

int 	ft_print_d_i(int input, t_params *params)
{
	int input_len;

	input_len = ft_strlen(ft_itoa(input));
	if ((params->accuracy == 0) && (params->dote) && (input == 0))
		input_len = 0;
	if(!(params->dote) && (params->zero))
		d_i_zero(input, input_len, params);
	else if ((params->dote) && !(params->accuracy == 0 && input == 0))
		d_i_dote(input, input_len, params);
	else if (params->minus)
		d_i_minus(input, input_len, params);
	else if (params->width)
		d_i_width(input, input_len, params);
	else if (input < 0)
	{
		ft_putnchar('-', 1, params);
		ft_putnbr(input, params);
	}
	else
		(input_len == 0 ? 0 : ft_putnbr(input, params));
	return (1);
}
