/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <clauren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 17:39:57 by clauren           #+#    #+#             */
/*   Updated: 2020/05/29 01:11:24 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static		int	count_words(char const *s, char c)
{
	int				i;
	int				count;

	i = -1;
	count = 0;
	while (s[++i])
		if ((i == 0 && s[i] != c) || (s[i] == c && s[i + 1] != c && s[i + 1]))
			count++;
	return (count);
}

static	int		word_len(char const *s, char c, int *pos)
{
	unsigned long	w_len;

	w_len = 0;
	while (s[++(*pos)] == c)
		;
	while (s[*pos] && s[*pos] != c)
	{
		w_len++;
		(*pos)++;
	}
	return (w_len);
}

void			memfree(char **arr)
{
	while (*arr)
		free(*arr++);
	free(arr);
}

char			**ft_split(char const *s, char c)
{
	char			**arr;
	int				count;
	int				i;
	unsigned long	w_len;
	int				pos;

	pos = -1;
	if (!s)
		return (0);
	count = count_words(s, c);
	if (!(arr = malloc(sizeof(*arr) * (count + 1))))
		return (NULL);
	i = 0;
	while (i < count)
	{
		w_len = word_len(s, c, &pos);
		if (!(arr[i] = malloc((w_len + 1) * sizeof(char))))
		{
			memfree(arr);
			return ((char **)NULL);
		}
		ft_strlcpy(arr[i++], &s[pos - w_len], w_len + 1);
	}
	arr[i] = 0;
	return (arr);
}
