/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_player_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:06:33 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/19 12:19:00 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	wolf3d_player_init(t_env *env)
{
	int	j;

	env->i = 0;
	j = 0;
	env->player.movement_x = 0;
	env->player.movement_y = 0;
	env->player.view_dir.x = 0;
	env->player.view_dir.y = 1 * BLOCK;
	env->player.view_move = 0;
	while (env->map.map[(int)(env->i / BLOCK)])
	{
		while (env->map.map[(int)(env->i / BLOCK)][(int)(j / BLOCK)])
		{
			if (env->map.map[(int)(env->i / BLOCK)][(int)(j / BLOCK)] == '#')
			{
				env->player.pos.x = (double)j + 0.5;
				env->player.pos.y = (double)env->i + 0.5;
				return (1);
			}
			++j;
		}
		j = 0;
		++env->i;
	}
	return (-1);
}
