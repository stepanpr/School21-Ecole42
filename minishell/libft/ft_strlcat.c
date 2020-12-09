/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <clauren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 00:55:16 by clauren           #+#    #+#             */
/*   Updated: 2020/05/29 01:56:53 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t size;

	size = 0;
	while (*dst++)
		size++;
	if (dstsize <= size)
	{
		while (*src++)
			dstsize++;
		return (dstsize);
	}
	dstsize -= size + 1;
	dst--;
	while (dstsize-- > 0 && *src)
	{
		size++;
		*dst++ = *src++;
	}
	while (*src++)
		size++;
	*dst = '\0';
	return (size);
}
