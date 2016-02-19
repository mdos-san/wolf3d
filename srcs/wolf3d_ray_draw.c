/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_ray_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 11:19:21 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/19 12:25:56 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	exeption(t_env *env, t_2d_pnt a, t_2d_pnt b)
{
	double coef;

	a = env->ray.o;
	coef = (b.x - a.x) / (b.y - a.y);
	while (env->map.map[(int)(a.y / BLOCK)][(int)(a.x / BLOCK)] == '0' || env->map.map[(int)(a.y / BLOCK)][(int)(a.x / BLOCK)] == '#')
	{
		(a.y < b.y) ? (a.x += coef) : (a.x -= coef);
		(a.y < b.y) ? (++a.y) : (--a.y);
	}
	env->ray.inter = a;
}

void		wolf3d_ray_draw(t_env *env, t_2d_ray *ray, unsigned int color)
{
	t_2d_pnt	a;
	t_2d_pnt	b;
	double	coef;

	a = ray->o;
	b = (t_2d_pnt){(a.x + ray->dir.x * 2000), (a.y + ray->dir.y * 2000)};
	coef = (b.y - a.y) / (b.x - a.x);
	if (-1 <= coef && coef <= 1)
	{
		while (env->map.map[(int)(a.y / BLOCK)][(int)(a.x / BLOCK)] == '0' || env->map.map[(int)(a.y / BLOCK)][(int)(a.x / BLOCK)] == '#')
		{
			(a.x < b.x) ? (a.y += coef) : (a.y -= coef);
			(a.x < b.x) ? (++a.x) : (--a.x);
		}
		ray->inter = a;
	}
	else
		exeption(env, a, b);
	img_putline(env,
	(t_2d_pnt){env->player.pos.x, env->player.pos.y},
	(t_2d_pnt){ray->inter.x, ray->inter.y},
	color);
}
