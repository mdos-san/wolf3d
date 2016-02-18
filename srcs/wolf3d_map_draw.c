/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_draw_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:20:19 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/18 13:20:34 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	draw_block(t_env *env, int x, int y, unsigned int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < BLOCK)
	{
		while (j < BLOCK)
		{
			img_putpixel(env, x * BLOCK + j, y * BLOCK + i, color);
			++j;
		}
		j = 0;
		++i;
	}
}

void	wolf3d_map_draw(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env->map.map[i])
	{
		while (env->map.map[i][j])
		{
			if (env->map.map[i][j] == '1')
				draw_block(env, j, i, 0xFF0000);
			else if (env->map.map[i][j] == '#')
				draw_block(env, j, i, 0x0000ff);
			else
				draw_block(env, j, i, 0x00FF00);
			++j;
		}
		j = 0;
		++i;
	}
}
