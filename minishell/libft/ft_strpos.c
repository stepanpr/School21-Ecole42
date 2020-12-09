/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:42:49 by clauren           #+#    #+#             */
/*   Updated: 2020/10/13 16:57:22 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strpos(const char *s, int c)
{
	char	ch;
	char	*string;
	int		i;

	i = 0;
	string = (char *)s;
	ch = (char)c;
	while (string[i] && !(string[i] == ch))
		i++;
	if (string[i] == ch)
		return (i + 1);
	return (0);
}
