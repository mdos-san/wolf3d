/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_player_draw.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:15:05 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/14 13:59:31 by mdos-san         ###   ########.fr       */
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
			img_putline(env, (t_2d_pnt){env->player.pos.x + i, env->player.pos.y + j},
					(t_2d_pnt){env->player.pos.x + env->player.view_dir.x + i, env->player.pos.y + env->player.view_dir.y + j},
					color_convert(color_get(255, 0, 255, 0)));
			img_putpixel(env,
					env->player.pos.x + i,
					env->player.pos.y + j,
					0xffffff);
			img_putpixel(env,
					(env->player.pos.x + env->player.view_dir.x) + i,
					(env->player.pos.y + env->player.view_dir.y) + j,
					0xff00ff);
			++i;
		}
		++j;
	}
}
