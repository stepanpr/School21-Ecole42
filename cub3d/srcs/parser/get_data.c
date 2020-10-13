/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 02:28:04 by emabel            #+#    #+#             */
/*   Updated: 2020/10/12 14:29:20 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int8_t	get_data_tex(char *line, t_img_data *img, void *mlx)
{
	int8_t	fd;

	while (*line == ' ')
		line++;
	fd = open(line, O_RDONLY);
	if (fd == -1)
		return (TEX_ERR);
	close(fd);
	img->img = mlx_xpm_file_to_image(mlx, line, &img->width, &img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
																&img->endian);
	return (1);
}

/*
** парсим параметры карты:
** текатуры, разрешение, цвета
*/

int8_t	get_data_parce(char *line, t_game_info *game_info, t_screen *screen)
{
	int8_t	value;

	value = 0;
	if (get_only_flags_and_spaces(line[0], line))
		return (LESS_ARG_ERR);
	if (line[0] == 'N' && line[1] == 'O')
		value = get_data_tex(line + 2, &(game_info)->textures[0], screen->mlx);
	else if (line[0] == 'W' && line[1] == 'E')
		value = get_data_tex(line + 2, &(game_info)->textures[1], screen->mlx);
	else if (line[0] == 'S' && line[1] == 'O')
		value = get_data_tex(line + 2, &(game_info)->textures[2], screen->mlx);
	else if (line[0] == 'E' && line[1] == 'A')
		value = get_data_tex(line + 2, &(game_info)->textures[3], screen->mlx);
	else if (*line == 'S')
		value = get_data_tex(line + 2, &(game_info)->sprite_texture,
																screen->mlx);
	else if (*line == 'R')
		value = get_data_resolution(line, &screen->width, &screen->height, 0);
	else if (*line == 'C')
		value = get_data_color(line, &game_info->floor_color);
	else if (*line == 'F')
		value = get_data_color(line, &game_info->ceiling_color);
	free(line);
	return (value);
}

/*
** читаем параметры карты
*/

void	get_data(int fd, t_game_info *game_info, t_screen *screen)
{
	char	*line;
	int8_t	count_arg;
	int8_t	value;

	count_arg = 0;
	while (get_next_line(fd, &line) > 0 && count_arg < COUNT_ARG)
	{
		value = get_data_parce(line, game_info, screen);
		value == RES_ERR ? exit_with_error(RES_ERR) : 0;
		value == RES_VAL_ERR ? exit_with_error(RES_VAL_ERR) : 0;
		value == RES_LEN_ERR ? exit_with_error(RES_LEN_ERR) : 0;
		value == RES_TWO_VAL ? exit_with_error(RES_TWO_VAL) : 0;
		value == TEX_ERR ? exit_with_error(TEX_ERR) : 0;
		value == COLOR_ERR ? exit_with_error(COLOR_ERR) : 0;
		value == COLOR_VAL_ERR ? exit_with_error(COLOR_VAL_ERR) : 0;
		value == LESS_ARG_ERR ? exit_with_error(LESS_ARG_ERR) : 0;
		value == MALLOC_ERR ? exit_with_error(MALLOC_ERR) : 0;
		count_arg += value;
	}
	free(line);
	if (count_arg < COUNT_ARG)
		exit_with_error(LESS_ARG_ERR);
}
