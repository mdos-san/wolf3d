/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 07:12:02 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/18 11:29:39 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include "libft.h"
# define WIDTH 1920
# define HEIGHT 1080

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
	int			i;
}				t_env;

void			wolf3d_init(t_env *env);
void			wolf3d_exit(t_env **env, char *str);
void			wolf3d_start(t_env *env);
void			wolf3d_map_load(t_env *env);
void			wolf3d_map_del(char ***addr);
void			wolf3d_draw_map(t_env *env);
void			img_putpixel(t_env *env, int x, int y, int color);
void			img_clear(t_env *env);

#endif
