/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:54:26 by clauren           #+#    #+#             */
/*   Updated: 2020/12/08 20:25:40 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			error_p(char *bin, char *subject, char *text, char *text1)
{
	ft_putstr_fd("minishell: ", 1);
	if (bin && *bin)
		ft_putstr_fd(bin, 1);
	if (subject && *subject)
		ft_putstr_fd(subject, 1);
	if (text && *text)
		ft_putstr_fd(text, 1);
	if (text1 && *text1)
		ft_putstr_fd(text1, 1);
	ft_putchar_fd('\n', 1);
	return (1);
}

char		**only_key_check(char *str)
{
	if (!ft_isalpha(*str) && (*str != '_'))
		return (NULL);
	while (*++str)
		if (!ft_isalnum(*str) && (*str != '_'))
			return (NULL);
	return ((char **)1);
}

void		listener(int code)
{
	if (code == SIGQUIT)
		ft_putstr_fd("Quit: 3\n", 1);
	if (code == SIGINT)
		ft_putstr_fd("\b\b\n", 1);
}

void		sighandler(int code)
{
	if (code == SIGINT)
		ft_putstr_fd("\b\b  \b\b\n\e[1;32mminishell$\e[0m ", 1);
	if (code == SIGQUIT)
		ft_putstr_fd("\b\b  \b\b", 1);
}

int			array_size(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
