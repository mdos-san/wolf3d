/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_map_is_wall.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 17:45:24 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/02 17:54:30 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	wolf3d_map_is_wall(t_env *env, t_2d_pnt a)
{
	if (env->map.map[(int)(a.y / BLOCK)][(int)(a.x / BLOCK)] == '1')
		return (1);
	if (env->map.map[(int)(a.y / BLOCK)][(int)(a.x / BLOCK)] == '\0')
		return (1);
	return (0);
}
