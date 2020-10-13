/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 11:10:54 by emabel            #+#    #+#             */
/*   Updated: 2020/10/12 15:13:54 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_player_position(t_player *player, int pos_x, int pos_y,
																char direction)
{
	player->x = (float)pos_x + 32;
	player->y = (float)pos_y + 32;
	player->look = 0;
	if (direction == 'E')
		player->pov = 0;
	else if (direction == 'N')
		player->pov = 90 * PI_DIV_180;
	else if (direction == 'W')
		player->pov = 180 * PI_DIV_180;
	else if (direction == 'S')
		player->pov = 270 * PI_DIV_180;
}

t_sprite	init_sprite_position(int x, int y)
{
	t_sprite	item;

	item.x = (float)x + 32;
	item.y = (float)y + 32;
	return (item);
}

void		check_positions(t_player *player, char c, int length_line,
													t_sprite *items)
{
	static int	current_length_line;
	static int	i;
	static int	x;
	static int	y;

	if (c == '2')
		items[i++] = init_sprite_position(x, y);
	else if (ft_strchr(PLAYER_POS, c))
		init_player_position(player, x, y, c);
	if (++current_length_line == length_line)
	{
		y += 64;
		x = 0;
		current_length_line = 0;
	}
	else
		x += 64;
}

t_player	player_init(t_game_info *game_info)
{
	t_map		map;
	t_player	player;
	t_sprite	*sprites;

	if (!(sprites = (t_sprite*)malloc(sizeof(t_sprite) *
									game_info->number_sprites)))
		exit_with_error(MALLOC_ERR);
	map = game_info->map;
	while (*map.map)
	{
		check_positions(&player, *map.map, map.line_length, sprites);
		map.map++;
	}
	player.map = game_info->map;
	game_info->sprites = sprites;
	return (player);
}

/*
** "mlx_get_screen_size" - получаем максимальное разрешение экрана:
** если полученные значения меньше значений указанных в параметрах карты,
** то разрешение окна будет равно максимальному разрешению экрана;
** "mlx_new_window" - инициируем новое окно;
** "mlx_new_image" - инициируем новый mlx-образ;
** "mlx_get_data_addr" - созраняем адрес памяти изображения;
*/

t_cub		cub_init(t_screen screen, t_player player, t_game_info *game_info)
{
	int			width_screen;
	int			height_screen;
	t_img_data	img_world;
	t_cub		cub;

	mlx_get_screen_size(screen.mlx, &width_screen, &height_screen);
	screen.width = (screen.width > width_screen) ? width_screen : screen.width;
	screen.height = (screen.height > height_screen) ? height_screen
													: screen.height;
	screen.win = mlx_new_window(screen.mlx, screen.width, screen.height,
																"Cub3D_emabel");
	img_world.img = mlx_new_image(screen.mlx, screen.width, screen.height);
	img_world.addr = mlx_get_data_addr(img_world.img, &img_world.bpp,
								&img_world.line_length, &img_world.endian);
	screen.img_world = img_world;
	cub.screen = screen;
	cub.player = player;
	cub.game_info = *game_info;
	return (cub);
}
