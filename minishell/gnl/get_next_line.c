/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 15:54:24 by clauren           #+#    #+#             */
/*   Updated: 2020/12/08 19:17:56 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		append_buf(char **line, const char *buf)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (!(tmp = malloc(ft_strlen(*line) + 2)))
		return ;
	while ((*line)[i])
	{
		tmp[i] = (*line)[i];
		i++;
	}
	tmp[i] = buf[0];
	tmp[i + 1] = '\0';
	free(*line);
	*line = tmp;
}

static	int	check_if_end(t_sh *sh, const char buf[2], char **line)
{
	if (buf[0] == '\0')
	{
		if (!sh->from_pipe)
			write(1, "  \b\b", 4);
		if (!ft_strlen(*line))
			return (0);
	}
	return (1);
}

int			get_next_line(t_sh *sh, int fd, char **line)
{
	char	buf[2];
	int		bytes;

	buf[1] = '\0';
	if (!(*line = malloc(sizeof(char *))))
		return (-1);
	(*line)[0] = '\0';
	buf[0] = '\0';
	while ((bytes = read(fd, buf, 1)) >= 0)
	{
		if (!check_if_end(sh, buf, line))
			return (0);
		if (buf[0] == '\n')
			return (1);
		append_buf(line, buf);
		buf[0] = '\0';
	}
	if (bytes < 0)
	{
		if (*line)
			free(*line);
		return (-1);
	}
	return (0);
}
