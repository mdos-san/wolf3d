/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 10:55:58 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/18 13:52:50 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf3d_start(t_env *env)
{
	wolf3d_map_draw(env);
	wolf3d_player_draw(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	event_key(env);
	mlx_expose_hook(env->win, hook_expose, env);
	mlx_loop_hook(env->mlx, hook_loop, env);
	mlx_loop(env->mlx);
}
