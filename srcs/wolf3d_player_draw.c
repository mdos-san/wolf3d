/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_player_draw.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:15:05 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/18 17:12:51 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf3d_player_draw(t_env *env)
{
	int		i;
	int		j;

	j = 0;
	while (j < PLAYER_SIZE)
	{
		i = 0;
		while (i < PLAYER_SIZE)
		{
			img_putpixel(env,
					BLOCK * env->player.pos.x + i,
					BLOCK * env->player.pos.y + j,
					0xffffff);
			img_putpixel(env,
					BLOCK * (env->player.pos.x + env->player.view_dir.x) + i,
					BLOCK * (env->player.pos.y + env->player.view_dir.y) + j,
					0xff00ff);
			++i;
		}
		++j;
	}
}
