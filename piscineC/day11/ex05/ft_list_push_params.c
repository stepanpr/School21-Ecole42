/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 05:14:29 by emabel            #+#    #+#             */
/*   Updated: 2019/08/14 05:18:14 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_push_params(int ac, char **av)
{
	int			count;
	t_list		*new;
	t_list		*cpy;

	count = 0;
	cpy = new;
	if (ac > 1)
	{
		new = ft_create_elem(av[count]);
		count++;
		cpy = new;
		while (count < ac)
		{
			cpy = cpy->next;
			cpy = ft_create_elem(av[count]);
			count++;
		}
	}
	return (new);
}
