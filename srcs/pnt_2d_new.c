/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnt_2d_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 13:02:33 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/19 13:04:54 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_2d_pnt	*pnt_2d_new(double x, double y)
{
	t_2d_pnt	*new;

	new = (t_2d_pnt*)malloc(sizeof(t_2d_pnt));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	return (new);
}
