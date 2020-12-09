/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <clauren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 14:48:02 by clauren           #+#    #+#             */
/*   Updated: 2020/05/27 14:21:46 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *string;
	char *result;

	if (!s)
		return (NULL);
	if (len > ft_strlen((char *)s + start))
	{
		if (start > ft_strlen((char *)s))
			return (ft_strdup(""));
		else
			len = ft_strlen((char *)s + start);
	}
	else if (ft_strlen((char *)s) <= start && (s += ft_strlen((char *)s)))
		len = 0;
	if (!(result = malloc((len + 1) * sizeof(char))))
		return (NULL);
	string = (char *)s;
	while (*string && start--)
		string++;
	ft_strlcpy(result, string, len + 1);
	return (result);
}
