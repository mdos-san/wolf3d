/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_player_draw.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:15:05 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/18 13:55:00 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf3d_player_draw(t_env *env)
{
	img_putpixel(env,
			BLOCK * env->player.pos.x, BLOCK * env->player.pos.y, 0x000000);
}
