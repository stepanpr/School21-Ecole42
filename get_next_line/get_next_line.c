/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 01:42:06 by emabel            #+#    #+#             */
/*   Updated: 2020/07/12 11:25:50 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** валидация при входе в функцию; проверяем на существование строки,
** дескриптор; выделяем память по размеру BUFFER_SIZE + 1
*/

static int		validate(char **line, char **buff, int fd)
{
	*buff = NULL;
	if ((!line) || (BUFFER_SIZE <= 0) || (read(fd, *buff, 0) < 0) || (fd < 0))
		return (-1);
	if (*buff == NULL)
	{
		if (!(*buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
			return (-1);
		*buff[0] = '\0';
	}
	return (1);
}

/*
** очистка памяти
*/

static int		ft_free(char **str, char **line)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	if (*line)
		*line = NULL;
	return (-1);
}

/*
** - ищем позицию (указатель) \n в, заменяем его на \0, передаем tail в line,
** - дублируем остаток строки после того, как
** предвинули указатель с конца строки вправо,
** - завершаем программу, возвращаем 1 -
** символ того, что файл еще не прочитан до конца
*/

static int		get_line(char **tail, char **line)
{
	char		*tmp;

	tmp = ft_strchr(*tail, '\n');
	*tmp++ = '\0';
	*line = *tail;
	*tail = NULL;
	if (!(*tail = ft_strdup(tmp)))
		return (-1);
	return (1);
}

/*
** - если буфер к примеру был большим, то
** в этой функции мы из сохраненных хвостов выводим строчки;
** - тут также, если находим \n, то вызываем get_line  логика повторяется;
** - если считали сразу много, и \n не встретили,
** то записываем все целиком в line;
** - файл прочитан до конца возвращаем 0;
** - пустой strdup нужен чтобы обработать пустой файл
** без строк, если есть только EOF
*/

static int		get_tail(char **tail, char **line)
{
	if (*tail)
	{
		if (ft_strchr(*tail, '\n'))
			return (get_line(tail, line));
		*line = *tail;
		*tail = NULL;
		return (0);
	}
	if (!(*line = ft_strdup("")))
		return (ft_free(tail, line));
	return (0);
}

/*
** вызываем функцию исполняющую валидацию;
** в цикле while читаем в буфер, пока read возвращает значение > 0;
** - присваиваем buff[readed_bytes] символ конца строки (встает как раз в конец,
** так как индекс в массиве начинается с 0, то есть длина - 1),
** - читаем в цикле файл до переноса строки, либо пока файл не закончится
** - записываем в результирующую строчку (стек) прочитанную часть buff,
** ft_strjoin выделяет память под строку длинной tail+buff;
** - когда ft_strjoin срабоатывает снова,
** то опять выделяет память под tail+buff,
** а предыдущуюю выделенную память в tmp обязательно удаляем;
** - во втором if ищем в результирующей строке, которая
** получилась в ft_strjoin символ переноса строки,
**  если нашли \n, то прекращаем цикл и наполняем line
** - if (readed_bytes < 0) - если в процессе работы что-то произошло с файлом
** - return (get_tail(&tail, line)) - если буфер к примеру большой
*/

int				get_next_line(int fd, char **line)
{
	static char	*tail = NULL;
	char		*tmp;
	char		*buff;
	ssize_t		readed_bytes;

	if (!(validate(line, &buff, fd)) || BUFFER_SIZE <= 0)
		return (ft_free(&tail, line));
	readed_bytes = 0;
	while ((readed_bytes = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[readed_bytes] = '\0';
		tmp = tail;
		if (!(tail = ft_strjoin(tail, buff)))
			return (ft_free(&tail, line));
		free(tmp);
		if (ft_strchr(tail, '\n'))
		{
			free(buff);
			return (get_line(&tail, line));
		}
	}
	if (readed_bytes < 0)
		return (ft_free(&tail, line));
	free(buff);
	return (get_tail(&tail, line));
}
