/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 10:55:58 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/18 15:21:16 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf3d_start(t_env *env)
{
	event_key(env);
	mlx_expose_hook(env->win, hook_expose, env);
	mlx_loop_hook(env->mlx, hook_loop, env);
	mlx_loop(env->mlx);
}
