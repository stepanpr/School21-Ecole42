/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 06:05:57 by emabel            #+#    #+#             */
/*   Updated: 2019/08/14 06:11:39 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *root;
	t_list *node;
	t_list *next;

	root = *begin_list;
	node = *begin_list;
	while (root)
	{
		next = (*root).next;
		if ((cmp)(root->data, data_ref) == 0)
		{
			if (root == *begin_list)
			{
				*begin_list = next;
			}
			node->next = next;
			free(root);
		}
		node = root;
		root = next;
	}
}
