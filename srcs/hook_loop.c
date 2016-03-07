/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_loop.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:45:46 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/07 08:06:33 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	hook_loop(t_env *env)
{
	(env->player.movement_y == -1) ? wolf3d_player_move
(env, SPEED * env->player.view_dir.x, SPEED * env->player.view_dir.y) : 0;
	(env->player.movement_y == 1) ? wolf3d_player_move
(env, -SPEED * env->player.view_dir.x, -SPEED * env->player.view_dir.y) : 0;
	(env->player.movement_x == 1) ? wolf3d_player_move
(env, -SPEED * env->player.view_dir.y, SPEED * env->player.view_dir.x) : 0;
	(env->player.movement_x == -1) ? wolf3d_player_move
(env, SPEED * env->player.view_dir.y, -SPEED * env->player.view_dir.x) : 0;
	(env->player.view_move == 1)
		? vec_rotate_2d(&env->player.view_dir, -2 * SPEED_CAM) : 0;
	(env->player.view_move == -1)
		? vec_rotate_2d(&env->player.view_dir, 2 * SPEED_CAM) : 0;
	hook_expose(env);
	return (1);
}
