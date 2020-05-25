/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 23:35:01 by emabel            #+#    #+#             */
/*   Updated: 2019/08/06 23:36:48 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

int		ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int		ft_isalnum(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9'));
}

char	*ft_strcapitalize(char *str)
{
	char *ptr;

	ptr = str;
	while (*ptr)
	{
		if ((ptr == str || ft_isalnum(*(ptr - 1)) == 0))
		{
			if (ft_islower(*ptr))
				*ptr -= 'a' - 'A';
		}
		else if (ft_isupper(*ptr))
			*ptr += 'a' - 'A';
		++ptr;
	}
	return (str);
}
