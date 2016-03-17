/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 13:24:05 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/17 13:30:36 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	textures_load(t_env *env)
{
	env->textures[0].ptr = mlx_xpm_file_to_image(env->mlx,
		"textures/wall_1.xpm",
		&env->textures[0].width, &env->textures[0].height);
	env->textures[0].data = mlx_get_data_addr(env->textures[0].ptr,
			&env->textures[0].bpp, &env->textures[0].sl, &env->textures[0].ed);
	env->textures[0].bpp /= 8;
	return (1);
}
