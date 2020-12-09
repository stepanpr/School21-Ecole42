/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <clauren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 22:03:48 by clauren           #+#    #+#             */
/*   Updated: 2020/05/25 15:20:26 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*string;

	string = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n--)
	{
		if (*string == ch)
			return (string);
		string++;
	}
	return (NULL);
}
