/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 23:21:38 by emabel            #+#    #+#             */
/*   Updated: 2019/08/08 23:23:03 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int *rptr;

	if (min >= max)
		return (0);
	*range = malloc((max - min) * sizeof(int));
	if (!*range)
		return (0);
	rptr = *range;
	while (min < max)
		*rptr++ = min++;
	return ((int)(rptr - *range));
}
