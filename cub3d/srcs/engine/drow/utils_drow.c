/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 16:14:11 by emabel            #+#    #+#             */
/*   Updated: 2020/10/03 08:08:34 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_transparency(t_img_data texture, int index)
{
	if (texture.addr[index] == 0 && texture.addr[index + 1] == 0 &&
		texture.addr[index + 2] == 0 && texture.addr[index + 3] == 0)
		return (0);
	return (1);
}

float	calculate_direction_sprite(t_sprite sprite, t_player player, float pov)
{
	float	sprite_dir;

	sprite_dir = atan2f(sprite.y - player.y, sprite.x - player.x);
	while (sprite_dir - pov > M_PI)
		sprite_dir -= 2 * (float)M_PI;
	while (sprite_dir - pov < -M_PI)
		sprite_dir += 2 * (float)M_PI;
	return (sprite_dir);
}

void	calculate_offset(t_sprite *sprite, t_screen screen, float angle,
																t_player player)
{
	const float	fov = 60.f * (float)M_PI / 180;

	sprite->h_offset = (int)(angle * (float)screen.width / fov +
						(float)screen.width / 2 - (float)sprite->height / 2);
	sprite->v_offset = screen.height / 2 - ((float)sprite->height / 2)
												+ player.look;
}

void	put_pixel(t_img_data img, int index, t_color color)
{
	img.addr[index] = (char)color.b;
	img.addr[index + 1] = (char)color.g;
	img.addr[index + 2] = (char)color.r;
	img.addr[index + 3] = 0;
}

void	put_pixel_img(t_img_data img, t_img_data texture,
		int index, int index_texture)
{
	img.addr[index] = texture.addr[index_texture];
	img.addr[index + 1] = texture.addr[index_texture + 1];
	img.addr[index + 2] = texture.addr[index_texture + 2];
	img.addr[index + 3] = texture.addr[index_texture + 3];
}
