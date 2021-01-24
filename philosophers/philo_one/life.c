/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:38:43 by emabel            #+#    #+#             */
/*   Updated: 2021/01/22 01:55:46 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

/*
** ПРОВЕРКА СМЕРТЕЛЬНОГО ИСХОДА
** 	get_time() - link->p->deadly_counter
** 	из текущго времени вычитаем временную метку на момент последнего
** 	приема пищи тем самым получая количество времени котрое философ
** 	оставался без еды и затем сравниваем с входным параметром допустимого
** 	времени до смерти; если пройденное время без еды больше чем было указано
** 	в агрументе, то завершаем программу
*/

int		death_check(t_links *link)
{
	pthread_mutex_lock(&link->d->death);
	if (!link->p->eating_status && !link->d->is_death &&
			get_time() - link->p->deadly_timestamp > link->d->time_to_die + 5)
	{
		link->d->time_must_eat = 0;
		link->d->is_death = 1;
		link->p->i_am_dead = 1;
		pthread_mutex_unlock(&link->d->death);
		print_action(DIED, link);
		return (1);
	}
	pthread_mutex_unlock(&link->d->death);
	return (0);
}

/*
** ПОДНЯТИЕ ВИЛОК (иерархия ресурсов)
** 	последний философ (с id равным заданному количеству философов),
** 	подинает сначала правую вилку, тогда как остальные философы поднимают
** 	вначале левую, тем самым мы избегаем ситуации взаимной блокировки (дедлока);
*/

void	take_forks(t_links *link)
{
	if (link->p->id == link->d->num_of_phil)
	{
		pthread_mutex_lock(&link->t->forks[link->p->right_fork]);
		print_action(FORK, link);
		pthread_mutex_lock(&link->t->forks[link->p->left_fork]);
		print_action(FORK, link);
	}
	else
	{
		pthread_mutex_lock(&link->t->forks[link->p->left_fork]);
		print_action(FORK, link);
		pthread_mutex_lock(&link->t->forks[link->p->right_fork]);
		print_action(FORK, link);
	}
}

/*
** ПРИЕМ ПИЩИ
** 	блокируем процесс приема пищи мьютексом table_manager,
** 	чтобы доступ к процессу имел только один философ;
** 	меняем статус приема пищи (eating_status) на 1;
** 	обнуляем время последнего приема пищи (get_time());
** 	пинимаем пищу заданное количество времени (usleep);
** 	распечатываем текущий статус философа;
** 	инкрементируем счетчик количества приемов пищи;
** 	меняем статус приема пищи (eating_status) на 0;
** 	разблокируем мьютекс (table_manager);
*/

void	eating(t_links *link)
{
	pthread_mutex_lock(&link->t->table_manager);
	link->p->eating_status = 1;
	link->p->deadly_timestamp = get_time();
	usleep(link->d->time_to_eat * 1000);
	print_action(EATING, link);
	++link->p->eat_counter;
	link->p->eating_status = 0;
	pthread_mutex_unlock(&link->t->table_manager);
}

/*
** СОН
** 	распечатываем текущий статус философа;
** 	кладем обе вилки на стол - сначала правую, затем левую,
** 	чтобы остальные философы сразу имели доступ к правой вилке;
** 	философ спит заданное количество времени (usleep);
*/

void	sleeping(t_links *link)
{
	print_action(SLEEPING, link);
	pthread_mutex_unlock(&link->t->forks[link->p->right_fork]);
	pthread_mutex_unlock(&link->t->forks[link->p->left_fork]);
	usleep(link->d->time_to_sleep * 1000);
	if ((link->d->time_to_sleep <= 100 || link->d->time_to_eat <= 100)
					&& link->d->num_of_phil > 2 && !link->d->is_death)
		usleep(100 * 1000);
}

/*
** ЖИЗНЕННЫЙ ЦИКЛ ФИЛОСОФА
** 	в deadly_counter инициируем подсчет времени перед циклом
** 	и обнуляем счетчик в цикле каждый раз после приема пищи,
** 	затем проверяем занчение счетчика в функции death_check;
** 	в каждой интерации сравниваем переменные eat_counter и time_must_eat,
** 	если они равны, то прерываем цикл - философ поел заданное количество раз;
** 	после завершения цикла, инкрементируем счетчик stop_eating в
** 	каждом потоке (философе), после чего сравниваем с количеством философов,
** 	если значения равны, значит заданное количество раз поели все философы,
** 	печатаем  "stop eting" и завершаем программу;
**	// link->p->limit = link->p->deadly_timestamp  + link->d->time_to_die;
*/

void	*life(void *links)
{
	t_links *link;

	link = (t_links*)links;
	usleep(link->d->num_of_phil % 2 * 200);
	link->p->deadly_timestamp = get_time();
	while (!link->d->is_death)
	{
		if (death_check(link))
			break ;
		take_forks(link);
		eating(link);
		if (link->p->eat_counter == link->d->time_must_eat)
			break ;
		if (death_check(link))
			break ;
		sleeping(link);
		print_action(THINKING, link);
	}
	pthread_mutex_unlock(&link->t->forks[link->p->right_fork]);
	pthread_mutex_unlock(&link->t->forks[link->p->left_fork]);
	if (!link->d->time_must_eat)
		pthread_mutex_unlock(&link->d->write);
	++link->d->stop_eat;
	print_stop(link);
	return (NULL);
}
