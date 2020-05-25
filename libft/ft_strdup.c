/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 05:21:22 by emabel            #+#    #+#             */
/*   Updated: 2020/05/19 19:38:03 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strdup(const char *s)
{
	char			*ss;
	unsigned int	s_len;
	unsigned int	i;

	ss = NULL;
	s_len = 0;
	i = 0;
	while (s[s_len])
		s_len++;
	if (!(ss = (char *)malloc(sizeof(char) * (s_len + 1))))
		return (NULL);
	while (i < s_len)
	{
		ss[i] = s[i];
		i++;
	}
	ss[i] = '\0';
	return (ss);
}
