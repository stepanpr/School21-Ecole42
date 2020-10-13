/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_distance_to_wall.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 15:54:11 by imicah            #+#    #+#             */
/*   Updated: 2020/10/03 08:01:36 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_distance	dist_to_wall_init(t_distance dist_to_wall, float pov, float angle)
{
	t_distance	distance;

	distance.x = modff(dist_to_wall.x / CELL, &dist_to_wall.x);
	distance.distance = dist_to_wall.distance * cosf(pov - angle);
	return (distance);
}

t_distance	calculate_distance_to_wall(t_cub *cub, float ray_angle)
{
	const t_player	player = cub->player;
	t_distance		distance_to_wall_h;
	t_distance		distance_to_wall_v;

	ray_angle = fix_angle(ray_angle);
	distance_to_wall_h = calculate_distance_to_wall_h(player, ray_angle);
	distance_to_wall_v = calculate_distance_to_wall_v(player, ray_angle);
	get_wall_texture(cub, ray_angle, distance_to_wall_h.distance,
										distance_to_wall_v.distance);
	if (distance_to_wall_h.distance > distance_to_wall_v.distance)
		return (dist_to_wall_init(distance_to_wall_v, player.pov, ray_angle));
	else
		return (dist_to_wall_init(distance_to_wall_h, player.pov, ray_angle));
}
