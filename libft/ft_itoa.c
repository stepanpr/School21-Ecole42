/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 14:09:11 by emabel            #+#    #+#             */
/*   Updated: 2020/05/23 00:07:44 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
