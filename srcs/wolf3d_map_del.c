/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_map_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 08:23:28 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/30 15:44:42 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf3d_map_del(t_map *map)
{
	int	i;

	i = 0;
	if (map->map)
	{
		while ((map->map)[i] != NULL)
		{
			free((map->map)[i]);
			free((map->color)[i]);
			++i;
		}
		free(map->map);
		free(map->color);
	}
}
