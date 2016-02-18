/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 08:03:38 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/18 09:03:19 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf3d_init(t_env *env)
{
	env->player.pos.x = 0;
	env->player.pos.y = 0;
	env->player.view_dir.x = 0;
	env->player.view_dir.y = 1;
	wolf3d_map_load(env);
}
