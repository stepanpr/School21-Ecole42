/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <clauren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 19:27:58 by clauren           #+#    #+#             */
/*   Updated: 2020/05/29 02:11:54 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t n_len;

	n_len = ft_strlen((char *)needle);
	if (!n_len)
		return ((char *)haystack);
	if (ft_strlen((char *)haystack) < n_len || len < n_len)
		return (NULL);
	i = -1;
	while (haystack[++i] && i <= (len - n_len))
		if (haystack[i] == needle[0] &&
			!(ft_strncmp(&haystack[i], needle, n_len)))
			return ((char*)&haystack[i]);
	return (NULL);
}
