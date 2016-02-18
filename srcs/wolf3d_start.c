/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 10:55:58 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/18 11:30:02 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf3d_start(t_env *env)
{
	wolf3d_draw_map(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_loop(env->mlx);
}
