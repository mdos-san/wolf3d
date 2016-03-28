/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_putpixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 21:53:07 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/18 09:59:58 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	img_putpixel(t_env *env, int x, int y, int color)
{
	if ((0 <= x && x < WIDTH) && (0 <= y && y < HEIGHT))
		*(unsigned int*)(env->data + x * env->bpp + env->sl * y) =
			mlx_get_color_value(env->mlx, color);
}
