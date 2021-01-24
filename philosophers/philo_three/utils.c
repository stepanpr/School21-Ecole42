/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 08:37:14 by emabel            #+#    #+#             */
/*   Updated: 2021/01/21 17:02:38 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"
#define MAX_LONG_LONG	9223372036854775807

size_t		ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int			ft_atoi(const char *str)
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

char		*ft_strdup(const char *str)
{
	int		size;
	char	*new;

	size = ft_strlen((char *)str);
	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	new[size] = '\0';
	while (--size >= 0)
		new[size] = str[size];
	return (new);
}

static int	ft_get_size(unsigned long nb)
{
	unsigned long count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(unsigned long n)
{
	unsigned int	size;
	unsigned int	i;
	char			*tab;

	size = ft_get_size(n);
	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (!(tab = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (++i <= size)
	{
		tab[size - i] = (n % 10) + '0';
		n = n / 10;
	}
	tab[size] = '\0';
	return ((char *)tab);
}
