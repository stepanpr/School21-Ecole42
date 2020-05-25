/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 02:23:11 by emabel            #+#    #+#             */
/*   Updated: 2020/05/22 23:11:20 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	a;
	int					sign;

	a = 0;
	sign = 1;
	while (*str == '\n' || *str == '\t' || *str == '\r' ||
			*str == ' ' || *str == '\f' || *str == '\v')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		a = (10 * a + (*str - '0'));
		str++;
		if (a > (long long)MAX_LONG_LONG && sign == 1)
			return (-1);
		if (a > (long long)MAX_LONG_LONG && sign == -1)
			return (0);
	}
	return (a * sign);
}
