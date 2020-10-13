/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_resolution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 08:05:25 by emabel            #+#    #+#             */
/*   Updated: 2020/10/12 16:00:57 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** проверяем наличие чисел после получения двух значений разрешения,
** если таковые присутствуют, то возвращаем ошибку;
*/

int		get_data_resolution_tail(char *line, t_resolution_tmp *res_tmp,
														int i, int rec)
{
	while (line[i] != '\0')
	{
		if ((ft_isdigit(line[i])))
		{
			return (RES_VAL_ERR);
		}
		i++;
	}
	return (0);
}

/*
** проделываем все то же самое для разрешения по высоте что и
** в функции get_data_resolution_width;
***********************
** ищем первое значние в цикле - если line[i] не равна пробелу,
** символу табуляции и является числом, то смотрим если мы не превысили
** допустимое количество символов в разрешении по ширине (rec = 8), то
** записываем символ line[i] в строку resolution_y_tmp;
***********************
** когда line[i + 1] снова является пробелом, то в resolution_y_tmp[rec]
** ствим символ конца строки и вызываем функцию проверки на остаток
** в строке get_data_resolution_tail;
***********************
** в случае если мы не хотим чтобы выводилась ошибка (RES_LEN_ERR),
** можно из функций считывания резрешения возвратить вместо (RES_LEN_ERR)
** любое дугое число больше 0, которое не будет обрабатываться в get_data_parce,
** тогда программа отработаем при разрешении любой длины
*/

int		get_data_resolution_height(char *line, t_resolution_tmp *res_tmp,
														int i, int rec)
{
	int	error_value;

	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\t' && (ft_isdigit(line[i])))
		{
			if (rec > 8)
				return (RES_LEN_ERR);
			res_tmp->resolution_y_tmp[rec] = line[i];
			rec++;
			if (line[i + 1] == ' ' || line[i + 1] == '\t')
			{
				res_tmp->resolution_y_tmp[rec] = '\0';
				i++;
				if ((error_value = get_data_resolution_tail(line, res_tmp,
															i, rec)) > 0)
					return (error_value);
				break ;
			}
		}
		i++;
	}
	return (0);
}

/*
** ищем первое значние в цикле - если line[i] не равна пробелу,
** символу табуляции и является числом, то смотрим если мы не превысили
** допустимое количество символов в разрешении по ширине (rec = 8), то
** записываем символ line[i] в строку resolution_x_tmp;
***********************
** если слудущий символ line[i + 1] является пробелом или табуляцией, то
** в resolution_x_tmp[rec] ставим символ конца строки, обнуляем rec и сдвигаем
** счетчик i;
*/

int		get_data_resolution_width(char *line, t_resolution_tmp *res_tmp,
														int i, int rec)
{
	int	error_value;

	while (line[i++] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\t' && (ft_isdigit(line[i])))
		{
			if (rec > 8)
				return (RES_LEN_ERR);
			res_tmp->resolution_x_tmp[rec] = line[i];
			rec++;
			if (line[i + 1] == ' ' || line[i + 1] == '\t')
			{
				res_tmp->resolution_x_tmp[rec] = '\0';
				rec = 0;
				i++;
				if ((error_value = get_data_resolution_height(line,
						res_tmp, i, rec)) > 0)
					return (error_value);
				break ;
			}
		}
	}
	return (0);
}

/*
** correct_resolution_value - проверяем строку на наличие допустимых
** символов, если встречаем букву, то возвращаем ошибку;
*************************
** counter_of_resolution_value - проверяем что указано два значения разрешения
*************************
** выделяем память под структуру хранящую временные значения
** и инициируем ее в функции get_data_resolution_allocation
*************************
** get_data_resolution_width запускаем цикл записывающий значения
** из строки, если цикл возвращает ошибку, то очищаем память и
** возвращаем ошибку в get_data_parce
*************************
** переводим временную строку в число и проверяем что получившеся
** значение больше минимально допустимого, если же нет то возвращаем
** ошибку в get_data_parce
*************************
** при успешном завершении, очищаем память
*/

int8_t	get_data_resolution(char *line, int *width,
								int *height, int error_value)
{
	t_resolution_tmp *res_tmp;

	if (!(correct_resolution_value(line)))
		return (RES_VAL_ERR);
	if ((counter_of_resolution_value(line, 'h')) == 0)
		return (RES_TWO_VAL);
	if (!(res_tmp = malloc(sizeof(t_resolution_tmp))))
		return (MALLOC_ERR);
	if (!(get_data_resolution_allocation(res_tmp, line)))
		return (MALLOC_ERR);
	if (((error_value = get_data_resolution_width(line, res_tmp,
					res_tmp->i, res_tmp->rec)) > 0))
	{
		get_data_resolution_free(res_tmp);
		return (error_value);
	}
	if ((*width = ft_atoi(res_tmp->resolution_x_tmp)) < 100 ||
		(*height = ft_atoi(res_tmp->resolution_y_tmp)) < 100)
	{
		get_data_resolution_free(res_tmp);
		return (RES_ERR);
	}
	get_data_resolution_free(res_tmp);
	return (1);
}
