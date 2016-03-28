/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_expose.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:50:05 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/28 14:06:10 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	get_color(t_env *env)
{
	env->color.r = ((double)env->color.r / env->dist * LUM > 255)
		? 255 : (double)env->color.r / env->dist * LUM;
	env->color.g = ((double)env->color.g / env->dist * LUM > 255)
		? 255 : (double)env->color.g / env->dist * LUM;
	env->color.b = ((double)env->color.b / env->dist * LUM > 255)
		? 255 : (double)env->color.b / env->dist * LUM;
}

static void	get_dist(t_env *env)
{
	env->dist *= (env->ray.dir.x * env->player.view_dir.x
	+ env->ray.dir.y * env->player.view_dir.y)
	/ ((sqrt(pow(env->ray.dir.x, 2) + pow(env->ray.dir.y, 2))) *
	sqrt(pow(env->player.view_dir.x, 2) + pow(env->player.view_dir.y, 2)));
}

static void	ray_send(t_env *env)
{
	wolf3d_ray_draw(env, &env->ray, 0xffffff, 0);
	get_dist(env);
	get_color(env);
}

static void	render(t_env *env, double new_x, double new_y, int i)
{
	env->ray.dir = (t_2d_vec)
		{env->player.view_dir.x + new_y, env->player.view_dir.y - new_x};
	ray_send(env);
	wolf3d_render(env, WIDTH / 2 - i, color_convert(env->color));
	env->ray.dir = (t_2d_vec)
		{env->player.view_dir.x - new_y, env->player.view_dir.y + new_x};
	ray_send(env);
	wolf3d_render(env, WIDTH / 2 + i, color_convert(env->color));
}

int			hook_expose(t_env *env)
{
	int		i;
	int		nbr;
	double	new_x;
	double	new_y;

	i = -1;
	nbr = WIDTH / 2;
	img_clear(env);
	env->ray.o = env->player.pos;
	img_fill_up(env, color_convert(color_get(0, 100, 255, 0)));
	img_fill_down(env, color_get(100, 100, 100, 0));
	while (++i < nbr + 1)
	{
		new_x = env->player.view_dir.x / nbr * i;
		new_y = env->player.view_dir.y / nbr * i;
		render(env, new_x, new_y, i);
	}
	if (env->ev_frame == 1)
		env->frame = (env->frame >= 8) ? 0 : env->frame + 0.3;
	env->ev_frame = 0;
	(env->ev_draw_map == 1) ? wolf3d_map_draw(env) : 0;
	(env->ev_draw_map == 1) ? wolf3d_player_draw(env) : 0;
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (1);
}
