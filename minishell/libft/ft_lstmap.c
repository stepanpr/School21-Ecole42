/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <clauren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 19:35:48 by clauren           #+#    #+#             */
/*   Updated: 2020/05/28 20:01:09 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*start;

	if (!lst || !f)
		return (NULL);
	if (!(result = ft_lstnew((*f)(lst->content))))
		return (NULL);
	lst = lst->next;
	start = result;
	while (lst)
	{
		if (!(result->next = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&start, (*del));
			return (NULL);
		}
		result = result->next;
		lst = lst->next;
	}
	return (start);
}
