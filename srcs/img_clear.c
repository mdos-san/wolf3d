/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 21:53:09 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/18 09:56:36 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	img_clear(t_env *env)
{
	if (env->img)
		mlx_destroy_image(env->mlx, env->img);
	if ((env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT)) == NULL)
		wolf3d_exit(&env, "img_clear: mlx_new_image");
	env->data = mlx_get_data_addr(env->img, &env->bpp, &env->sl, &env->ed);
	env->bpp /= 8;
}
