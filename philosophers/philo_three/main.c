/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 02:54:47 by emabel            #+#    #+#             */
/*   Updated: 2021/01/22 02:04:13 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

/*
** ФУНКЦИЯ ОЧИСТКИ
** закрытие семафоров
** очистка аллоцированной памяти
*/

int				clean_memory(t_data *d)
{
	if (d)
	{
		sem_close(d->table.forks);
		sem_close(d->write);
		sem_close(d->death);
		sem_close(d->table.table_manager);
		sem_unlink("/forks");
		sem_unlink("/table_manager");
		sem_unlink("/write");
		sem_unlink("/death");
		if (d->philos)
		{
			free(d->philos);
			d->philos = NULL;
		}
		free(d);
	}
	return (0);
}

/*
** ВЫВОД ОШИБОК И ЗАПУСК ФУНКЦИИ ОЧИСТКИ
*/

int				error(t_data *d, int code)
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
** ОЖИДАНИЕ У УДАЛЕНИЕ ПРОЦЕССОВ
**	ожидаем завершения дечерних процессов с помощью функции WAITPID
**	pid_t waitpid(pid_t pid, int *status, int options);
**	waitpid приостанавливает выполнение текущего процесса до тех пор,
**	пока дочерний процесс, указанный в параметре pid, не завершит выполнение;
**	при первом аргументе равном -1, функция ждет любой дочерний процесс;
**	WIFEXITED(st) возвращает ненулевое значение если процесс завершился и был
**	возвращен статус;
** 	WEXITSTATUS(st) возвращает статус завершения дочернего процесса
**	переданный в exit();
**	WEXITSTATUS(st) следует использовать лишь если WIFEXIDED(status) равен true;
**
** * https://pubs.opengroup.org/onlinepubs/9699919799/functions/waitpid.html
** * (есть пример со статусами)
** * https://www.opennet.ru/man.shtml?topic=waitpid&category=2&russian=0#lbAE
** * https://habr.com/ru/post/423049/
**
**	если status != 3, значит никто из философов не умер, в этом случае
**	распечатываем [stop eating];
**  через вызов kill() посылаем сигнал SIGKILL уничтожение процесса каждому
**	из процессов;
*/

void			wait_and_kill(t_data *d, t_links *links, int *status)
{
	int			i;

	i = 0;
	waitpid(-1, status, 0);
	if (d->time_must_eat > 0 && WIFEXITED(*status) && WEXITSTATUS(*status) != 3)
		print_action(STOP, links);
	while (i < d->num_of_phil)
	{
		kill(d->philos[i].pid, SIGKILL);
		i++;
	}
}

/*
** СОЗДАНИЕ ПРОЦЕССОВ
** 	объявляем структуру-ссылку на структуры, выделяем память;
** 	инициируем программное время (get_time());
**  присваиваем значения структуре-ссылке;
**	в цикле при каждой итерации присваиваем "links->p" своего философа,
**	затем увеличивая счетчик для масива философов "d->philos" и
**	порождаем процессы с помощью fork();
**	если pid развен 0, то запускаем функцию life;
**	запускаем функцию wait_and_kill() ожидающую исполнения
**	процесса и "убивающуую" его;
**	очищаем структуру-ссылку;
*/

int				process(t_data *d)
{
	t_links		*links;
	int			status;

	if (!(links = (t_links *)malloc(sizeof(t_links))))
		return (ERR_MALLOC);
	d->time = get_time();
	d->i = 0;
	links->t = &d->table;
	links->d = d;
	while (d->i < d->num_of_phil)
	{
		links->p = &d->philos[d->i];
		if ((d->philos[d->i].pid = fork()) < 0)
			return (1);
		else if (d->philos[d->i].pid == 0)
			status = life(links);
		d->i++;
	}
	wait_and_kill(d, links, &status);
	free(links);
	return (0);
}

/*
** ФУНКЦИЯ MAIN
** 	начальная проверка аргументов;
** 	запуск функций инициализации;
** 	запуск функции создания процессов;
** 	при возникновении ошибки, записываем ее код в переменную status,
** 	которую передаем в функцию error;
*/

int				main(int ac, char **av)
{
	t_data		*d;
	int			status;

	d = NULL;
	status = 0;
	if ((ac < 5 || ac > 6) && error(d, ERR_ARGS))
		return (1);
	if (!(d = (t_data*)malloc(sizeof(t_data))) && error(d, ERR_MALLOC))
		return (1);
	if ((status = init(d, ac, av)) > 0 && (error(d, status)))
		return (1);
	if ((status = process(d)) > 0 && (error(d, status)))
		return (1);
	clean_memory(d);
	return (0);
}
