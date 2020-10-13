/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 06:44:29 by emabel            #+#    #+#             */
/*   Updated: 2020/10/12 11:41:27 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					numbers_of_color_value(char *line)
{
	int				i;
	int				values;

	i = 0;
	values = 0;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]))
		{
			values++;
			while (ft_isdigit(line[i]))
				i++;
		}
		while (!(ft_isdigit(line[i])) && line[i] != '\0')
			i++;
	}
	if (values < 3 || values > 3)
	{
		return (COLOR_VAL_ERR);
	}
	return (0);
}

int					correct_color_value(char *line)
{
	int				k;

	k = 1;
	while (line[k] != '\0')
	{
		if (line[k] != ' ' && line[k] != '\t' && line[k] != ','
										&& !(ft_isdigit(line[k])))
		{
			return (COLOR_VAL_ERR);
		}
		k++;
	}
	return (0);
}

int					get_data_color_cycle(char *line, int color_value,
											char *color, int8_t flag)
{
	int				q;

	q = 0;
	while (*line && q < 3)
	{
		if ((('0' <= *line && *line <= '9') || *line == '-') && flag)
		{
			color_value = ft_atoi(line);
			flag = 0;
			if (0 <= color_value && color_value <= 255)
				color[q++] = (unsigned char)color_value;
			else
				return (COLOR_ERR);
		}
		else if (!(('0' <= *line && *line <= '9') || *line == '-'))
			flag = 1;
		line++;
	}
	return (0);
}

int8_t				get_data_color(char *line, t_color *rgb)
{
	unsigned char	color[3];
	int				color_value;
	int8_t			flag;

	if ((correct_color_value(line)) > 0)
	{
		return (COLOR_VAL_ERR);
	}
	if ((numbers_of_color_value(line)) > 0)
	{
		return (COLOR_VAL_ERR);
	}
	if ((get_data_color_cycle(line, color_value, color, flag)) > 0)
		return (COLOR_ERR);
	rgb->r = color[0];
	rgb->g = color[1];
	rgb->b = color[2];
	return (1);
}
