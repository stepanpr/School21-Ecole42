/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 06:58:45 by emabel            #+#    #+#             */
/*   Updated: 2021/01/21 21:24:11 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

/*
** ИНИЦИАЛИЗАЦИЯ ФИЛОСОФОВ
** 	присваиваем переменныем объекта философа начальные значения;
*/

int			init_philosopher(t_data *d)
{
	d->i = 0;
	d->id = 1;
	d->left_fork = 0;
	d->right_fork = 1;
	if (!(d->philos = (t_philosopher *)
				malloc(sizeof(t_philosopher) * d->num_of_phil)))
		return (ERR_MALLOC);
	while (d->i < d->num_of_phil)
	{
		if (d->left_fork == d->num_of_phil - 1)
			d->right_fork = 0;
		d->philos[d->i].id = d->id++;
		d->philos[d->i].left_fork = d->left_fork++;
		d->philos[d->i].right_fork = d->right_fork++;
		d->philos[d->i].deadly_timestamp = 0;
		d->philos[d->i].i_am_dead = 0;
		d->philos[d->i].eating_status = 0;
		d->philos[d->i].eat_count = 0;
		d->i++;
	}
	return (0);
}

/*
** с помощью sem_unlink() удаляем семафоры связанные с передаваемым
** именем из системы (на случай если они ранее был созданы);
** создаем ИМЕНОВАННЫЕ семафоры функцией sem_open() (при помощи этой же
** функции можно получить доступ к уже существующему именованному семафору),
** которая возвращает указатель на семафор, а при ошибке она
** возвращает SEM_FAILED и устанавливает errno;
** семафору "/forks" даем начальное значение равное количеству философов;
** семафор "/write" контролирует доступ к выводу статуса философа;
** семафор "/death" контролирует доступ к проверке смерти;
** * НЕИМЕНОВАННЫЕ семафоры инициализируются функцией sem_init(),
** * но эта функция так же как как sem_destroy() и sem_getvalue() считается
** * устаревшей и не работает;
** * https://it.wikireading.ru/24889
** * https://www.softprayog.in/programming/posix-semaphores
*/

int			init_semaphores(t_data *d)
{
	sem_unlink("/forks");
	sem_unlink("/table_manager");
	sem_unlink("/write");
	sem_unlink("/death");
	if ((d->table.forks = sem_open("/forks", O_CREAT, 0644, d->num_of_phil))
																== SEM_FAILED)
		return (1);
	if ((d->table.table_manager = sem_open("/table_manager", O_CREAT, 0644, 1))
																== SEM_FAILED)
		return (1);
	if ((d->write = sem_open("/write", O_CREAT, 0644, 1)) == SEM_FAILED)
		return (1);
	if ((d->death = sem_open("/death", O_CREAT, 0644, 1)) == SEM_FAILED)
		return (1);
	return (0);
}

/*
** ИНИЦИАЛИЗАЦИЯ СТРУКТУРЫ T_DATA
** 	присваиваем переменныем объекта философа начальные значения;
** 	инициализация мьютекса write (контролирует доступ к выводу статуса);
** 	инициализация мьютекса death (контролирует доступ к проверке смерти);
** 	вызываем функцию инициализирующую вилки;
** 	вызываем функцию инициализирующую философов;
** 	выделяем память для массива потоков threads;
*/

int			init_data(t_data *d)
{
	d->is_death = 0;
	d->time = 0;
	d->stop_eat = 0;
	d->i = 0;
	if (init_semaphores(d))
		return (ERR_MALLOC);
	if (init_philosopher(d))
		return (ERR_MALLOC);
	return (0);
}

/*
** ЗАПИСЬ АРГУМЕНТОВ В ПЕРЕМЕННЫЕ И ВЫЗОВ ИНИЦИАЛИЗИРУЮЩИХ ФУНКЦИЙ
*/

int			init(t_data *d, int ac, char **av)
{
	d->philos = NULL;
	d->table.forks = NULL;
	if ((d->num_of_phil = ft_atoi(av[1])) < 2 || d->num_of_phil > 200)
		return (ERR_ARGS);
	if ((d->time_to_die = ft_atoi(av[2])) < 60)
		return (ERR_ARGS);
	if ((d->time_to_eat = ft_atoi(av[3])) < 60)
		return (ERR_ARGS);
	if ((d->time_to_sleep = ft_atoi(av[4])) < 60)
		return (ERR_ARGS);
	d->time_must_eat = 0;
	if (ac == 6 && (d->time_must_eat = ft_atoi(av[5])) <= 0)
		return (ERR_ARGS);
	return (init_data(d));
}
