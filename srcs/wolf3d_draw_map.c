/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_draw_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 11:24:56 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/18 12:01:36 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf3d_draw_map(t_env *env)
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
				img_putpixel(env, j, i, 0xFF0000);
			else
				img_putpixel(env, j, i, 0x00FF00);
			++j;
		}
		j = 0;
		++i;
	}
}
