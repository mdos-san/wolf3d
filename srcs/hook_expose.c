/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_expose.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:50:05 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/07 00:54:52 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	hook_expose(t_env *env)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = WIDTH / 2;
	img_clear(env);
	env->ray.o = env->player.pos;
	while (i < nbr)
	{
		env->ray.dir = (t_2d_vec){env->player.view_dir.x + (env->player.view_dir.y / nbr * i), env->player.view_dir.y - env->player.view_dir.x / nbr * i};
		wolf3d_ray_draw(env, &env->ray, 0xffffff, 0);
		wolf3d_render(env, WIDTH / 2 - i, color_convert(*env->color));
		env->ray.dir = (t_2d_vec){env->player.view_dir.x - env->player.view_dir.y / nbr * i, env->player.view_dir.y + env->player.view_dir.x / nbr * i};
		wolf3d_ray_draw(env, &env->ray, 0xffffff, 0);
		wolf3d_render(env, WIDTH / 2 + i, color_convert(*env->color));
		++i;
	}
	
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (1);
}
