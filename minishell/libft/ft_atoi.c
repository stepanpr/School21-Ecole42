/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <clauren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 00:08:57 by clauren           #+#    #+#             */
/*   Updated: 2020/05/29 01:19:41 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_atoi(const char *str)
{
	long	result;
	long	prev;
	int		sign;

	result = 0;
	while (*str == ' ' || *str == '\r' || *str == '\v' || *str == '\f' ||
			*str == '\t' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (*(str - 1) == '-')
		sign = -1;
	else
		sign = 1;
	while (ft_isdigit(*str))
	{
		prev = result;
		result = result * 10 + (*str++ - '0');
		if (result / 10 != prev && sign == -1)
			return (0);
		if (result / 10 != prev && sign == 1)
			return (-1);
	}
	return (result * sign);
}
