/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 07:47:26 by emabel            #+#    #+#             */
/*   Updated: 2020/05/23 12:33:00 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			**ft_mem_free(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static unsigned int	ft_get_nb_strs(char const *s, char c)
{
	unsigned int	i;
	unsigned int	nb_strs;

	if (!s[0])
		return (0);        
	i = 0;
	nb_strs = 0;
	while (s[i] && s[i] == c)     // если S[i] равно разделителю, то увеличиваем индекс в начале
		i++;
	while (s[i])                 // идем по слову, если указатель внова равен С (разделителю), то добавляем слово в nb_strs
	{
		if (s[i] == c)           
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)              // если s[i - 1] в конце не равен разделителю, то увеличиваем индекс, прибавляем слово в nb_strs
		nb_strs++;
	return (nb_strs);
}

static void			ft_next_str(char **next_str, unsigned int *next_str_len,
					char c)
{
	unsigned int i;

	*next_str += *next_str_len;
	*next_str_len = 0;
	i = 0;
	while (**next_str && **next_str == c)  //если указатель равен разделителю, то идем вперед по индексу
		(*next_str)++;
	while ((*next_str)[i])             // далее счтаем слово
	{
		if ((*next_str)[i] == c)         //если снова встречаем разделитель, то возвращаем
			return ;
		(*next_str_len)++;
		i++;
	}
}

char				**ft_split(char const *s, char c)
{
	char			**tab;
	char			*next_str;
	unsigned int	next_str_len;
	unsigned int	nb_strs;
	unsigned int	i;

	if (!s)	   // если не S, то возвращаем налл
		return (NULL);                     
	nb_strs = ft_get_nb_strs(s, c);             // дальше считаем количество слов       
	if (!(tab = malloc(sizeof(char *) * (nb_strs + 1)))) // выделяем память
		return (NULL);
	i = 0;
	next_str = (char *)s;						
	next_str_len = 0;  								
	while (i < nb_strs)								//дальше присваиваем 
	{
		ft_next_str(&next_str, &next_str_len, c);    //в next_str считаем слово посимвольно
		if (!(tab[i] = malloc(sizeof(char) * (next_str_len + 1))))  // выделяем память в зависимости от длины
			return (ft_mem_free(tab));								// в случае неудачи очищаем
		ft_strlcpy(tab[i], next_str, next_str_len + 1);				//в strlcpy копируем слово (next_str) в tab[i]
		i++;
	}
	tab[i] = NULL;		// присваиваем Налл в конце и
	return (tab);     // возвращаем ТАБ
}
