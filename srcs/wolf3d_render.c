/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 08:08:33 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/28 13:58:29 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	init_texture(t_env *env, int *nb_texture)
{
	*nb_texture = env->map.map[(int)(env->ray.inter.y / BLOCK)]
								[(int)(env->ray.inter.x / BLOCK)] - 48 - 1;
	if (*nb_texture == 8)
	{
		env->ev_frame = 1;
		*nb_texture = env->frame;
	}
}

static void	render_texture(t_env *env, int col, double down, double nb_pixel)
{
	int		nb_texture;
	double	percent_width;
	int		col_t;
	double	x;
	double	y;

	env->i = 0;
	init_texture(env, &nb_texture);
	percent_width = (env->ray.col == 1) ?
		(int)(env->ray.inter.y / BLOCK) - env->ray.inter.y / BLOCK :
		(int)(env->ray.inter.x / BLOCK) - env->ray.inter.x / BLOCK;
	col_t = fabs(env->textures[nb_texture].width * percent_width);
	while (down - env->i > HEIGHT)
		++env->i;
	x = col_t * env->textures[nb_texture].bpp;
	y = (double)env->textures[nb_texture].height / nb_pixel;
	while (env->i < nb_pixel && env->i < down)
	{
		img_putpixel(env, col, (int)down - env->i,
			*(unsigned int*)(env->textures[nb_texture].data +
			(int)x + (int)(env->textures[nb_texture].height - 1 - env->i * y) *
			env->textures[nb_texture].sl));
		++env->i;
	}
}

void		wolf3d_render(t_env *env, int col, unsigned int color)
{
	double	up;
	double	down;
	double	nb_pixel;

	if (env->dist != 0)
	{
		up = (HEIGHT / 2) - HEIGHT * 4 / env->dist;
		down = (HEIGHT / 2) + HEIGHT * 4 / env->dist;
		nb_pixel = down - up;
		if (env->ev_textures == 0)
		{
			(up <= 0) ? (up = -1) : 0;
			(down > HEIGHT) ? (down = HEIGHT) : 0;
			img_putline(env,
					(t_2d_pnt){col, HEIGHT / 2}, (t_2d_pnt){col, up}, color);
			img_putline(env,
					(t_2d_pnt){col, HEIGHT / 2}, (t_2d_pnt){col, down}, color);
		}
		else
			render_texture(env, col, down, nb_pixel);
	}
}
