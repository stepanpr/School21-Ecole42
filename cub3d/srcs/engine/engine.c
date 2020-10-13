/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 20:08:52 by emabel            #+#    #+#             */
/*   Updated: 2020/10/09 05:29:28 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** вычисляем дистанцию до стены;
** вычисляем высоту столбца;
** запускаем функцию отрисовки потолка;
** запускаем функцию отрисовки стен;
** запускаем функцию отрисовки пола;
*/

float			drow(t_cub *cub, float ray_angle, int wall_x)
{
	const t_screen	screen = cub->screen;
	const t_player	player = cub->player;
	t_distance		dist_to_wall;
	float			height;
	float			dist;

	dist_to_wall = calculate_distance_to_wall(cub, ray_angle);
	cub->wall_texture.x = (int)(CELL * dist_to_wall.x);
	height = calculate_height(dist_to_wall.distance, screen);
	dist = dist_to_wall.distance;
	dist_to_wall.distance = ((float)screen.height / 2 - height / 2) +
														player.look;
	drow_floor(cub, (int)dist_to_wall.distance, wall_x);
	drow_wall(cub, (int)dist_to_wall.distance, (int)height, wall_x);
	drow_ceiling(cub, (int)(dist_to_wall.distance + height), wall_x);
	return (dist);
}

/*
** step - шаг с которым движемся;
** ray_angle - начальный угол луча (равен player_direction + (FOV / 2),
** увеличивается с каждой итерацией);
** last_ray_angle - последний угол луча (равен player_direction - (FOV / 2));
** step - шаг с которым движемся;
** distance[screen.width] - массив равный ширине окна (разрешению по ширине);
** wall_x - переменная x увеличивающаяся с каждой итерацией;
** в цикле while отрисовываем стены, заетем вызываем функцию отрисовки спрайтов;
** после чего вызываем стандартную функцию библиотеки MLX -
** mlx_put_image_to_window, которая помещает отрисованную кратинку в окно;
** mlx_do_sync отвечает за ставиблизацию отображения картинки;
*/

void			raycasting(t_cub *cub, t_player player, t_screen screen)
{
	float		ray_angle;
	const float	last_ray_angle = player.pov - (FOV_RAD / 2);
	const float	step = (FOV / (float)screen.width) * PI_DIV_180;
	float		distance[screen.width];
	int			wall_x;

	wall_x = 0;
	ray_angle = player.pov + (FOV_RAD / 2);
	while (ray_angle >= last_ray_angle)
	{
		distance[wall_x] = drow(cub, ray_angle, wall_x);
		ray_angle -= step;
		wall_x++;
	}
	drow_sprites(cub->game_info, player, cub->screen, distance);
	mlx_put_image_to_window(screen.mlx, screen.win, screen.img_world.img, 0, 0);
	mlx_do_sync(screen.mlx);
}

/*
** player_init - инициализация игрока;
** check_valid_map - проверяем карту на валидность
** cub_init - инициализация параметров библиотеки MLX;
** frame_rendering;
** проверяем, если был подан аргумент "--save" (strcmp при равных строках
** возвращает 0), то запускаем функцию save_bmp;
** если вргумента "--save" нету, то инициируем обработку нажатия клавиш
** (mlx_hook) и повторения цикла (mlx_loop);
*/

void			engine(t_game_info game_info, t_screen screen, char *save)
{
	t_cub		cub;
	t_player	player;

	player = player_init(&game_info);
	if (!check_valid_map(player))
		exit_with_error(MAP_ERR);
	cub = cub_init(screen, player, &game_info);
	screen = cub.screen;
	raycasting(&cub, cub.player, screen);
	if (!ft_strcmp(save, "--save"))
		save_bmp(screen.width, screen.height, screen.img_world.addr);
	else
	{
		mlx_hook(screen.win, KeyPress, KeyPressMask, keys, &cub);
		mlx_loop(screen.mlx);
	}
	close_game(cub);
}
