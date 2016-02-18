/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_player_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:06:33 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/18 13:37:10 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	wolf3d_player_init(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	env->player.movement = 0;
	while (env->map.map[i])
	{
		while (env->map.map[i][j])
		{
			if (env->map.map[i][j] == '#')
			{
				env->player.pos.x = (double)j + 0.5;
				env->player.pos.y = (double)i + 0.5;
				return (1);
			}
			++j;
		}
		j = 0;
		++i;
	}
	return (-1);
}
