/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 09:32:29 by emabel            #+#    #+#             */
/*   Updated: 2019/08/22 09:48:23 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			find_square(t_map map, int x, int y, t_square *bsq)
{
	int i;
	int f;
	int w;

	i = 0;
	w = bsq->w + 1;
	while (i < w)
	{
		f = index_of_free(map.data + x + (y + i) * (map.w + 1),
				map.c_obstacle, w);
		if (f < w)
			return (f + 1);
		i++;
	}
	bsq->x = x;
	bsq->y = y;
	bsq->w = w;
	return (0);
}

t_square	parse_bsq(t_map map)
{
	int			y;
	int			x;
	t_square	bs;

	bs.w = 0;
	bs.x = 0;
	bs.y = 0;
	y = 0;
	while (y < map.h - bs.w)
	{
		x = 0;
		while (x < map.w - bs.w && y < map.h - bs.w)
			x += find_square(map, x, y, &bs);
		y++;
	}
	return (bs);
}

t_map		parse_legend(char *data, int size)
{
	t_map	desc;
	int		i;

	desc.w = 0;
	i = 0;
	desc.h = atoi(data);
	while (data[i] >= '0' && data[i] <= '9')
		i++;
	desc.c_empty = data[i++];
	desc.c_obstacle = data[i++];
	desc.c_full = data[i++];
	if (data[i++] != '\n')
		return (desc);
	desc.data = data + i;
	desc.w = (size - i) / (desc.h) - 1;
	return (desc);
}

char		*my_realloc(char *data, int size, int new_size)
{
	char	*new_data;
	int		i;

	new_data = malloc(new_size);
	i = 0;
	while (i < size && i < new_size)
	{
		new_data[i] = data[i];
		i++;
	}
	return (new_data);
}
