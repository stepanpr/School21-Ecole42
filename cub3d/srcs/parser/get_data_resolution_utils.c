/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_resolution_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 10:39:15 by emabel            #+#    #+#             */
/*   Updated: 2020/10/12 15:19:01 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
**	очистка выделенной памяти под структуру
*/

void	get_data_resolution_free(t_resolution_tmp *res_tmp)
{
	free(res_tmp->resolution_x_tmp);
	free(res_tmp->resolution_y_tmp);
	free(res_tmp);
}

/*
**	инициация структуры храняещей временные значения разрешения
*/

int		get_data_resolution_allocation(t_resolution_tmp *res_tmp, char *line)
{
	res_tmp->resolution_x_tmp = NULL;
	res_tmp->resolution_y_tmp = NULL;
	res_tmp->error_value = 0;
	res_tmp->i = 1;
	res_tmp->rec = 0;
	if (!(res_tmp->resolution_x_tmp = (char*)malloc(sizeof(char) *
							(counter_of_resolution_value(line, 'w')) + 1)))
		return (0);
	if (!(res_tmp->resolution_y_tmp = (char*)malloc(sizeof(char) *
							(counter_of_resolution_value(line, 'h')) + 1)))
		return (0);
	return (1);
}

/*
**	проверка на отсутствие не предусмотренных символов
*/

int		correct_resolution_value(char *line)
{
	int k;

	k = 1;
	while (line[k] != '\0')
	{
		if (line[k] != ' ' && line[k] != '\t' && !(ft_isdigit(line[k])))
			return (0);
		k++;
	}
	return (1);
}

/*
**	подсчет длины значений разрешения
*/

int		counter_of_resolution_value_height(char *line, int counter, char togle)
{
	int	len_of_val_res_h;

	len_of_val_res_h = 0;
	while (line[counter++] != '\0')
	{
		if ((ft_isdigit(line[counter])) && togle == 'h')
		{
			len_of_val_res_h++;
			if (line[counter + 1] == ' ' || line[counter + 1] == '\t' ||
				line[counter + 1] == '\0' || !(ft_isdigit(line[counter + 1])))
				return (len_of_val_res_h);
		}
	}
}

int		counter_of_resolution_value(char *line, char togle)
{
	int	len_of_val_res_w;
	int	counter;

	len_of_val_res_w = 0;
	counter = 0;
	while (line[counter++] != '\0')
	{
		if ((ft_isdigit(line[counter])) && togle == 'w')
		{
			len_of_val_res_w++;
			if (line[counter + 1] == ' ' || line[counter + 1] == '\t'
									|| !(ft_isdigit(line[counter + 1])))
				return (len_of_val_res_w);
		}
		if (((ft_isdigit(line[counter])) && togle != 'w') &&
				(line[counter + 1] == ' ' || line[counter + 1] == '\t'))
		{
			counter++;
			break ;
		}
	}
	return (counter_of_resolution_value_height(line, counter, togle));
}
