/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:30:52 by emabel            #+#    #+#             */
/*   Updated: 2020/10/03 02:55:11 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strchr(const char *src, char c)
{
	const char *src_copy = src;

	while (*src_copy)
		if (*src_copy++ == c)
			return ((int)(src_copy - src));
	if (c == '\0')
		return ((int)(src_copy - src));
	return (0);
}
