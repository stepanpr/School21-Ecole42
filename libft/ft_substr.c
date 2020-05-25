/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 07:10:53 by emabel            #+#    #+#             */
/*   Updated: 2020/05/19 21:32:59 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	s_len;
	unsigned int	i;

	s_len = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[s_len] != '\0')
		s_len++;
	if (s_len < start)
	{
		if (!(res = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		res[i++] = s[start++];
	}
	res[i] = '\0';
	return (res);
}
