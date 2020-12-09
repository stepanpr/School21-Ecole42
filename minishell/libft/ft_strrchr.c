/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <clauren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:15:01 by clauren           #+#    #+#             */
/*   Updated: 2020/05/29 00:49:59 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char ch;
	char *string;

	string = (char *)s;
	ch = (char)c;
	string += ft_strlen((char *)s);
	while (!(*string == ch) && string >= s)
		string--;
	if (*string == ch)
		return (string);
	return (NULL);
}
