/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 02:19:11 by emabel            #+#    #+#             */
/*   Updated: 2021/01/22 01:54:23 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# define FORK 			" \e[0;32mhas taken a fork\e[0m\n"
# define EATING 		" \e[0;32mis eating\e[0m\n"
# define SLEEPING 		" \e[0;32mis sleeping\e[0m\n"
# define THINKING 		" \e[0;32mis thinking\e[0m\n"
# define DIED 			" \e[0;33mdied\e[0m\n"
# define STOP 			" \e[0;34m[stop eating]\e[0m\n"
# define ERR_ARGS   	1
# define ERR_MALLOC 	2
# define ERR_THREAD 	3

/*
** ОБЪЕКТ ФИЛОСОФ
**	id              	id философа
**	left_fork;			id левой вилки
**	right_fork;			id правой вилки
**	eating_status;  	ест ли в филосов данный момент (1 || 0)
**	eat_counter;		сколько раз поел
**	i_am_dead       	философ жив или нет (1 || 0)
**	deadly_timestamp	метка времени на последний прием пищи
*/

typedef struct			s_philosopher {
	int					id;
	int					left_fork;
	int					right_fork;
	int					eating_status;
	int					eat_counter;
	int					i_am_dead;
	unsigned long		limit;
	long long			deadly_timestamp;
}						t_philosopher;

/*
** ОБЪЕКТ СТОЛ
**	*forks				вилки (массив мьютексов)
**  table_manager		мьютекс контролирующий чтобы пищу в
**						моменте принимал только один философ
*/

typedef struct			s_table {

	pthread_mutex_t		*forks;
	pthread_mutex_t		table_manager;
}						t_table;

/*
** СТРУКТУРА ДАННЫХ
**	num_of_phil			number_of_philosophers
**	time_to_die			time_to_die
**	time_to_eat			time_to_eat
**	time_to_sleep		time_to_sleep
**	time_must_eat		number_of_times_each_philosopher_must_eat]
**	time				текущее время выполнения программы (time in ms)
**
**	*threads			потоки (массив pthread_t)
**	*philos				массив объекта философа
**	table				объект стол
**	write				мьютекс защищающий вывод write
**	death	    		мьютекс защищающий проверку жизни
**
**	is_death			кто-то из философов умер
**	stop_eat			сколько закнчили есть
**
**
**	left_fork,			рабочие переменные для инициализации объекта философа
**	right_fork,
**	id
**
**	i		   	  		счетчик
*/

typedef struct			s_data
{
	time_t				num_of_phil;
	time_t				time_to_die;
	time_t				time_to_eat;
	time_t				time_to_sleep;
	time_t				time_must_eat;
	time_t				time;

	pthread_t			*threads;
	t_philosopher		*philos;
	t_table				table;
	pthread_mutex_t		write;
	pthread_mutex_t		death;

	int					is_death;
	int					stop_eat;

	int					left_fork;
	int					right_fork;
	int					id;

	int					i;
}						t_data;

/*
** СТРУКТУРА ССЫЛОК
**	*p	ссылка на объекта философа
**	*t	сслыка на объект стол
**	*d	ссылка на структуру данных
*/

typedef struct			s_links
{
	t_philosopher		*p;
	t_table				*t;
	t_data				*d;
}						t_links;

int						threads(t_data *d);
void					*life(void *links);
void					sleeping(t_links *link);
void					eating(t_links *link);
void					take_forks(t_links *link);
int						death_check(t_links *link);

int						error(t_data *d, int code);
int						clean_memory(t_data *d);

int						init(t_data *d, int ac, char **av);
int						init_data(t_data *d);
int						init_table(t_data *d);
int						init_philosopher(t_data *d);

int						ft_atoi(const char *str);
char					*ft_itoa(unsigned long n);
size_t					ft_strlen(const char *s);
char					*ft_strcpy(char *dest, const char *src);
int						print_action(char *action, t_links *link);
void					print_stop(t_links *link);
time_t					get_time(void);

#endif
