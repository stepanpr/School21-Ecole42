/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <clauren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 15:53:00 by clauren           #+#    #+#             */
/*   Updated: 2020/05/29 01:46:33 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	memsize;
	char			*ss1;
	char			*ss2;
	char			*result;

	if (!s1 || !s2)
		return (NULL);
	ss1 = (char *)s1;
	ss2 = (char *)s2;
	memsize = ft_strlen(ss1) + ft_strlen(ss2);
	if (!(result = malloc((memsize + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(result, ss1, memsize + 1);
	ft_strlcat(result, ss2, memsize + 1);
	return (result);
}
