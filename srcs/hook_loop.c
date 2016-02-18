/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_loop.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:45:46 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/18 16:17:03 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	hook_loop(t_env *env)
{
	(env->player.movement_y == -1) ? wolf3d_player_move(env, 0.1 * env->player.view_dir.x, 0.1 * env->player.view_dir.y) : 0;
	(env->player.movement_y == 1) ? wolf3d_player_move(env, -0.1 * env->player.view_dir.x, -0.1 * env->player.view_dir.y) : 0;
	(env->player.movement_x == 1) ? wolf3d_player_move(env, -0.1 * env->player.view_dir.y, 0.1 * env->player.view_dir.x) : 0;
	(env->player.movement_x == -1) ? wolf3d_player_move(env, 0.1 * env->player.view_dir.y, -0.1 * env->player.view_dir.x) : 0;
	(env->player.view_move == 1) ? vec_rotate_2d(&env->player.view_dir, -2) : 0;
	(env->player.view_move == -1) ? vec_rotate_2d(&env->player.view_dir, 2) : 0;
	hook_expose(env);
	return (1);
}
