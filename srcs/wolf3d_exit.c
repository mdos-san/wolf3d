/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 08:09:51 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/30 15:45:04 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	wolf3d_exit(t_env **env, char *str)
{
	if (*env)
	{
		wolf3d_map_del(&(*env)->map);
		if ((*env)->img)
			mlx_destroy_image((*env)->mlx, (*env)->img);
		if ((*env)->win)
			mlx_destroy_window((*env)->mlx, (*env)->win);
		free(*env);
	}
	ft_putendl(str);
	exit(0);
}
