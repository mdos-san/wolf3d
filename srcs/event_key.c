/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:31:19 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/18 14:04:03 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_press(int keycode, t_env *env)
{
	(keycode == 13) ? (env->player.movement_y = 1) : 0;
	(keycode == 1) ? (env->player.movement_y = 2) : 0;
	(keycode == 0) ? (env->player.movement_x = 3) : 0;
	(keycode == 2) ? (env->player.movement_x = 4) : 0;
	(keycode == 53) ? wolf3d_exit(&env, "Esc key pressed, good bye ! :D") : 0;
	return (1);
}

int		key_rl(int keycode, t_env *env)
{
	(keycode == 13) ? (env->player.movement_y = 0) : 0;
	(keycode == 1) ? (env->player.movement_y = 0) : 0;
	(keycode == 0) ? (env->player.movement_x = 0) : 0;
	(keycode == 2) ? (env->player.movement_x = 0) : 0;
	return (1);
}

void	event_key(t_env *env)
{
	mlx_hook(env->win, KEYPRESS, KEYPRESSMASK, key_press, env);
	mlx_key_hook(env->win, key_rl, env);
}
