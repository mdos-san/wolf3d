/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 08:03:38 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/18 15:19:00 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf3d_init(t_env *env)
{
	wolf3d_map_load(env);
	wolf3d_player_init(env);
	if ((env->mlx = mlx_init()) == NULL)
		wolf3d_exit(&env, "wolf3d_init: mlx_init");
	if ((env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, TITLE)) == NULL)
		wolf3d_exit(&env, "wolf3d_init: mlx_new_window");
	env->img = NULL;
	img_clear(env);
}
