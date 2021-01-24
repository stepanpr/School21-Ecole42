/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 02:54:47 by emabel            #+#    #+#             */
/*   Updated: 2021/01/21 21:07:16 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

/*
** ФУНКЦИЯ ОЧИСТКИ
** удаление мьютексов
** очистка аллоцированной памяти
*/

int			clean_memory(t_data *d)
{
	int		i;

	i = -1;
	if (d)
	{
		if (d->table.forks)
		{
			while (++i < d->num_of_phil)
				pthread_mutex_destroy(&(d->table.forks)[i]);
			pthread_mutex_destroy(&(d->table.table_manager));
			pthread_mutex_destroy(&(d->write));
			pthread_mutex_destroy(&(d->death));
			free(d->table.forks);
		}
		if (d->threads)
			free(d->threads);
		if (d->philos)
			free(d->philos);
		free(d);
	}
	return (0);
}

/*
** ВЫВОД ОШИБОК И ЗАПУСК ФУНКЦИИ ОЧИСТКИ
*/

int			error(t_data *d, int code)
{
	if (code == ERR_ARGS)
		write(1, "Error: argument\n", 16);
	if (code == ERR_MALLOC)
		write(1, "Error: malloc\n", 14);
	if (code == ERR_THREAD)
		write(1, "Error: thread\n", 14);
	if (d)
		clean_memory(d);
	return (1);
}

/*
** ИНИЦИАЛИЗАЦИЯ ПОТОКОВ
** 	объявляем массив структур-ссылок на структуры, выделяем память;
** 	инициируем программное время (get_time());
** 	в первом цикле присваиваем значения каждой из структур-ссылок;
** 	там же создаем потоки (pthread_create) с выходом на функцию life;
** 	во втором цикле ожидаем завершения потоков с помощью функции pthread_join;
*/

int			threads(t_data *d)
{
	t_links *links;

	if (!(links = (t_links *)malloc(sizeof(t_links) * d->num_of_phil)))
		return (ERR_MALLOC);
	d->time = get_time();
	d->i = 0;
	while (d->i < d->num_of_phil)
	{
		links[d->i].p = &d->philos[d->i];
		links[d->i].t = &d->table;
		links[d->i].d = d;
		if (pthread_create(&d->threads[d->i], NULL, &life, &links[d->i]))
			return (ERR_THREAD);
		d->i++;
	}
	d->i = 0;
	while (d->i < d->num_of_phil)
		pthread_join(d->threads[d->i++], NULL);
	free(links);
	return (0);
}

/*
** ФУНКЦИЯ MAIN
** 	начальная проверка аргументов;
** 	запуск функций инициализации;
** 	запуск функций потока;
** 	при возникновении ошибки, записываем ее код в переменную status,
** 	которую передаем в функцию error;
*/

int			main(int ac, char **av)
{
	t_data	*d;
	int		status;

	d = NULL;
	status = 0;
	if ((ac < 5 || ac > 6) && error(d, ERR_ARGS))
		return (1);
	if (!(d = (t_data*)malloc(sizeof(t_data))) && error(d, ERR_MALLOC))
		return (1);
	if ((status = init(d, ac, av)) > 0 && (error(d, status)))
		return (1);
	if ((status = threads(d)) > 0 && (error(d, status)))
		return (1);
	clean_memory(d);
	return (0);
}
