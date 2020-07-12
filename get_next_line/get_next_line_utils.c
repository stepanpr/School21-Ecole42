/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 23:12:13 by emabel            #+#    #+#             */
/*   Updated: 2020/07/12 00:59:52 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t		ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static void			*ft_calloc(size_t nmemb, size_t size)
{
	void			*res;
	char			*str;
	unsigned int	i;

	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	i = 0;
	str = (char *)res;
	while (i < (nmemb * size))
		str[i++] = '\0';
	return (res);
}

char				*ft_strchr(const char *s, int c)
{
	int				i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char				*ft_strdup(const char *s)
{
	char			*ss;
	unsigned int	len;
	unsigned int	i;

	len = ft_strlen(s) + 1;
	ss = (char *)ft_calloc(len, sizeof(char));
	if (ss == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ss[i] = s[i];
		i++;
	}
	return (ss);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*new;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if ((!s1) && (!s2))
		return (NULL);
	if ((!s1) && (s2))
		return (ft_strdup(s2));
	if (!(new = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char))))
		return (NULL);
	while (s1[j])
	{
		new[i++] = s1[j++];
	}
	j = 0;
	while (s2[j])
	{
		new[i++] = s2[j++];
	}
	return (new);
}
