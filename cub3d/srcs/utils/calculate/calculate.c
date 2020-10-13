/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 00:02:20 by imicah            #+#    #+#             */
/*   Updated: 2020/10/03 08:01:43 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float		get_texture_coordinate(float current_x)
{
	if (current_x < 0)
		return (0);
	return (current_x);
}

float		get_distance(float x, float y)
{
	return (sqrtf(x * x + y * y));
}
