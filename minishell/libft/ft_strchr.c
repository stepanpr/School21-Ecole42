/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <clauren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 01:27:53 by clauren           #+#    #+#             */
/*   Updated: 2020/05/27 19:08:25 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char ch;
	char *string;

	string = (char *)s;
	ch = (char)c;
	while (*string && !(*string == ch))
		string++;
	if (*string == ch)
		return (string);
	return (NULL);
}
