/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 14:14:30 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/19 14:20:48 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_player	*player_new(t_2d_pnt pos, t_2d_vec view_dir)
{
	t_player	*new;

	new = (t_player*)malloc(sizeof(t_player));
	if (!new)
		return (NULL);
	new->pos = pos;
	new->view_dir = view_dir;
	new->movement_x = 0;
	new->movement_y = 0;
	new->view_move = 0;
	return (new);
}
