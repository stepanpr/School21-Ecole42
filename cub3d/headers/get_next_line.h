/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 10:03:59 by emabel            #+#    #+#             */
/*   Updated: 2020/10/03 02:49:19 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include "libft.h"

# define BUFFER_SIZE 32

int		get_next_line(int fd, char **line);
char	*ft_strndup(const char *src, int n);
void	add_list(register t_list **lst, char *buffer);
t_list	*ft_lstnew(void *content);

#endif
