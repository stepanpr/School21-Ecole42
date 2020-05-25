/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 08:17:57 by emabel            #+#    #+#             */
/*   Updated: 2019/08/22 09:48:04 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*read_fd(int fd, int *size)
{
	char	*data;
	int		bytes_read;
	int		data_size;
	int		data_offset;

	data_size = 20000 * 20000;
	data = malloc(data_size);
	data_offset = 0;
	while ((bytes_read = read(fd, data + data_offset, data_size -
					data_offset)) > 0)
	{
		data_offset += bytes_read;
		if (data_offset == data_size)
		{
			data = my_realloc(data, data_size, data_size * 2);
			data_size *= 2;
		}
	}
	*size = data_offset;
	return (data);
}

void	parse_fd(int fd)
{
	char		*data;
	int			size;
	t_square	box;
	t_map		map;

	data = read_fd(fd, &size);
	map = parse_legend(data, size);
	if (is_valid_map(map))
	{
		box = parse_bsq(map);
		mark_box(map, box);
		output_map(map);
	}
	else
		printf("map error\n");
}

void	parse_file(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd > 0)
	{
		parse_fd(fd);
		close(fd);
	}
}

int		main(int argc, char **argv)
{
	int i;

	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
			parse_file(argv[i++]);
	}
	else
		parse_fd(0);
	return (0);
}
