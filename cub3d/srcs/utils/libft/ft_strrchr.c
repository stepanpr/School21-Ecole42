/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 15:52:21 by emabel            #+#    #+#             */
/*   Updated: 2020/10/03 02:52:35 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, char ch)
{
	char	*temp_str;

	temp_str = (void*)0;
	while (*str)
	{
		if (*str == ch)
			temp_str = (char*)str;
		str++;
	}
	if (ch == '\0')
		temp_str = (char*)str;
	return (temp_str);
}
