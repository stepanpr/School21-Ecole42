/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 05:57:41 by emabel            #+#    #+#             */
/*   Updated: 2019/08/09 06:10:06 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		ft_isws(char c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\v'
			|| c == '\f');
}

static int		ft_wc(char *str)
{
	int		i;

	i = 0;
	while (*str)
		if (ft_isws(*str))
			++str;
		else
		{
			++i;
			++str;
			while (*str && !ft_isws(*str))
				++str;
		}
	return (i);
}

static char		*ft_split_w(char **str)
{
	char	*bptr;
	char	*bsptr;
	char	*sptr;

	sptr = *str;
	while (ft_isws(*sptr))
		++sptr;
	*str = sptr;
	while (!ft_isws(*sptr))
		++sptr;
	bptr = malloc((sptr - *str) * sizeof(char));
	if (!bptr)
		return (NULL);
	bsptr = bptr;
	while (sptr > *str)
		*bsptr++ = *((*str)++);
	*bsptr = '\0';
	while (**str && ft_isws(**str))
		++*str;
	return (bptr);
}

char			**ft_split_whitespaces(char *str)
{
	char	**buffer;
	char	**bptr;
	int		i;

	i = ft_wc(str);
	if (!(buffer = malloc((i + 1) * sizeof(char *))))
		return (NULL);
	bptr = buffer;
	while (i--)
		if (!(*bptr++ = ft_split_w(&str)))
			return (NULL);
	*bptr = (NULL);
	return (buffer);
}
