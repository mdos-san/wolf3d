/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 08:08:33 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/17 16:31:34 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	render_texture(t_env *env, int col, double down, double nb_pixel)
{
	double	i;
	int		nb_texture;
	double	percent_width;
	int		col_t;

	i = 0;
	nb_texture = env->map.map[(int)(env->ray.inter.y / BLOCK)][(int)(env->ray.inter.x / BLOCK)] - 48 - 1;
	percent_width = (env->ray.col == 1) ?
		(int)(env->ray.inter.y / BLOCK) - env->ray.inter.y / BLOCK :
		(int)(env->ray.inter.x / BLOCK) - env->ray.inter.x / BLOCK;
	col_t = fabs(env->textures[nb_texture].width * percent_width);
	while (down - i > HEIGHT)
		++i;
	while (i < nb_pixel && down - i > 0)
	{
		img_putpixel(env, col, (int)down - i,
			*(unsigned int*)(env->textures[nb_texture].data +
			col_t * env->textures[nb_texture].bpp +
			(int)(env->textures[nb_texture].height - 1 - i *
			env->textures[nb_texture].height / nb_pixel ) *
			env->textures[nb_texture].sl));
		++i;
	}
}

void	wolf3d_render(t_env *env, int col, unsigned int color)
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
