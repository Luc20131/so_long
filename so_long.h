/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:42:35 by lrichaud          #+#    #+#             */
/*   Updated: 2024/03/13 06:08:01 by lrichaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <string.h>
# include <errno.h>
# define FT_PI 3.14159
# define TILE_SIZE 64

typedef struct s_content
{
	int	coins;
	int	exit;
	int	carac;
}	t_content;

typedef struct s_pos
{
	size_t	x;
	size_t	y;
}	t_pos;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		h;
	int		w;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		h;
	int		w;
	char	***map;
	t_data	tile[24];
	size_t	link_side;
}	t_vars;

char			***map_tester(char	*map_path);
int				wall_checker(int fd, int *nb_line, t_content *content);
char			***map_initializer(int fd, int nb_line);
int				path_finder(char ***map);
void			free_map(char ***map);
void			print_map(char ***map, size_t layer);
t_pos			carac_finder(t_pos pos_carac, char ***map);
char			***map_refresher(t_vars *v);
int				random_tree(int y, int x);
int				wall_selector(char ***map, int y, int x);
t_data			new_img(char *path, t_vars *v);
void			img_map_initializer(t_vars *v, char ***map);
int				tile_selector(char ***map, int y, int x);
int				pseudo_random_percent(int y, int x);
void			print_content(t_vars *v, int t_x, int t_y);
int				is_big_tree(int tile_x, int tile_y, char ***map);
int				move_down(char ***map, size_t *side);
int				move_right(char ***map, size_t *side);
int				move_up(char ***map, size_t *side);
int				move_left(char ***map, size_t *side);
void			put_pixel_img(t_data img, int x, int y, int color);
t_pos			size_map(char ***map);
unsigned int	get_pixel_img(t_data img, int x, int y);
void			ft_close(t_vars *vars);
void			images_for_map(t_vars *v);
void			images_for_link(t_vars *v);
void			stepper(void);
void			map_formating(char ***map, size_t i, size_t y);
int				closer(t_vars *v);
int				checker_images(t_vars *v);

#endif
