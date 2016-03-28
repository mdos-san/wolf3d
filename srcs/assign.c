/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 14:46:32 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/28 15:11:00 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	assign_y(t_env *env, t_2d_ray *ray, double *disty, t_2d_pnt cursor)
{
	*disty =
		sqrt(pow(cursor.x - ray->o.x, 2) + pow(cursor.y - ray->o.y, 2));
	if (ray->inter.x == -1 || (*disty <= env->dist))
	{
		ray->inter = cursor;
		ray->col = 2;
		if (env->ev_color == 1)
			env->color =
				env->map.color[(int)(cursor.y / BLOCK)]
								[(int)(cursor.x / BLOCK)];
		else if (ray->dir.y > 0)
			env->color = color_get(0, 0, 255, 0);
		else
			env->color = color_get(255, 255, 0, 0);
		env->dist = *disty;
	}
}

void	assign_x(t_env *env, t_2d_ray *ray, double *distx, t_2d_pnt cursor)
{
	*distx =
		sqrt(pow(cursor.x - ray->o.x, 2) + pow(cursor.y - ray->o.y, 2));
	ray->inter = cursor;
	ray->col = 1;
	env->dist = *distx;
	if (env->ev_color == 1)
		env->color =
			env->map.color[(int)(cursor.y / BLOCK)][(int)(cursor.x / BLOCK)];
	else if (ray->dir.x > 0)
		env->color = color_get(255, 165, 0, 0);
	else
		env->color = color_get(0, 255, 0, 0);
}
