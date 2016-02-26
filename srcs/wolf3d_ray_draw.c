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

void		wolf3d_ray_draw(t_env *env, t_2d_ray *ray, unsigned int color,
																	char draw)
{
	t_2d_pnt	a;
	char		done;
	double		m;
	double		p;

	(void)draw;
	(void)color;
	done = 0;
	a = ray->o;
	m = ray->dir.y / ray->dir.x;
	p = a.y - m * a.x;
//	ft_putendl("debug1");
	while (done == 0)
	{
//		printf("a.x %lf, a.y %lf\n", a.x, a.y);
		if (env->map.map[(int)(a.y / BLOCK)][(int)((a.x + ray->dir.x) / BLOCK)] == '1')
			done = 1;
		else if (env->map.map[(int)((a.y + ray->dir.y) / BLOCK)][(int)(a.x / BLOCK)] == '1')
			done = 2;
		else
		{
			a.x += ray->dir.x;
			a.y += ray->dir.y;
		}
	}
	if (done == 1)
	{
		a.x = (a.x < a.x + ray->dir.x) ? (int)a.x + 1 : (int)a.x;
		a.y = (ray->dir.x != 0) ? m * a.x + p : a.y;
	}
	if (done == 2)
	{
		a.y = (a.y < a.y + ray->dir.y) ? (int)a.y + 1 : (int)a.y;
		a.x = (ray->dir.x != 0) ? (a.y - p) / m : a.x;
	}
	ray->inter = a;
	ft_putendl("1");
	*env->dist = (sqrt(pow(a.x - ray->o.x, 2) + pow(a.y - ray->o.y, 2)));
	ft_putendl("2");
}
