/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:46:16 by sfrederi          #+#    #+#             */
/*   Updated: 2020/05/22 23:51:35 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*ln;

	if (!del || !lst)
		return ;
	if (lst)
	{
		list = *lst;
		while (list)
		{
			ln = list->next;
			del(list->content);
			free(list);
			list = ln;
		}
		*lst = NULL;
	}
}
