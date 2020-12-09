/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <clauren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 02:36:11 by clauren           #+#    #+#             */
/*   Updated: 2020/05/26 03:20:12 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_itoa(int n)
{
	int		temp;
	int		len;
	int		sign;
	char	*result;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 0;
	if (n < 0 && (n *= -1))
		sign = 1;
	temp = n;
	len = 2 + sign;
	while (temp /= 10)
		len++;
	if (!(result = malloc(sizeof(char) * len)))
		return (NULL);
	result[--len] = '\0';
	while (len--)
	{
		result[len] = n % 10 + '0';
		n /= 10;
	}
	if (sign)
		result[0] = '-';
	return (result);
}
