/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:45:27 by clauren           #+#    #+#             */
/*   Updated: 2020/12/08 20:44:26 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtolower(char *str)
{
	int		i;
	char	*res;

	i = -1;
	if (!(res = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[++i])
		res[i] = (char)ft_tolower(str[i]);
	res[i] = '\0';
	return (res);
}
