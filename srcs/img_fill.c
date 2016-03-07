/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 05:27:07 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/07 06:15:52 by mdos-san         ###   ########.fr       */
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
	int		i;
	t_color	tmp;

	x = 0;
	i = 0;
	y = HEIGHT;
	size = HEIGHT / 2;
	grad = 100 / (double)size;
	tmp = color;
	while (y > size)
	{
		while (x < WIDTH)
		{
			img_putpixel(env, x, y, color_convert(color));
			++x;
		}
		color = tmp;
		color.r -= (grad * i);
		color.g -= (grad * i);
		color.b -= (grad * i);
		x = 0;
		++i;
		--y;
	}
}
