/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 20:33:09 by emabel            #+#    #+#             */
/*   Updated: 2019/08/16 20:34:02 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree		*btree_create_node(void *item)
{
	t_btree *tree;

	tree = (t_btree *)malloc(sizeof(t_btree));
	if (tree)
	{
		tree->item = item;
		tree->left = 0;
		tree->right = 0;
	}
	return (tree);
}
