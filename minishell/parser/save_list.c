/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clauren <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:05:48 by clauren           #+#    #+#             */
/*   Updated: 2020/12/08 20:41:34 by clauren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_redirect	*rdr_new(char *fl, int tp)
{
	t_redirect *result;

	if (!(result = malloc(sizeof(*result))))
		return (NULL);
	result->file = fl;
	result->type = tp;
	result->next = NULL;
	return (result);
}

int			free_cmd(t_command **cmd)
{
	t_command	*head;
	t_command	*tmp;
	int			i;

	head = *cmd;
	while (head)
	{
		i = -1;
		tmp = head;
		while (head->args[++i])
			free(head->args[i]);
		free(head->args);
		head = head->next;
		free(tmp);
	}
	return (1);
}

void		free_rdr(t_redirect **rdr)
{
	t_redirect	*head;
	t_redirect	*tmp;

	head = *rdr;
	while (head)
	{
		tmp = head;
		free(head->file);
		head = head->next;
		free(tmp);
	}
}

t_command	*cmdnew(char **arg, int pipe, t_redirect *redirect)
{
	t_command	*result;
	int			i;

	i = -1;
	if (!(result = malloc(sizeof(*result))))
		return (NULL);
	if (!(result->args = malloc(sizeof(char*) * (array_size(arg) + 1))))
		return (NULL);
	while (arg[++i])
		result->args[i] = arg[i];
	free(arg);
	result->args[i] = NULL;
	result->pipe = pipe;
	result->redirect = redirect;
	result->next = NULL;
	return (result);
}

void		lab(t_redirect **lstr, t_redirect *newr,
					t_command **lstc, t_command *newc)
{
	t_command	*resultc;
	t_redirect	*resultr;

	if (lstr)
	{
		resultr = *lstr;
		if (!*lstr)
			*lstr = newr;
		else
		{
			while (resultr->next)
				resultr = resultr->next;
			resultr->next = newr;
		}
		return ;
	}
	resultc = *lstc;
	if (!*lstc)
		*lstc = newc;
	else
	{
		while (resultc->next)
			resultc = resultc->next;
		resultc->next = newc;
	}
}
