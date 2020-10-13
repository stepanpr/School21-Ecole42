/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_distance_to_wall_v.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:59:52 by emabel            #+#    #+#             */
/*   Updated: 2020/10/03 08:01:39 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float		get_step_x_vertical(float angle)
{
	if (angle < (M_PI / 2) || angle > (3 * M_PI / 2))
		return (CELL);
	else
		return (-CELL);
}

float		get_x_vertical(float position, float angle)
{
	float	x;

	x = (float)((int)(position / CELL) * CELL);
	x += (angle < (M_PI / 2) || angle > (3 * M_PI / 2)) ? CELL : -.01f;
	return (x);
}

float		get_y_vertical(t_player player, float x, float angle)
{
	return (player.y + (player.x - x) * tanf(angle));
}

t_distance	calculate_distance_to_wall_v(t_player player, float ray_angle)
{
	const float		step_x = get_step_x_vertical(ray_angle);
	const float		step_y = -step_x * tanf(ray_angle);
	t_map			map;
	t_coordinates	current;
	t_distance		distance;

	map = player.map;
	current.x = get_x_vertical(player.x, ray_angle);
	current.y = get_y_vertical(player, current.x, ray_angle);
	map.x = (int)(current.x / CELL);
	map.y = (int)(current.y / CELL);
	while (map.y > 0 && map.y < map.column_length)
	{
		if (map.map[map.x + map.y * map.line_length] == '1')
			break ;
		current.x += step_x;
		current.y += step_y;
		map.x = (int)(current.x / CELL);
		map.y = (int)(current.y / CELL);
	}
	distance.x = get_texture_coordinate(current.y);
	distance.distance = get_distance(player.x - current.x,
									player.y - current.y);
	return (distance);
}
