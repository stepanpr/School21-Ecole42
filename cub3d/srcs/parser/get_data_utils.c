/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 07:28:06 by emabel            #+#    #+#             */
/*   Updated: 2020/10/12 11:26:24 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				get_only_flags_and_spaces(int c, char *line)
{
	char		*tmp;

	if ((c > 0 && c < 127) && (c != 78 && c != 87 && c != 83 && c != 69 &&
	c != 82 && c != 70 && c != 67 && c != 0 && c != 127 && c != 9 && c != 32))
		return (1);
	if (c == 0 || c == 127 || c == 9 || c == 32)
	{
		tmp = line;
		while (*tmp != '\0')
		{
			if (*tmp != ' ' && *tmp != '\t' && *tmp != '\n' && *tmp != '\0')
			{
				return (1);
			}
			tmp++;
		}
	}
	return (0);
}

int				get_number_sprites(char *line)
{
	int	result;

	result = 0;
	while (*line)
	{
		if (*line == '2')
			result++;
		line++;
	}
	return (result);
}

int				check_valid_player(char *temp_map)
{
	int			player_exists;
	int			i;

	player_exists = 0;
	i = -1;
	while (temp_map[++i])
	{
		if ((ft_strchr(PLAYER_POS, temp_map[i])))
			player_exists = 1;
	}
	return (player_exists);
}
