/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:23:07 by emabel            #+#    #+#             */
/*   Updated: 2020/10/03 09:20:20 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t byte_sizes)
{
	void	*result;

	if (!(result = malloc(num * byte_sizes)))
		return (NULL);
	ft_bzero(result, num * byte_sizes);
	return (result);
}
