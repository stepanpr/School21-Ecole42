/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 22:22:23 by emabel            #+#    #+#             */
/*   Updated: 2019/08/13 23:18:54 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *tab_ret;

	i = 0;
	tab_ret = (int*)malloc(sizeof(*tab) * length);
	while (i < length)
	{
		tab_ret[i] = f(tab[i]);
		i++;
	}
	return (tab_ret);
}
