/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:38:43 by emabel            #+#    #+#             */
/*   Updated: 2021/01/21 21:19:34 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

/*
** ПРОВЕРКА СМЕРТЕЛЬНОГО ИСХОДА
** get_time() - link->p->deadly_counter
** из текущго времени вычитаем временную метку на момент последнего
** приема пищи тем самым получая количество времени котрое философ
** оставался без еды и затем сравниваем с входным параметром допустимого
** времени до смерти; если пройденное время без еды больше чем было указано
** в агрументе то завершаем программу
*/

int		death_check(t_links *link)
{
	sem_wait(link->d->death);
	if (!link->p->eating_status && !link->d->is_death &&
			get_time() - link->p->deadly_timestamp > link->d->time_to_die + 5)
	{
		link->d->is_death = 1;
		link->p->i_am_dead = 1;
		link->d->time_must_eat = 0;
		sem_post(link->d->death);
		print_action(DIED, link);
		return (1);
	}
	sem_post(link->d->death);
	return (0);
}

/*
** ПОДНЯТИЕ ВИЛОК
** философы получают доступ к вилкам только если семафор открыт
** блокируем доступ к print_action() семафором table_manager
*/

void	take_forks(t_links *link)
{
	sem_wait(link->t->forks);
	sem_wait(link->t->forks);
	sem_wait(link->t->table_manager);
	print_action(FORK, link);
	sem_post(link->t->table_manager);
	sem_wait(link->t->table_manager);
	print_action(FORK, link);
	sem_post(link->t->table_manager);
}

/*
** ПРИЕМ ПИЩИ
** 	блокируем процесс приема пищи семафором table_manager,
** 	чтобы доступ к процессу имел только один философ;
** 	меняем статус приема пищи (eating_status) на 1;
** 	обнуляем время последнего приема пищи (get_time());
** 	пинимаем пищу заданное количество времени (usleep);
** 	распечатываем текущий статус философа;
** 	инкрементируем счетчик количества приемов пищи;
** 	меняем статус приема пищи (eating_status) на 0;
** 	разблокируем семафор table_manager;
*/

void	eating(t_links *link)
{
	sem_wait(link->t->table_manager);
	link->p->eating_status = 1;
	link->p->deadly_timestamp = get_time();
	usleep(link->d->time_to_eat * 1000);
	print_action(EATING, link);
	++link->p->eat_count;
	link->p->eating_status = 0;
	sem_post(link->t->table_manager);
}

/*
** СОН
** 	распечатываем текущий статус философа;
** 	разблокируем семафоры (кладем обе вилки на стол)
** 	философ спит заданное количество времени (usleep);
*/

void	sleeping(t_links *link)
{
	print_action(SLEEPING, link);
	sem_post(link->t->forks);
	sem_post(link->t->forks);
	usleep(link->d->time_to_sleep * 1000);
	if ((link->d->time_to_sleep < 190 || link->d->time_to_eat < 190)
					&& !link->d->is_death && link->d->num_of_phil > 2)
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
*/

void	*life(void *links)
{
	t_links *link;

	link = (t_links*)links;
	usleep(link->p->id % 2 * 200);
	link->p->deadly_timestamp = get_time();
	while (!link->d->is_death)
	{
		if (death_check(link))
			break ;
		take_forks(link);
		eating(link);
		if (link->p->eat_count == link->d->time_must_eat && ++link->d->stop_eat)
			break ;
		if (death_check(link))
			break ;
		sleeping(link);
		print_action(THINKING, link);
	}
	sem_post(link->t->forks);
	sem_post(link->t->forks);
	if (!link->d->time_must_eat)
		sem_post(link->d->write);
	if (link->d->stop_eat == link->d->num_of_phil && link->d->time_must_eat > 0)
		print_action(STOP, link);
	return (NULL);
}
