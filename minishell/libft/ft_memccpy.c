/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <clauren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 15:00:18 by clauren           #+#    #+#             */
/*   Updated: 2020/05/25 15:00:22 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	unsigned char	ch;

	ch = (unsigned char)c;
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	while (n--)
	{
		*dst1++ = *src1++;
		if (*(dst1 - 1) == ch)
			return (dst1);
	}
	return (NULL);
}
