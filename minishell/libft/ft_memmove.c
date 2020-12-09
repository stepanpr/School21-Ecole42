/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <clauren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 21:46:56 by clauren           #+#    #+#             */
/*   Updated: 2020/05/25 15:17:43 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dst1;
	unsigned char *src1;

	if (len == 0 || dst == src)
		return (dst);
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	if (dst1 < src1)
		ft_memcpy(dst, src, len);
	else
	{
		dst1 += len - 1;
		src1 += len - 1;
		while (len--)
			*dst1-- = *src1--;
	}
	return (dst);
}
