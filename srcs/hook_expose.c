/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_expose.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:50:05 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/18 13:53:00 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	hook_expose(t_env *env)
{
	img_clear(env);
	wolf3d_map_draw(env);
	wolf3d_player_draw(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (1);
}
