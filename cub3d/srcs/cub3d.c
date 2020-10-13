/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 02:27:38 by emabel            #+#    #+#             */
/*   Updated: 2020/10/09 05:23:54 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** MAIN
*/

int		main(int ac, char **av)
{
	const int8_t	fd = (char)open(av[1], O_RDONLY);
	t_game_info		game_info;
	t_screen		screen;

	check_arguments(fd, ac, av);
	if (ac == 1)
		exit_with_error(ARG_ERR);
	else if (fd == -1)
		exit_with_error(FILE_ERR);
	screen.mlx = mlx_init();
	get_data(fd, &game_info, &screen);
	if (get_map(fd, &game_info, &game_info.map) == 0)
		exit_with_error(MAP_ERR);
	close(fd);
	engine(game_info, screen, av[2]);
	return (0);
}
