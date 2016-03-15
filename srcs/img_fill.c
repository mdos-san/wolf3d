/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 05:27:07 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/15 13:21:26 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	img_fill_up(t_env *env, double color)
{
	int		x;
	int		y;
	int		size;

	x = 0;
	y = 0;
	size = HEIGHT / 2;
	while (y < size)
	{
		while (x < WIDTH)
		{
			img_putpixel(env, x, y, color);
			++x;
		}
		x = 0;
		++y;
	}
}

void	img_fill_down(t_env *env, t_color color)
{
	int		x;
	int		y;
	int		size;
	double	grad;
	t_color	tmp;

	env->i = 0;
	y = HEIGHT;
	size = HEIGHT / 2;
	grad = 100 / (double)size;
	tmp = color;
	while (y > size)
	{
		x = -1;
		while (++x < WIDTH)
			img_putpixel(env, x, y, color_convert(color));
		color = tmp;
		color.r -= (grad * env->i);
		color.g -= (grad * env->i);
		color.b -= (grad * env->i);
		++env->i;
		--y;
	}
}
