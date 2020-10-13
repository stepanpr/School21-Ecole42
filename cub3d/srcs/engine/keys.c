/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 00:10:11 by emabel            #+#    #+#             */
/*   Updated: 2020/10/04 02:07:33 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int8_t	check_wall(t_player *player, float step_x, float step_y)
{
	const int	coord_x = (int)((player->x + step_x * PLAYER_SPEED * 2) / 64);
	const int	coord_y = (int)((player->y + step_y * PLAYER_SPEED * 2) / 64);
	const t_map	map = player->map;

	return (map.map[coord_x + coord_y * map.line_length] != '1' &&
			map.map[coord_x + coord_y * map.line_length] != '2');
}

void	change_position(int key, t_player *player)
{
	const float	coss = cosf(player->pov);
	const float	sinn = -sinf(player->pov);

	if ((key == W || key == W_MAC) && check_wall(player, coss, sinn))
	{
		player->x += coss * PLAYER_SPEED;
		player->y += sinn * PLAYER_SPEED;
	}
	else if ((key == S || key == S_MAC) && check_wall(player, -coss, -sinn))
	{
		player->x -= coss * PLAYER_SPEED;
		player->y -= sinn * PLAYER_SPEED;
	}
	else if ((key == D || key == D_MAC) && check_wall(player, -sinn, coss))
	{
		player->x -= sinn * PLAYER_SPEED;
		player->y += coss * PLAYER_SPEED;
	}
	else if ((key == A || key == A_MAC) && check_wall(player, sinn, -coss))
	{
		player->x += sinn * PLAYER_SPEED;
		player->y -= coss * PLAYER_SPEED;
	}
}

void	change_pov(int key, t_player *player)
{
	if (key == LEFT_ARROW || key == LEFT_ARROW_MAC)
		player->pov += PI_DIV_180 * 5;
	else if (key == RIGHT_ARROW || key == RIGHT_ARROW_MAC)
		player->pov -= PI_DIV_180 * 5;
	else if ((key == UP_ARROW || key == UP_ARROW_MAC) && player->look < 400)
		player->look += 20;
	else if ((key == DOWN_ARROW || key == DOWN_ARROW_MAC) &&
											player->look > -400)
		player->look -= 20;
	player->pov = fix_angle(player->pov);
}

int		keys(int key, t_cub *cub)
{
	const float		x = cub->player.x;
	const float		y = cub->player.y;
	const float		look = cub->player.look;
	const float		pov = cub->player.pov;

	if (key == LEFT_ARROW || key == RIGHT_ARROW || key == DOWN_ARROW
		|| key == UP_ARROW || key == LEFT_ARROW_MAC || key ==
			RIGHT_ARROW_MAC || key == UP_ARROW_MAC || key == DOWN_ARROW_MAC)
		change_pov(key, &cub->player);
	else if (key == A || key == D || key == S || key == W || key == A_MAC
		|| key == D_MAC || key == S_MAC || key == W_MAC)
		change_position(key, &cub->player);
	else if (key == ESC || key == ESC_MAC)
		close_game(*cub);
	if (compare_pov(cub->player, pov, look) ||
		compare_position(cub->player, x, y))
		raycasting(cub, cub->player, cub->screen);
	return (0);
}
