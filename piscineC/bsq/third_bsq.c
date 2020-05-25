/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 09:35:52 by emabel            #+#    #+#             */
/*   Updated: 2019/08/22 09:48:35 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		index_of_free(char *s, char c, int n)
{
	int i;

	i = 0;
	while (i < n && s[i] != '\n' && s[i] != c)
		i++;
	return (i);
}

int		is_valid_map(t_map map)
{
	int		x;
	int		y;
	char	*pos;

	y = 0;
	while (y < map.h)
	{
		pos = map.data + y * (map.w + 1);
		x = 0;
		while (x < map.w)
		{
			if (pos[x] != map.c_empty &&
					pos[x] != map.c_obstacle)
				return (0);
			x++;
		}
		if (pos[x] != '\n')
			return (0);
		y++;
	}
	return (1);
}

void	mark_box(t_map map, t_square box)
{
	int x;
	int y;

	y = 0;
	while (y < box.w)
	{
		x = 0;
		while (x < box.w)
		{
			map.data[(y + box.y) * (map.w + 1) + box.x + x] = map.c_full;
			x++;
		}
		y++;
	}
}

void	output_map(t_map map)
{
	write(1, map.data, (map.w + 1) * map.h);
}
