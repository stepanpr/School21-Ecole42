/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <clauren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 21:18:16 by clauren           #+#    #+#             */
/*   Updated: 2020/05/26 18:04:58 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dst1;
	unsigned char *src1;

	if (n == 0 || dst == src)
		return (dst);
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	while (n--)
		*dst1++ = *src1++;
	return (dst);
}
