/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 12:20:37 by emabel            #+#    #+#             */
/*   Updated: 2020/10/12 15:12:56 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		copy_read_map(char *map, char *line, int i)
{
	static char	flag;

	while (*line)
	{
		if ((ft_strchr(PLAYER_POS, *line) && flag) ||
			!ft_strchr(MAP_CHAR, *line))
		{
			free(map);
			return (0);
		}
		else
		{
			if (ft_strchr(PLAYER_POS, *line))
				flag = 1;
			map[i++] = *line++;
		}
	}
	map[i++] = '\n';
	map[i] = 0;
	return (i);
}

char	*read_map(char *line, char *temp_map, t_map *map)
{
	static int	i;
	int			current_length;

	if (*line)
	{
		current_length = ft_strlen(line);
		if (current_length > map->line_length)
			map->line_length = current_length;
		temp_map = ft_realloc(temp_map, (int)current_length + 2);
		if ((i = copy_read_map(temp_map, line, i)) == 0)
			return (NULL);
	}
	return (temp_map);
}

char	*copy_write_map(char *map, char *temp_map, int length_line)
{
	const int	k = ft_strlen(temp_map);
	int			current_length_line;
	int			i;
	int			q;

	i = 0;
	q = 0;
	current_length_line = 0;
	while (i < k)
	{
		if (temp_map[i] == '\n')
		{
			while (current_length_line++ < length_line)
				map[q++] = ' ';
			i++;
			current_length_line = 0;
		}
		map[q++] = temp_map[i++];
		current_length_line++;
	}
	--q;
	map[q] = 0;
	return (map);
}

int		get_map_cicle(char fd, t_game_info *game_info, t_map *map)
{
	while ((game_info->read_res = get_next_line(fd, &game_info->line)) > 0)
	{
		game_info->number_sprites += get_number_sprites(game_info->line);
		if (!(ft_strchr(game_info->line, '0')) &&
										(ft_strchr(game_info->line, '1')))
			game_info->no_so += 1;
		if (game_info->line[0] == '\0' && game_info->no_so == 1)
			return (0);
		if (game_info->read_res > 0 && (*game_info->line == '1' ||
												*game_info->line == ' '))
		{
			game_info->temp_map = read_map(game_info->line,
											game_info->temp_map, map);
			if (game_info->temp_map == NULL)
				return (0);
			map->column_length++;
		}
		free(game_info->line);
	}
	return (1);
}

/*
** читаем карту в "get_map_cicle", записываем количество спрайтов,
** выделяем память (под длину строки * на кол-во строк) и записываем
** карту в переменную структуры map;
** если в строке обнаруживаем символ "1" и не обнаруживаем символ "0"
** (верхняя и нижняя стена), то увелчиваем значение переменной no_so,
** таким образом, если мы в данный момент читаем само тело карты, то есть
** уже прошли через северную стену, то значение no_so будет равно 1,
** поэтому в следующем условии if обозначаем что если no_so равно 1 и line[0]
** равно 0 (концу строки), то значит в теле карты у нас пустая строка, а
** следовательно карта не валидна, затем при проходе через нижнюю стену снова
** увеличиваем значение no_so на 1, что означает что мы прошли через южную
** стену, то есть уже прочли карту, а следовательно будут обрабатываться
** "пустые" строки;
** очищаем line;
*/

int8_t	get_map(char fd, t_game_info *game_info, t_map *map)
{
	game_info->no_so = 0;
	game_info->number_sprites = 0;
	map->column_length = 0;
	map->line_length = 0;
	game_info->temp_map = NULL;
	if (!(get_map_cicle(fd, game_info, map)))
		return (0);
	if (map->column_length < 3 || map->line_length < 3)
		return (0);
	free(game_info->line);
	if (!(map->map = ft_calloc(sizeof(char),
					(map->line_length * map->column_length) + 1)))
		exit_with_error(MALLOC_ERR);
	if (!(check_valid_player(game_info->temp_map)))
		return (0);
	map->map = copy_write_map(map->map, game_info->temp_map, map->line_length);
	free(game_info->temp_map);
	return (1);
}
