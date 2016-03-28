/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_map_del.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 08:23:28 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/18 09:18:46 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf3d_map_del(char ***addr)
{
	int	i;

	i = 0;
	if (*addr)
	{
		while ((*addr)[i] != NULL)
		{
			free((*addr)[i]);
			++i;
		}
		free(*addr);
	}
}
