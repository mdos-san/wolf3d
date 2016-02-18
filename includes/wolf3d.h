/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 07:12:02 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/18 17:07:26 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include "libft.h"
# define KEYPRESS 2
# define KEYPRESSMASK (1L<<0)
# define WIDTH 1920
# define HEIGHT 1080
# define BLOCK 20
# define TITLE "WOLF3D"
# define PLAYER_SIZE 5

typedef struct	s_2d_pnt
{
	double	x;
	double	y;
}				t_2d_pnt;

typedef struct	s_2d_vec
{
	double	x;
	double	y;
}				t_2d_vec;

typedef struct	s_player
{
	t_2d_pnt	pos;
	t_2d_vec	view_dir;
	char		movement_x;
	char		movement_y;
	char		view_move;
}				t_player;

typedef struct	s_map
{
	char	**map;
}				t_map;

typedef struct	s_env
{
	int			ac;
	char		**av;
	int			fd;
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			sl;
	int			ed;
	t_map		map;
	t_player	player;
	int			player_size;
	int			i;
}				t_env;

void			wolf3d_init(t_env *env);
void			wolf3d_exit(t_env **env, char *str);
void			wolf3d_start(t_env *env);
void			wolf3d_map_load(t_env *env);
void			wolf3d_map_del(char ***addr);
void			wolf3d_map_draw(t_env *env);
int				wolf3d_player_init(t_env *env);
void			wolf3d_player_draw(t_env *env);
void			wolf3d_player_move(t_env *env, double x, double y);
void			img_putpixel(t_env *env, int x, int y, int color);
void			img_clear(t_env *env);
void			event_key(t_env *env);
int				hook_loop(t_env *env);
int				hook_expose(t_env *env);
void			vec_rotate_2d(t_2d_vec *vec, double angle);

#endif
