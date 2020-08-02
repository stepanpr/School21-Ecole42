/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subfunc_put.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 14:09:41 by emabel            #+#    #+#             */
/*   Updated: 2020/08/01 18:28:35 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_len(char c, int len, t_params *params)
{
	while (len > 0)
	{
		write(1, &c, 1);
		len--;
		params->count++;
	}
}

void	ft_putnbr(int n, t_params *params)
{
	unsigned int	nbr;

	if (n < 0)
	{
		params->count += ft_putchar('-');
		nbr = -1 * n;
	}
	else
		nbr = n;
	if (nbr >= 10)
		ft_putnbr(nbr / 10, params);
	params->count += ft_putchar(nbr % 10 + '0');
}

void	ft_putunbr(unsigned int digit, t_params *params)
{
	if (digit >= 10)
		ft_putunbr(digit / 10, params);
	params->count += ft_putchar(digit % 10 + '0');
}

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
