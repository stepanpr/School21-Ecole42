/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subfunc_cnt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 14:20:41 by emabel            #+#    #+#             */
/*   Updated: 2020/07/30 16:54:18 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

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

static size_t	t_len_n(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char		*res;
	size_t		len;
	int			nbr;

	len = t_len_n(n);
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len] = '\0';
	if (n == 0)
		res[0] = 48;
	if (n < 0)
		res[0] = '-';
	while (len - 1 > 0)
	{
		nbr = n % 10;
		if (nbr < 0)
			nbr = -nbr;
		res[len-- - 1] = nbr + 48;
		n = n / 10;
	}
	if (n > 0)
		res[0] = n + 48;
	return (res);
}

int	len_u_digit(size_t digit, char type)
{
	int	count;
	int	point;

	count = 1;
	point = (type == 'x' || type == 'X' || type == 'p') ? 16 : 10;
	while (digit / point)
	{
		digit /= point;
		count++;
	}
	return (count);
}
