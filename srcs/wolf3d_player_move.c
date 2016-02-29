/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_player_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:07:43 by ahamouda          #+#    #+#             */
/*   Updated: 2016/02/19 12:23:40 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf3d_player_move(t_env *env, double x, double y)
{
	clock_t	last_frame;

	if ((env->map.map[(int)((env->player.pos.y + y) / BLOCK)]
					[(int)((env->player.pos.x + x) / BLOCK)] == '0' ||
		env->map.map[(int)((env->player.pos.y + y) / BLOCK)]
					[(int)((env->player.pos.x + x) / BLOCK)] == '#' ) &&
	(env->map.map[(int)((env->player.pos.y + PLAYER_SIZE + y) / BLOCK)]
					[(int)((env->player.pos.x + PLAYER_SIZE + x) / BLOCK)] == '0' ||
		env->map.map[(int)((env->player.pos.y + PLAYER_SIZE + y) / BLOCK)]
					[(int)((env->player.pos.x + PLAYER_SIZE + x) / BLOCK)] == '#' ) &&
	(env->map.map[(int)((env->player.pos.y + y) / BLOCK)]
					[(int)((env->player.pos.x + PLAYER_SIZE + x) / BLOCK)] == '0' ||
		env->map.map[(int)((env->player.pos.y + y) / BLOCK)]
					[(int)((env->player.pos.x + PLAYER_SIZE + x) / BLOCK)] == '#' ) &&
		(env->map.map[(int)((env->player.pos.y + PLAYER_SIZE + y) / BLOCK)]
					[(int)((env->player.pos.x + x) / BLOCK)] == '0' ||
		env->map.map[(int)((env->player.pos.y + PLAYER_SIZE + y) / BLOCK)]
					[(int)((env->player.pos.x + x) / BLOCK)] == '#' ))
	{
		last_frame = clock() - *env->time;
		last_frame /= 10;
		env->player.pos.x += x * last_frame;
		env->player.pos.y += y * last_frame;
	}
}
