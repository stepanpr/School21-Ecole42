/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:04:22 by emabel            #+#    #+#             */
/*   Updated: 2020/10/03 02:56:40 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dest, size_t byte_sizes)
{
	char	*temp_dest;

	temp_dest = (char*)dest;
	while (byte_sizes--)
		*(temp_dest++) = 0;
}
