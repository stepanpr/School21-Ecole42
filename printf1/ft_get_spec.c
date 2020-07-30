/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 14:25:16 by emabel            #+#    #+#             */
/*   Updated: 2020/07/30 15:29:29 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t  len_of_spec(const char *str)
{
	size_t	len;
	const char *types;

	len = 0;
	types = "cspdiuxX%";
	if (str[len] == '%')
		return (len + 1);
	while (!(ft_strchr(types, str[len])) && str[len])
	{
		if (ft_isalpha(str[len]))
		{
			++len;
			return (0);
		}
		++len;
	}
	if (ft_strchr(types, str[len]))
		++len;
	return (len);
}

char		*ft_get_spec(char *str)
{
	char 	*res;
	size_t len;

	len = len_of_spec(str);
	if (!(res = (char *)malloc(len+1)))
		return (NULL);
	ft_strlcpy(res, str, len + 1);
	return (res);
}
