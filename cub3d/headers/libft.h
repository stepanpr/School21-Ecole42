/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 11:32:23 by emabel            #+#    #+#             */
/*   Updated: 2020/10/12 16:01:57 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# define MAX_LONG_LONG 9223372036854775807

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

long long			ft_atoi(const char *str);
int					ft_strcmp(const char *arr1, const char *arr2);
int					ft_strchr(const char *str, char ch);

size_t				ft_strlen(const char *str);

void				ft_bzero(void *dest, size_t byte_sizes);
void				*ft_calloc(size_t num, size_t byte_sizes);
void				*ft_realloc(char *src, int len);

char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strjoin(char const *s1, char const *s2);

int					ft_isdigit(int c);

#endif
