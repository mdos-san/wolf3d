/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_player_draw.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:15:05 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/18 14:53:40 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf3d_player_draw(t_env *env)
{
	img_putpixel(env,
			BLOCK * env->player.pos.x, BLOCK * env->player.pos.y, 0x000000);
	img_putpixel(env,
			BLOCK * (env->player.pos.x + env->player.view_dir.x),
			BLOCK * (env->player.pos.y + env->player.view_dir.y), 0xff00ff);
}
