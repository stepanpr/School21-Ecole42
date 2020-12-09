/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 16:09:47 by clauren           #+#    #+#             */
/*   Updated: 2020/11/20 00:39:04 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	find_in_set(const char c, const char *set)
{
	int		i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		i;
	int		k;
	int		len;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	i = -1;
	k = -1;
	len = ft_strlen((char *)s1);
	while (find_in_set(s1[++i], set))
		;
	if (i == len)
		return (ft_strdup(""));
	while (find_in_set(s1[len - 1 - ++k], set))
		;
	if (!(result = ft_substr(s1, i, len - k - i)))
		return (NULL);
	return (result);
}
