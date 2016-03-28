/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_ray_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 11:19:21 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/28 14:51:45 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	get_dist_x(t_env *env, t_2d_ray *ray, double *distx)
{
	t_2d_pnt	cursor;
	char		error;

	cursor = ray->o;
	error = 0;
	if (ray->dir.x > 0)
		cursor.x = (int)((int)(cursor.x / BLOCK) * BLOCK) + BLOCK;
	else
		cursor.x = (int)((int)(cursor.x / BLOCK) * BLOCK) - 0.00001;
	cursor.y = env->m * cursor.x + env->p;
	if (!(0 <= cursor.y && cursor.y < env->map.size_y && 0 <= cursor.x &&
		cursor.x < ft_strlen(env->map.map[(int)(cursor.y / BLOCK)]) * BLOCK))
		error = 1;
	while (error == 0 && !wolf3d_map_is_wall(env, cursor))
	{
		cursor.x += (ray->dir.x > 0) ? BLOCK : -BLOCK;
		cursor.y = env->m * cursor.x + env->p;
		if (!(0 <= cursor.y && cursor.y < env->map.size_y && 0 <= cursor.x &&
		cursor.x < ft_strlen(env->map.map[(int)(cursor.y / BLOCK)]) * BLOCK))
			error = -1;
	}
	if (error == 0)
		assign_x(env, ray, distx, cursor);
}

static void	get_dist_y(t_env *env, t_2d_ray *ray, double *disty)
{
	t_2d_pnt	cursor;
	char		error;

	cursor = ray->o;
	error = 0;
	if (ray->dir.y > 0)
		cursor.y = (int)((int)(cursor.y / BLOCK) * BLOCK) + BLOCK;
	else
		cursor.y = (int)((int)(cursor.y / BLOCK) * BLOCK) - 0.00001;
	cursor.x = (cursor.y - env->p) / env->m;
	if (!(0 <= cursor.y && cursor.y < env->map.size_y && 0 <= cursor.x &&
		cursor.x < ft_strlen(env->map.map[(int)(cursor.y / BLOCK)]) * BLOCK))
		error = 1;
	while (error == 0 && !wolf3d_map_is_wall(env, cursor))
	{
		cursor.y += (ray->dir.y > 0) ? BLOCK : -BLOCK;
		cursor.x = (cursor.y - env->p) / env->m;
		if (!(0 <= cursor.y && cursor.y < env->map.size_y && 0 <= cursor.x &&
		cursor.x < ft_strlen(env->map.map[(int)(cursor.y / BLOCK)]) * BLOCK))
			error = -1;
	}
	if (error == 0)
		assign_y(env, ray, disty, cursor);
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
	ray->col = 2;
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
	ray->col = 1;
}

void		wolf3d_ray_draw(t_env *env, t_2d_ray *ray, unsigned int color,
		char draw)
{
	double	distx;
	double	disty;

	ray->inter.x = -1;
	if (ray->dir.x != 0 && ray->dir.y != 0)
	{
		env->m = (ray->dir.y) / (ray->dir.x);
		env->p = ray->o.y - env->m * ray->o.x;
		get_dist_x(env, ray, &distx);
		get_dist_y(env, ray, &disty);
		if (draw == 1)
			img_putline(env, ray->o, ray->inter, color);
	}
	else if (ray->dir.x == 0)
		exeption_x(env, ray);
	else if (ray->dir.y == 0)
		exeption_y(env, ray);
}
