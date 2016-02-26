/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_ray_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 11:19:21 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/19 15:32:27 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void exeption(t_env *env, t_2d_pnt a, t_2d_pnt b)
{
	double coef;

	a	 = env->ray.o;
	coef = (b.x - a.x) / (b.y - a.y);
	while (env->map.map[(int)(a.y / BLOCK)][(int)(a.x / BLOCK)] == '0'
			|| env->map.map[(int)(a.y / BLOCK)][(int)(a.x / BLOCK)] == '#')
	{
		(a.y < b.y) ? (a.x += 0.1 * coef) : (a.x -= 0.1 * coef);
		a.y = (a.y < b.y) ? (a.y + 0.1) : (a.y - 0.1);
	}
	env->ray.inter = a;
}

void		wolf3d_ray_draw(t_env *env, t_2d_ray *ray, unsigned int color,
		char draw)
{
	t_2d_pnt a;
	t_2d_pnt b;
	double coef;

	(void)draw;
	(void)color;
	a = ray->o;
	b = (t_2d_pnt){(a.x + ray->dir.x * 2000000), (a.y + ray->dir.y * 2000000)};
	coef = (b.y - a.y) / (b.x - a.x);
	if (-1 <= coef && coef <= 1)
	{
		while (env->map.map[(int)(a.y / BLOCK)][(int)(a.x / BLOCK)] == '0'
				|| env->map.map[(int)(a.y / BLOCK)][(int)(a.x / BLOCK)] == '#')
		{
			(a.x < b.x) ? (a.y += 0.1 * coef) : (a.y -= 0.1 * coef);
			a.x = (a.x < b.x) ? (a.x + 0.1) : (a.x - 0.1);
		}
		ray->inter = a;
	}
	else
		exeption(env, a, b);
	*env->dist = (sqrt(pow(ray->inter.x - ray->o.x, 2) + pow(ray->inter.y - ray->o.y, 2)));
}
