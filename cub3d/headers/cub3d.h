/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emabel <emabel@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 10:25:22 by emabel            #+#    #+#             */
/*   Updated: 2020/10/12 16:09:39 by emabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "mlx_int.h"
# include "get_next_line.h"
# include "libft.h"
# include "bmp.h"

# define MAP_CHAR		" 012NSEW"
# define PLAYER_POS		"NSEW"
# define COUNT_ARG		8
# define PI_DIV_180		(float)(M_PI / 180.f)
# define FOV			60.f
# define FOV_RAD		FOV * PI_DIV_180
# define CELL			64
# define PLAYER_SPEED	6

/*
** KEYS LINUX
*/
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define UP_ARROW	65362
# define DOWN_ARROW		65364
# define M 109

/*
** KEYS MAC
*/
# define ESC_MAC 53
# define W_MAC 13
# define A_MAC 0
# define S_MAC 1
# define D_MAC 2
# define LEFT_ARROW_MAC 123
# define RIGHT_ARROW_MAC 124
# define UP_ARROW_MAC	126
# define DOWN_ARROW_MAC		125
# define M_MAC 46

/*
** --ERRORS--
** COLOR_ERR		"Color should be from 0 to 255"
** RES_ERR	 		"Resolution should be from 100"
** TEX_ERR 	 		"Wrong texture path"
** LESS_ARG_ERR 	"Not enough tools"
** ARG_ERR 			"Double tools"
** FILE_ERR 		"No file name argument"
** MAP_ERR 			"Invalid map"
** UNKNOWN_ERR 		"Unknown argument"
** FORMAT_ERR 		"Wrong file format"
** MALLOC_ERR		"Memory error"
** RES_LEN_ERR		"Too high resolution"
** RES_VAL_ERR		"Incorrect value of resolution"
** RES_TWO_VAL		"Resolution must have two meanings"
** COLOR_VAL_ERR 	"Incorrect value of color"
*/

# define COLOR_ERR		2
# define RES_ERR		3
# define TEX_ERR		4
# define LESS_ARG_ERR	5
# define ARG_ERR		7
# define FILE_ERR		8
# define MAP_ERR		9
# define UNKNOWN_ERR	10
# define FORMAT_ERR		11
# define MALLOC_ERR		12
# define RES_LEN_ERR	13
# define RES_VAL_ERR	14
# define RES_TWO_VAL	15
# define COLOR_VAL_ERR	16

typedef struct	s_color
{
	u_int8_t	r;
	u_int8_t	g;
	u_int8_t	b;
}				t_color;

typedef struct	s_img_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img_data;

typedef struct	s_texture
{
	t_img_data	img_data;
	float		step;
	int			x;
	int			y;
}				t_texture;

typedef struct	s_map
{
	char		*map;
	int			line_length;
	int			column_length;
	int			x;
	int			y;
}				t_map;

typedef struct	s_player
{
	t_map		map;
	float		x;
	float		y;
	float		pov;
	float		look;
}				t_player;

typedef struct	s_screen
{
	void		*mlx;
	void		*win;
	t_img_data	img_world;
	int			width;
	int			height;
}				t_screen;

typedef struct	s_sprite
{
	float		x;
	float		y;
	float		dist;
	int			h_offset;
	int			v_offset;
	int			height;
	t_texture	texture;
}				t_sprite;

typedef struct	s_game_info
{
	char		*line;
	char		*temp_map;
	int			no_so;
	int			read_res;
	int			number_sprites;
	t_sprite	*sprites;
	t_img_data	textures[4];
	t_img_data	sprite_texture;
	t_map		map;
	t_color		floor_color;
	t_color		ceiling_color;
}				t_game_info;

typedef	struct	s_cub
{
	t_game_info	game_info;
	t_screen	screen;
	t_player	player;
	t_texture	wall_texture;
}				t_cub;

typedef struct	s_distance
{
	float		distance;
	float		x;
}				t_distance;

typedef struct	s_coordinates
{
	float		x;
	float		y;
}				t_coordinates;

typedef struct	s_resolution_tmp
{
	char		*resolution_x_tmp;
	char		*resolution_y_tmp;
	int			i;
	int			rec;
	int			error_value;
}				t_resolution_tmp;

void			get_data(int fd, t_game_info *game_info, t_screen *screen);

int8_t			get_data_resolution(char *line, int *width,
									int *height, int error_value);
int				counter_of_resolution_value(char *line, char togle);
int				correct_resolution_value(char *line);
int				get_data_resolution_allocation(t_resolution_tmp *res_tmp,
														char *line);
void			get_data_resolution_free(t_resolution_tmp *res_tmp);

int8_t			get_data_color(char *line, t_color *rgb);

int8_t			get_map(char fd, t_game_info *game_info, t_map *map);
int				get_only_flags_and_spaces(int c, char *line);
int				get_number_sprites(char *line);
int				check_valid_player(char *temp_map);
int8_t			check_valid_map(t_player player);
void			check_arguments(int fd, int ac, char **av);

void			engine(t_game_info game_info, t_screen screen, char *save);

void			exit_with_error(int8_t error_nbr);
void			close_game(t_cub cub);

int				keys(int key, t_cub *cub);
void			raycasting(t_cub *cub, t_player player, t_screen screen);

t_player		player_init(t_game_info *game_info);
t_cub			cub_init(t_screen screen, t_player player,
														t_game_info *game_info);

void			change_position(int key, t_player *player);
void			change_pov(int key, t_player *player);

int8_t			compare_pov(t_player player, float pov, float look);
int8_t			compare_position(t_player player, float x, float y);

float			drow(t_cub *cub, float ray_angle, int wall_x);
void			drow_floor(t_cub *cub, int height, int wall_x);
void			drow_wall(t_cub *cub, int wall_y, int height, int wall_x);
void			drow_ceiling(t_cub *cub, int height, int wall_x);
void			drow_sprites(t_game_info game_info, t_player player,
											t_screen screen, float *distances);

float			fix_angle(float angle);
int				check_transparency(t_img_data texture, int index);

void			put_pixel(t_img_data img, int index, t_color color);
void			put_pixel_img(t_img_data img, t_img_data texture, int index,
															int index_texture);

float			get_texture_coordinate(float current_x);
float			get_distance(float x, float y);
void			get_wall_texture(t_cub *cub, float ray_angle,
						float distance_to_wall_h, float distance_to_wall_v);

float			calculate_height(float distance_to_wall, t_screen screen);
void			calculate_offset(t_sprite *sprite, t_screen screen, float angle,
															t_player player);
float			calculate_direction_sprite(t_sprite sprite, t_player player,
																	float pov);
t_distance		calculate_distance_to_wall(t_cub *cub, float ray_angle);
t_distance		calculate_distance_to_wall_v(t_player player, float ray_angle);
t_distance		calculate_distance_to_wall_h(t_player player, float ray_angle);

#endif
