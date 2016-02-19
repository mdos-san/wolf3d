/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_putline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 10:58:21 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/19 10:20:25 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	exeption(t_env *par, t_2d_pnt a, t_2d_pnt b, unsigned int color)
{
	double coef;

	coef = (b.x - a.x) / (b.y - a.y);
	while ((int)a.y != (int)b.y)
	{
		img_putpixel(par, a.x, a.y, color);
		if (a.y < b.y)
		{
			a.x += coef;
			a.y++;
		}
		else
		{
			a.x -= coef;
			a.y--;
		}
	}
}

void		img_putline(t_env *par, t_2d_pnt a, t_2d_pnt b, unsigned int color)
{
	double	coef;

	coef = (b.y - a.y) / (b.x - a.x);
	if (-1 <= coef && coef <= 1)
	{
		while ((int)a.x != (int)b.x)
		{
			img_putpixel(par, a.x, a.y, color);
			if (a.x < b.x)
			{
				a.y += coef;
				a.x++;
			}
			else
			{
				a.y -= coef;
				a.x--;
			}
		}
	}
	else
		exeption(par, a, b, color);
}
