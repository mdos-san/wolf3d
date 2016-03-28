/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 08:03:38 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/17 23:11:33 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	init_texture(t_env *env)
{
	textures_load(env, 0, "textures/wall0.xpm");
	textures_load(env, 1, "textures/wall1.xpm");
	textures_load(env, 2, "textures/wall2.xpm");
	textures_load(env, 3, "textures/wall3.xpm");
	textures_load(env, 4, "textures/wall4.xpm");
	textures_load(env, 5, "textures/wall5.xpm");
	textures_load(env, 6, "textures/wall6.xpm");
	textures_load(env, 7, "textures/wall7.xpm");
	textures_load(env, 8, "textures/wall8.xpm");
	env->ev_textures = 0;
	env->frame = 0;
	env->ev_frame = 0;
	return (1);
}

t_env		*wolf3d_init(int ac, char **av)
{
	t_env *env;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		wolf3d_exit(&env, "wolf3d_init: malloc");
	env->color = color_get(255, 255, 255, 0);
	env->dist = 0;
	env->ac = ac;
	env->av = av;
	env->ray.dir.x = 0;
	env->ray.dir.x = 0;
	env->ray.inter.x = 0;
	env->ray.inter.x = 0;
	env->ev_draw_map = 0;
	env->ev_color = 0;
	wolf3d_map_load(env);
	wolf3d_player_init(env);
	if (((env)->mlx = mlx_init()) == NULL)
		wolf3d_exit(&env, "wolf3d_init: mlx_init");
	if ((env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, TITLE)) == NULL)
		wolf3d_exit(&env, "wolf3d_init: mlx_new_window");
	(env)->img = NULL;
	img_clear(env);
	init_texture(env);
	return (env);
}
