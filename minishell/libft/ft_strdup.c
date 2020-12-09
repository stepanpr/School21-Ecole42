/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <clauren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 02:14:33 by clauren           #+#    #+#             */
/*   Updated: 2020/05/29 01:08:44 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	size;
	char			*result;

	size = ft_strlen((char *)s1);
	if (!(result = malloc((size + 1) * sizeof(*s1))))
		return (NULL);
	ft_strlcpy(result, s1, size + 1);
	return (result);
}
