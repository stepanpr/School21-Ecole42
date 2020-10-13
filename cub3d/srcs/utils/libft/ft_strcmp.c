/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:25:34 by emabel            #+#    #+#             */
/*   Updated: 2020/10/03 02:54:47 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *arr1, const char *arr2)
{
	if (arr1 == arr2)
		return (0);
	else if (arr1 == NULL)
		return (1);
	while (*arr1 == *arr2 && *arr2 && *arr1)
	{
		arr1++;
		arr2++;
	}
	return (*arr1 - *arr2);
}
