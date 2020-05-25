/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 20:48:01 by emabel            #+#    #+#             */
/*   Updated: 2019/08/06 07:20:34 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_atoi_is_leadskip_char(char c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\v' ||
			c == '\f');
}

char	*ft_atoi_leadskip(char *str, int *sign)
{
	while (*str != '\0' && ft_atoi_is_leadskip_char(*str))
		++str;
	*sign = 1;
	if (*str == '+')
		++str;
	else if (*str == '-')
	{
		++str;
		*sign = -1;
	}
	return (str);
}

int		ft_atoi(char *str)
{
	int result;
	int sign;
	int i;

	if (!str)
		return (0);
	result = 0;
	i = 0;
	str = ft_atoi_leadskip(str, &sign);
	while (*str != '\0')
	{
		if (++i >= 20)
			return (-1);
		if (*str >= '0' && *str <= '9')
			result = result * 10 + *str - '0';
		else
			return (sign * result);
		++str;
	}
	return (sign * result);
}
