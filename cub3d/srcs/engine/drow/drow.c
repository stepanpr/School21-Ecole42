/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 15:47:58 by emabel            #+#    #+#             */
/*   Updated: 2020/10/04 00:59:39 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drow_ceiling(t_cub *cub, int height, int wall_x)
{
	const t_img_data	img = cub->screen.img_world;
	const t_color		celling_color = cub->game_info.ceiling_color;
	int					index;

	wall_x *= (img.bpp / 8);
	while (height < cub->screen.height)
	{
		index = (height * img.line_length + wall_x);
		if (index > 0)
			put_pixel(img, index, celling_color);
		height++;
	}
}

void	drow_floor(t_cub *cub, int height, int wall_x)
{
	const t_img_data	img = cub->screen.img_world;
	const t_color		floor_color = cub->game_info.floor_color;
	int					y;
	int					index;

	y = 0;
	wall_x *= (img.bpp / 8);
	while (y < height)
	{
		index = (y * img.line_length + wall_x);
		if (index < cub->screen.height * img.line_length)
			put_pixel(img, index, floor_color);
		y++;
	}
}

void	drow_wall(t_cub *cub, int wall_y, int height, int wall_x)
{
	const t_img_data	img = cub->screen.img_world;
	t_texture			texture;
	float				texture_position;
	int					index;
	int					index_texture;

	texture = cub->wall_texture;
	texture.step = 1.0f * (float)texture.img_data.height / (float)height;
	texture.x *= (texture.img_data.bpp / 8);
	wall_x *= img.bpp / 8;
	texture_position = (((float)wall_y - cub->player.look)
			- (float)cub->screen.height / 2 + (float)height / 2) * texture.step;
	while (height-- > 0)
	{
		texture.y = (int)texture_position & (texture.img_data.height - 1);
		index_texture = texture.y * texture.img_data.line_length + texture.x;
		index = wall_y * img.line_length + wall_x;
		if (index > 0 && index < img.line_length * cub->screen.height)
			put_pixel_img(img, texture.img_data, index, index_texture);
		texture_position += texture.step;
		wall_y++;
	}
}
