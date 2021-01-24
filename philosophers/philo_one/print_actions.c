/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 04:14:16 by emabel            #+#    #+#             */
/*   Updated: 2021/01/22 01:56:07 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		print_stop(t_links *link)
{
	if (link->d->stop_eat == link->d->num_of_phil && link->d->time_must_eat > 0)
		print_action(STOP, link);
}

/*
** ПОЛУЧАЕМ ВРЕМЯ В МИЛЛИСЕКУНДАХ
** gettimeofday()
*/

time_t		get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (unsigned long)1000) + (tv.tv_usec / 1000));
}

/*
** ПЕЧАТЬ СОСТОЯНИЙ ФИЛОСОФОВ, ИХ ID И ВРЕМЕНИ
*/

int			print_action(char *action, t_links *link)
{
	char	*philosopher_id;
	char	*current_time;

	philosopher_id = ft_itoa(link->p->id);
	current_time = ft_itoa(get_time() - link->d->time);
	pthread_mutex_lock(&link->d->write);
	if (!link->d->is_death || link->p->i_am_dead == 1)
	{
		write(1, "\e[0;33m[", 8);
		write(1, current_time, ft_strlen(current_time));
		write(1, "ms]\e[0m ", 8);
		if (action[12] != 'p')
			write(1, philosopher_id, ft_strlen(philosopher_id));
		write(1, action, ft_strlen(action));
		if (link->p->i_am_dead == 1)
		{
			free(philosopher_id);
			free(current_time);
			return (0);
		}
	}
	pthread_mutex_unlock(&link->d->write);
	free(philosopher_id);
	free(current_time);
	return (0);
}
