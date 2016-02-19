/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_ray_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 11:19:21 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/19 11:59:59 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	exeption(t_env *env, t_2d_pnt a, t_2d_pnt b)
{
	double coef;

	a = env->ray.o;
	coef = (b.x - a.x) / (b.y - a.y);
	while (env->map.map[(int)a.y][(int)a.x] == '0' || env->map.map[(int)a.y][(int)a.x] == '#')
	{
		if (a.y < b.y)
		{
			a.x += coef;
			a.y++;
		}
		else
		{
			a.x -= coef;
			a.y--;
		}
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
		while (env->map.map[(int)a.y][(int)a.x] == '0' || env->map.map[(int)a.y][(int)a.x] == '#')
		{
			(a.x < b.x) ? (a.y += coef) : (a.y -= coef);
			(a.x < b.x) ? (++a.x) : (--a.x);
		}
		ray->inter = a;
	}
	else
		exeption(env, a, b);
/*	ray->inter.x -= env->player.pos.x - (int)env->player.pos.x;
**	ray->inter.y -= env->player.pos.y - (int)env->player.pos.y;
*/	img_putline(env,
	(t_2d_pnt){env->player.pos.x * BLOCK, env->player.pos.y * BLOCK},
	(t_2d_pnt){ray->inter.x * BLOCK, ray->inter.y * BLOCK},
	color);
}
