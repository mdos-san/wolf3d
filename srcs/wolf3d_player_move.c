/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_player_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:07:43 by ahamouda          #+#    #+#             */
/*   Updated: 2016/02/19 10:36:43 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf3d_player_move(t_env *env, double x, double y)
{
	if (env->map.map[(int)(env->player.pos.y + y)]
					[(int)(env->player.pos.x + x)] == '0' ||
		env->map.map[(int)(env->player.pos.y + y)]
					[(int)(env->player.pos.x + x)] == '#')
	{
		env->player.pos.x += x;
		env->player.pos.y += y;
	}
}
