/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 10:33:07 by emabel            #+#    #+#             */
/*   Updated: 2020/05/22 23:46:26 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*a;
	unsigned int	j;

	a = NULL;
	if (!f || !s)
		return (NULL);
	if (f && s)
	{
		j = (unsigned int)ft_strlen(s);
		if (!(a = malloc(sizeof(char) * (j + 1))))
			return (NULL);
		a[j] = '\0';
		j = 0;
		while (s[j] != '\0')
		{
			a[j] = (*f)(j, s[j]);
			j++;
		}
	}
	return (a);
}
