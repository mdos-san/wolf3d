/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:31:19 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/28 13:31:47 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_press(int keycode, t_env *env)
{
	(keycode == 13 || keycode == 119 || keycode == 65362) ?
		(env->player.movement_y = -1) : 0;
	(keycode == 1 || keycode == 115 || keycode == 65364) ?
		(env->player.movement_y = 1) : 0;
	(keycode == 0 || keycode == 97) ? (env->player.movement_x = -1) : 0;
	(keycode == 2 || keycode == 100) ? (env->player.movement_x = 1) : 0;
	(keycode == 123 || keycode == 65361) ? (env->player.view_move = 1) : 0;
	(keycode == 124 || keycode == 65363) ? (env->player.view_move = -1) : 0;
	(keycode == 15) ? wolf3d_player_init(env) : 0;
	(keycode == 53 || keycode == 65307) ?
		wolf3d_exit(&env, "Esc key pressed, good bye ! :D") : 0;
	return (1);
}

int		key_rl(int keycode, t_env *env)
{
	(keycode == 13 || keycode == 119 || keycode == 65362) ?
		(env->player.movement_y = 0) : 0;
	(keycode == 1 || keycode == 115 || keycode == 65364) ?
		(env->player.movement_y = 0) : 0;
	(keycode == 0 || keycode == 97) ? (env->player.movement_x = 0) : 0;
	(keycode == 2 || keycode == 100) ? (env->player.movement_x = 0) : 0;
	(keycode == 123 || keycode == 65361) ? (env->player.view_move = 0) : 0;
	(keycode == 124 || keycode == 65363) ? (env->player.view_move = 0) : 0;
	if (keycode == 46 || keycode == 109)
		env->ev_draw_map = (env->ev_draw_map == 0) ? 1 : 0;
	if (keycode == 122 || keycode == 65470)
		env->ev_color = (env->ev_color == 0) ? 1 : 0;
	if (keycode == 120 || keycode == 65471)
		env->ev_textures = (env->ev_textures == 0) ? 1 : 0;
	return (1);
}

void	event_key(t_env *env)
{
	mlx_hook(env->win, KEYPRESS, KEYPRESSMASK, key_press, env);
	mlx_key_hook(env->win, key_rl, env);
}
