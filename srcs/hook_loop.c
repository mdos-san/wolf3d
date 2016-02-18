/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_loop.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:45:46 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/18 13:59:48 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	hook_loop(t_env *env)
{
	(env->player.movement_y == 1) ? (env->player.pos.y -= 0.1) : 0;
	(env->player.movement_y == 2) ? (env->player.pos.y += 0.1) : 0;
	(env->player.movement_x == 3) ? (env->player.pos.x -= 0.1) : 0;
	(env->player.movement_x == 4) ? (env->player.pos.x += 0.1) : 0;
	hook_expose(env);
	return (1);
}
