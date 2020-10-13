/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:57:37 by imicah            #+#    #+#             */
/*   Updated: 2020/10/03 02:55:22 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(char *src, int size)
{
	char	*temp;

	temp = src;
	if (src != NULL)
	{
		size += ft_strlen(src);
		src = (char*)malloc(sizeof(char) * size);
		ft_strcpy(src, temp);
		free(temp);
	}
	else
		src = (char*)malloc(sizeof(char) * size);
	return (src);
}
