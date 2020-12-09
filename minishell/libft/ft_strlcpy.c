/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <clauren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 00:23:37 by clauren           #+#    #+#             */
/*   Updated: 2020/05/29 01:03:30 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t size;

	size = 0;
	if (!src)
		return (0);
	while (src[size])
		size++;
	if (!dst)
		return (size);
	if (!dstsize)
		return (size);
	while (*src && --dstsize)
		*dst++ = *src++;
	*dst = '\0';
	return (size);
}
