/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:05:48 by clauren           #+#    #+#             */
/*   Updated: 2020/12/06 05:39:14 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_addtostr(char *s1, char s2)
{
	unsigned int	memsize;
	char			*result;

	if (!s1)
		return (NULL);
	memsize = ft_strlen(s1) + 1;
	if (!(result = malloc((memsize + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(result, s1, memsize + 1);
	result[memsize - 1] = s2;
	result[memsize] = '\0';
	free(s1);
	return (result);
}

int		word_len(char *str)
{
	int i;

	i = 0;
	while (str[i] && find_inset(str[i], "_?", ft_isalnum))
		i++;
	return (i);
}

int		skip_spaces(char **line)
{
	while (**line == ' ' || **line == '\t')
	{
		(*line)++;
	}
	return (1);
}

int		find_inset(char c, char *set, int (*is)(int c))
{
	if (is && (*is)(c))
		return (1);
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}
