/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 08:03:38 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/02 14:44:27 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_env	*wolf3d_init(int ac, char **av)
{
	t_env *env;

	ft_putnbrl(sizeof(t_env));
	if (!(env = (t_env*)malloc(sizeof(t_env))))
		wolf3d_exit(&env, "wolf3d_init: malloc");
	env->i = 0;
	env->dist = (double*)malloc(sizeof(double));
	env->ac = ac;
	env->av = av;
	env->ray.o.x = 0;
	env->ray.o.x = 0;
	env->ray.dir.x = 0;
	env->ray.dir.x = 0;
	env->ray.inter.x = 0;
	env->ray.inter.x = 0;
	wolf3d_map_load(env);
	wolf3d_player_init(env);
	if (((env)->mlx = mlx_init()) == NULL)
		wolf3d_exit(&env, "wolf3d_init: mlx_init");
	if ((env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, TITLE)) == NULL)
		wolf3d_exit(&env, "wolf3d_init: mlx_new_window");
	(env)->img = NULL;
	img_clear(env);
	return (env);
}
