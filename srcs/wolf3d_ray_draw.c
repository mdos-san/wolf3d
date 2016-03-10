/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_ray_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 11:19:21 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/10 10:47:25 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** y = m * x + p
** x = (y - p) / m
**
**
** m = (diff_y) / (diff_x)
** m = (vec_y) / (vec_x)
**
** p = y - m * x
**
** exeption when diff_x = 0, line is vertical
**
*/

static double	get_dist(t_2d_pnt a, t_2d_pnt b)
{
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

static double	next_x(t_2d_pnt pnt, char dir)
{
	if (dir == -1)
	{
		pnt.x /= BLOCK;
		pnt.x = (int)pnt.x;
		pnt.x *= BLOCK;
		if ((int)pnt.x == 0)
			return (0);
		return ((int)pnt.x - 0.0001);
	}
	if (dir == 1)
	{
		pnt.x /= BLOCK;
		pnt.x = (int)pnt.x;
		pnt.x *= BLOCK;
		return ((int)pnt.x + BLOCK);
	}
	return (0);
}

static double	next_y(t_2d_pnt pnt, char dir)
{
	if (dir == -1)
	{
		pnt.y /= BLOCK;
		pnt.y = (int)pnt.y;
		pnt.y *= BLOCK;
		if ((int)pnt.y == 0)
			return (0);
		return ((int)pnt.y - 0.0001);
	}
	if (dir == 1)
	{
		pnt.y /= BLOCK;
		pnt.y = (int)pnt.y;
		pnt.y *= BLOCK;
		return ((int)pnt.y + BLOCK);
	}
	return (0);
}

void			wolf3d_ray_draw(t_env *env, t_2d_ray *ray, unsigned int color,
		char draw)
{
	t_2d_pnt	pnt;
	t_2d_pnt	pnt2;
	double	m;
	double	p;
	char	exeption;
	char	condition;

	pnt = ray->o;
	pnt2 = ray->o;
	condition = 0;
	exeption = 0;
	m = 0;
	if (ray->dir.x != 0)
		m = (ray->dir.y) / (ray->dir.x);
	else
		exeption = 1;
	p = ray->o.y - m * ray->o.x;
	if (exeption == 0)
	{
		while (!condition)
		{
			pnt.x = (ray->dir.x > 0) ? next_x(pnt, 1) : next_x(pnt, -1);
			pnt.y = m * pnt.x + p;
//			printf("pnt x %lf, y %lf, m %lf\n", pnt.x, pnt.y, m);
			if (0 <= pnt.y && pnt.y < env->map.size_y && (0 <= pnt.x && pnt.x <= ft_strlen(env->map.map[(int)(pnt.y / BLOCK)]) * BLOCK))
			{
				if(wolf3d_map_is_wall(env, pnt))
				{
//					printf("pnt x %lf, y %lf, m %lf\n", pnt.x, pnt.y, m);
//					img_putline(env, ray->o, pnt, 0xfffffff);
					condition++;
				}
			}
			pnt2.y = (ray->dir.y > 0) ? next_y(pnt2, 1) : next_y(pnt2, -1);
			pnt2.x = (pnt2.y - p) / m;
//			printf("pnt2 x %lf, y %lf, m %lf\n", pnt2.x, pnt2.y, m);
			if (0 <= pnt2.y && pnt2.y < env->map.size_y && (0 <= pnt2.x && pnt2.x <= ft_strlen(env->map.map[(int)(pnt2.y / BLOCK)]) * BLOCK))
			{
				if(wolf3d_map_is_wall(env, pnt2))
				{
//					printf("pnt2 x %lf, y %lf, m %lf\n", pnt2.x, pnt2.y, m);
//					img_putline(env, ray->o, pnt2, 0xfffff);
					condition++;
				}
			}
//			condition++;
		}
		pnt = (get_dist(ray->o, pnt) < get_dist(ray->o, pnt2)) ? pnt : pnt2;
		img_putline(env, ray->o, pnt, 0xff00ff);
	}
	(void)env;
	(void)ray;
	(void)draw;
	(void)color;
}
