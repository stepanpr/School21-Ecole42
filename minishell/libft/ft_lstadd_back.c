/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <clauren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 19:19:55 by clauren           #+#    #+#             */
/*   Updated: 2020/05/29 01:21:53 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*result;

	if (!lst)
		return ;
	result = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (result->next)
			result = result->next;
		result->next = new;
	}
}
