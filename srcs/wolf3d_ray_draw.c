/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_ray_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 11:19:21 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/02 15:58:40 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		wolf3d_ray_draw(t_env *env, t_2d_ray *ray, unsigned int color,
		char draw)
{
	t_2d_pnt	a;
	int			i;

	a = ray->o;
	i = 1;
	while (env->map.map[(int)(a.y / BLOCK)][(int)(a.x / BLOCK)] != '1')
	{
		a.x += ray->dir.x;
		a.y += ray->dir.y;
	}
	while (i <= 42)
	{
		if (env->map.map[(int)(a.y / BLOCK)][(int)(a.x / BLOCK)] == '1')
		{
			a.x -= (double)ray->dir.x / ((double)2 * (double)i);
			a.y -= (double)ray->dir.y / ((double)2 * (double)i);
		}
		else
		{
			a.x += (double)ray->dir.x / ((double)2 * (double)i);
			a.y += (double)ray->dir.y / ((double)2 * (double)i);
		}
		++i;
	}
	ray->inter = a;
	if (draw)
		img_putline(env, ray->o, ray->inter, color);
	*env->dist = (sqrt(pow(ray->inter.x - ray->o.x, 2) + pow(ray->inter.y - ray->o.y, 2)));
}
