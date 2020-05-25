/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 07:40:09 by emabel            #+#    #+#             */
/*   Updated: 2019/08/22 09:47:16 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_map_descriptor {
	int				w;
	int				h;
	char			c_empty;
	char			c_obstacle;
	char			c_full;
	char			*data;
}					t_map;

typedef struct		s_square {
	int				w;
	int				x;
	int				y;
}					t_square;

char				*my_realloc(char *data, int size, int new_size);
int					index_of_free(char *s, char c, int n);
int					my_atoi(char *s);
t_map				parse_legend(char *data, int size);
int					is_valid_map(t_map map);
t_square			parse_bsq(t_map map);
void				mark_box(t_map map, t_square box);
void				parse_fd(int fd);
char				*read_fd(int fd, int *size);
int					find_square(t_map map, int x, int y, t_square *bsq);
void				output_map(t_map map);
void				parse_file(char *filename);

#endif
