/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 10:19:28 by emabel            #+#    #+#             */
/*   Updated: 2020/10/03 02:49:45 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	write_line(t_list *list, char **line, int result)
{
	int		i;

	if (list)
	{
		if ((i = ft_strchr(list->content, '\n')))
			i -= 1;
		else
			i = ft_strchr(list->content, '\0');
		*line = ft_strndup(list->content, i);
	}
	else if (!result && BUFFER_SIZE != 0)
		*line = ft_strndup("", 0);
}

int		ft_result(t_list **element, int result)
{
	t_list	*temp;

	temp = NULL;
	if (*element)
	{
		temp = (*element);
		(*element) = (*element)->next;
		free(temp->content);
		free(temp);
	}
	if (result == -1)
		return (-1);
	else if (result == 0 && temp == NULL)
		return (0);
	return (1);
}

int		parse_buffer(t_list **list, char *buffer)
{
	int		i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i++] == '\n' || buffer[i] == 0)
		{
			add_list(list, ft_strndup(buffer, i));
			buffer += i;
			i = 0;
		}
	}
	buffer -= 1;
	if (*buffer == '\n')
		add_list(list, ft_strndup("", 0));
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int				result;
	char			*buffer;
	static t_list	*lists[14000];

	if (line == NULL || fd < 0 || fd > 14000 ||
			!(buffer = ft_calloc(1, BUFFER_SIZE + 1)))
		return (-1);
	while ((result = (read(fd, buffer, BUFFER_SIZE))) > 0)
	{
		if (ft_strchr(buffer, '\n'))
		{
			parse_buffer(&lists[fd], buffer);
			free(buffer);
			break ;
		}
		add_list(&lists[fd], buffer);
		buffer = ft_calloc(1, BUFFER_SIZE + 1);
	}
	if (result <= 0)
		free(buffer);
	write_line(lists[fd], line, result);
	return (ft_result(&lists[fd], result));
}
