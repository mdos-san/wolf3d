/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_expose.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:50:05 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/07 04:17:10 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	hook_expose(t_env *env)
{
	int	i;
	int	nbr;
	double	new_x;
	double	new_y;

	i = 0;
	nbr = WIDTH / 2;
	img_clear(env);
	env->ray.o = env->player.pos;
	while (i < nbr)
	{
		new_x = env->player.view_dir.x / nbr * i;
		new_y = env->player.view_dir.y / nbr * i;
		env->ray.dir = (t_2d_vec){env->player.view_dir.x + new_y, env->player.view_dir.y - new_x};
		wolf3d_ray_draw(env, &env->ray, 0xffffff, 0);
//		*env->dist *= cos((env->ray.dir.x * env->player.view_dir.x + env->ray.dir.y * env->player.view_dir.y)
//		/ ((sqrt(pow(env->ray.dir.x, 2) + pow(env->ray.dir.y, 2))) * (sqrt(pow(env->player.view_dir.x, 2) + pow(env->player.view_dir.y, 2)))));
		*env->dist *= (env->ray.dir.x * env->player.view_dir.x + env->ray.dir.y * env->player.view_dir.y)
		/ ((sqrt(pow(env->ray.dir.x, 2) + pow(env->ray.dir.y, 2))) * (sqrt(pow(env->player.view_dir.x, 2) + pow(env->player.view_dir.y, 2))));
		env->color->r = (env->color->r / *env->dist * LUM > 255) ? 255 : env->color->r / *env->dist * LUM;
		env->color->g = (env->color->g / *env->dist * LUM > 255) ? 255 : env->color->g / *env->dist * LUM;
		env->color->b = (env->color->b / *env->dist * LUM > 255) ? 255 : env->color->b / *env->dist * LUM;
		wolf3d_render(env, WIDTH / 2 - i, color_convert(*env->color));
		env->ray.dir = (t_2d_vec){env->player.view_dir.x - new_y, env->player.view_dir.y + new_x};
		wolf3d_ray_draw(env, &env->ray, 0xffffff, 0);
		*env->dist *= (env->ray.dir.x * env->player.view_dir.x + env->ray.dir.y * env->player.view_dir.y)
		/ ((sqrt(pow(env->ray.dir.x, 2) + pow(env->ray.dir.y, 2))) * (sqrt(pow(env->player.view_dir.x, 2) + pow(env->player.view_dir.y, 2))));
		env->color->r = (env->color->r / *env->dist * LUM > 255) ? 255 : env->color->r / *env->dist * LUM;
		env->color->g = (env->color->g / *env->dist * LUM > 255) ? 255 : env->color->g / *env->dist * LUM;
		env->color->b = (env->color->b / *env->dist * LUM > 255) ? 255 : env->color->b / *env->dist * LUM;
		wolf3d_render(env, WIDTH / 2 + i, color_convert(*env->color));
		++i;
	}
	
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (1);
}
