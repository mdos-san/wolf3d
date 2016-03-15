/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_ray_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 11:19:21 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/15 14:09:05 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	get_dist_x(t_env *env,
		t_2d_ray *ray, double *distx, double m, double p)
{
	t_2d_pnt	cursor;
	char		error;

	cursor = ray->o;
	error = 0;
	if (ray->dir.x > 0)
		cursor.x = (int)((int)(cursor.x / BLOCK) * BLOCK) + BLOCK;
	else
		cursor.x = (int)((int)(cursor.x / BLOCK) * BLOCK) - 0.00001;
	cursor.y = m * cursor.x + p;
	if (!(0 <= cursor.y && cursor.y < env->map.size_y && 0 <= cursor.x &&
		cursor.x < ft_strlen(env->map.map[(int)(cursor.y / BLOCK)]) * BLOCK))
		error = 1;
	while (error == 0 && !wolf3d_map_is_wall(env, cursor))
	{
		cursor.x += (ray->dir.x > 0) ? BLOCK : -BLOCK;
		cursor.y = m * cursor.x + p;
		if ((0 <= cursor.y && cursor.y < env->map.size_y && 0 <= cursor.x &&
		cursor.x < ft_strlen(env->map.map[(int)(cursor.y / BLOCK)]) * BLOCK))
			error = 0;
		else
			error = 1;
	}
	if (error == 0)
	{
		*distx =
			sqrt(pow(cursor.x - ray->o.x, 2) + pow(cursor.y - ray->o.y, 2));
		ray->inter = cursor;
		env->dist = *distx;
		if (env->ev_color == 1)
			env->color =
			env->map.color[(int)(cursor.y / BLOCK)][(int)(cursor.x / BLOCK)];
		else if (ray->dir.x > 0)
			env->color = color_get(255, 0, 0, 0);
		else
			env->color = color_get(0, 255, 0, 0);
	}
	else
		*distx = -1;
}

static void	get_dist_y(t_env *env, t_2d_ray *ray,
						double *disty, double m, double p)
{
	t_2d_pnt	cursor;
	char		error;

	cursor = ray->o;
	error = 0;
	if (ray->dir.y > 0)
		cursor.y = (int)((int)(cursor.y / BLOCK) * BLOCK) + BLOCK;
	else
		cursor.y = (int)((int)(cursor.y / BLOCK) * BLOCK) - 0.00001;
	cursor.x = (cursor.y - p) / m;
	if (!(0 <= cursor.y && cursor.y < env->map.size_y && 0 <= cursor.x &&
		cursor.x < ft_strlen(env->map.map[(int)(cursor.y / BLOCK)]) * BLOCK))
		error = 1;
	while (error == 0 && !wolf3d_map_is_wall(env, cursor))
	{
		cursor.y += (ray->dir.y > 0) ? BLOCK : -BLOCK;
		cursor.x = (cursor.y - p) / m;
		if ((0 <= cursor.y && cursor.y < env->map.size_y && 0 <= cursor.x &&
		cursor.x < ft_strlen(env->map.map[(int)(cursor.y / BLOCK)]) * BLOCK))
			error = 0;
		else
			error = 1;
	}
	if (error == 0)
	{
		*disty =
			sqrt(pow(cursor.x - ray->o.x, 2) + pow(cursor.y - ray->o.y, 2));
		if (ray->inter.x == -1 || (*disty < env->dist))
		{
			ray->inter = cursor;
			if (env->ev_color == 1)
				env->color =
			env->map.color[(int)(cursor.y / BLOCK)][(int)(cursor.x / BLOCK)];
			else if (ray->dir.y > 0)
				env->color = color_get(0, 0, 255, 0);
			else
				env->color = color_get(255, 255, 0, 0);
			env->dist = *disty;
		}
	}
	else
		*disty = -1;
}

static void	exeption_x(t_env *env, t_2d_ray *ray)
{
	t_2d_pnt	cursor;

	cursor = ray->o;
	if (ray->dir.y > 0)
		cursor.y = (int)((int)(cursor.y / BLOCK) * BLOCK) + BLOCK;
	else
		cursor.y = (int)((int)(cursor.y / BLOCK) * BLOCK) - 0.00001;
	while (!wolf3d_map_is_wall(env, cursor))
		cursor.y += (ray->dir.y > 0) ? BLOCK : -BLOCK;
	env->dist =
		sqrt(pow(ray->o.x - cursor.x, 2) + pow(ray->o.y - cursor.y, 2));
	if (env->ev_color == 1)
		env->color =
			env->map.color[(int)(cursor.y / BLOCK)][(int)(cursor.x / BLOCK)];
	else if (ray->dir.y > 0)
		env->color = color_get(0, 0, 255, 0);
	else
		env->color = color_get(255, 255, 0, 0);
}

static void	exeption_y(t_env *env, t_2d_ray *ray)
{
	t_2d_pnt	cursor;

	cursor = ray->o;
	if (ray->dir.x > 0)
		cursor.x = (int)((int)(cursor.x / BLOCK) * BLOCK) + BLOCK;
	else
		cursor.x = (int)((int)(cursor.x / BLOCK) * BLOCK) - 0.00001;
	while (!wolf3d_map_is_wall(env, cursor))
		cursor.x += (ray->dir.x > 0) ? BLOCK : -BLOCK;
	env->dist =
		sqrt(pow(ray->o.x - cursor.x, 2) + pow(ray->o.y - cursor.y, 2));
	if (env->ev_color == 1)
		env->color =
			env->map.color[(int)(cursor.y / BLOCK)][(int)(cursor.x / BLOCK)];
	else if (ray->dir.x > 0)
		env->color = color_get(255, 0, 0, 0);
	else
		env->color = color_get(0, 255, 0, 0);
}

void		wolf3d_ray_draw(t_env *env, t_2d_ray *ray, unsigned int color,
		char draw)
{
	double	m;
	double	p;
	double	distx;
	double	disty;

	ray->inter.x = -1;
	if (ray->dir.x != 0 && ray->dir.y != 0)
	{
		m = (ray->dir.y) / (ray->dir.x);
		p = ray->o.y - m * ray->o.x;
		get_dist_x(env, ray, &distx, m, p);
		get_dist_y(env, ray, &disty, m, p);
		if (draw == 1)
			img_putline(env, ray->o, ray->inter, color);
	}
	else if (ray->dir.x == 0)
		exeption_x(env, ray);
	else if (ray->dir.y == 0)
		exeption_y(env, ray);
}
