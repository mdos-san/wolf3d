/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 07:12:02 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/18 08:12:08 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <stdlib.h>
# include "libft.h"

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
	void		*mlx;
	void		*win;
	void		*img;
	int			bpp;
	int			sl;
	int			ed;
	t_map		map;
	t_player	player;
}				t_env;

void			wolf3d_init(t_env *env);
void			wolf3d_exit(t_env **env, char *str);

#endif
