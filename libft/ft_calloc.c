/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 07:13:32 by emabel            #+#    #+#             */
/*   Updated: 2020/05/23 00:01:39 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*mem;
	unsigned int	i;

	if (!(mem = (unsigned char *)malloc(nmemb * size)))
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		mem[i] = 0;
		i++;
	}
	return ((void *)mem);
}
