/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_engine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 00:10:32 by emabel            #+#    #+#             */
/*   Updated: 2020/10/03 08:24:53 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int8_t	compare_pov(t_player player, float pov, float look)
{
	return (player.pov != pov || player.look != look);
}

int8_t	compare_position(t_player player, float x, float y)
{
	return (player.x != x || player.y != y);
}

float	fix_angle(float angle)
{
	if (angle <= 0)
		return (angle + (float)(2 * M_PI));
	else if (angle >= (2 * M_PI))
		return (angle - (float)(2 * M_PI));
	else
		return (angle);
}

/*
** высота столбца = высота текстуры / расстояние до столбца *
** расстояние до protection_plane ((scr_width /2) / tang(FOV/2))
*/

float	calculate_height(float distance_to_wall, t_screen screen)
{
	float			height;

	height = CELL / distance_to_wall * ((float)screen.width / 2
										/ tanf(FOV_RAD / 2));
	return (height);
}

void	get_wall_texture(t_cub *cub, float ray_angle, float distance_to_wall_h,
													float distance_to_wall_v)
{
	if (distance_to_wall_h < distance_to_wall_v)
	{
		if (ray_angle < M_PI)
			cub->wall_texture.img_data = cub->game_info.textures[0];
		else
			cub->wall_texture.img_data = cub->game_info.textures[2];
	}
	else
	{
		if (ray_angle > M_PI / 2 && ray_angle < M_PI * 3 / 2)
			cub->wall_texture.img_data = cub->game_info.textures[1];
		else
			cub->wall_texture.img_data = cub->game_info.textures[3];
	}
}
