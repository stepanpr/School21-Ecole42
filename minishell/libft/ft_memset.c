/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <clauren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 20:46:13 by clauren           #+#    #+#             */
/*   Updated: 2020/05/28 17:46:16 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr;
	unsigned char value;

	ptr = (unsigned char *)b;
	value = (unsigned char)c;
	while (len--)
		*ptr++ = value;
	return (b);
}
