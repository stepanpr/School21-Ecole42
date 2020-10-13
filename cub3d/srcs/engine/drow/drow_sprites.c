/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 12:44:28 by emabel            #+#    #+#             */
/*   Updated: 2020/10/04 01:03:11 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_sprite(t_sprite sprite, t_screen screen, t_img_data img, int i)
{
	const t_img_data	texture = sprite.texture.img_data;
	int					index_texture;
	int					index;
	int					x;

	x = 0;
	while (x < sprite.height)
	{
		if (sprite.v_offset + x > 0 && sprite.v_offset + x <= screen.height)
		{
			index = (sprite.v_offset + x) * img.line_length
					+ (sprite.h_offset + i) * img.bpp / 8;
			index_texture = x * texture.height / sprite.height
								* texture.line_length + i * texture.height
								/ sprite.height * img.bpp / 8;
			if (check_transparency(texture, index_texture))
				put_pixel_img(img, texture, index, index_texture);
		}
		x++;
	}
}

void	drow_sprite(t_sprite item, t_screen screen, const float *distances)
{
	const t_img_data	img = screen.img_world;
	int					y;

	y = 0;
	while (y < item.height)
	{
		if ((item.h_offset + y > 0 && item.h_offset + y <= screen.width) &&
			(distances[item.h_offset + y] > item.dist * 0.9))
			put_sprite(item, screen, img, y);
		y++;
	}
}

void	sorting_sprites(t_sprite *items, int number_items)
{
	t_sprite	temp_item;
	int			q;
	int			i;
	int			flag;

	q = 0;
	while (q < number_items)
	{
		i = 0;
		flag = 0;
		while (i < number_items - q)
		{
			if ((i + 1) < number_items && items[i].dist < items[i + 1].dist)
			{
				temp_item = items[i];
				items[i] = items[i + 1];
				items[i + 1] = temp_item;
				flag = 1;
			}
			i++;
		}
		if (flag == 0)
			return ;
		q++;
	}
}

void	sprites_init(t_game_info *game_info, t_player player, t_screen screen)
{
	const float	pov = -player.pov;
	float		direction_sprite;
	t_sprite	*item;
	int			q;

	q = 0;
	while (q < game_info->number_sprites)
	{
		item = &game_info->sprites[q];
		direction_sprite = calculate_direction_sprite(*item, player, pov);
		item->dist = get_distance(player.x - item->x, player.y - item->y);
		item->height = (int)calculate_height(item->dist, screen);
		item->texture.img_data = game_info->sprite_texture;
		calculate_offset(item, screen, direction_sprite - pov, player);
		q++;
	}
}

void	drow_sprites(t_game_info game_info, t_player player,
											t_screen screen, float *distances)
{
	t_sprite	sprite;
	int			q;

	q = 0;
	sprites_init(&game_info, player, screen);
	sorting_sprites(game_info.sprites, game_info.number_sprites);
	while (q < game_info.number_sprites)
	{
		sprite = game_info.sprites[q];
		drow_sprite(sprite, screen, distances);
		q++;
	}
}
