/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_full_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <mdos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 13:09:24 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/28 13:41:38 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	check_full_line(t_env *env, char **line)
{
	int	i;
	
	i = 0;
	while ((*line)[i] != '\0')
	{
		if (ft_isdigit((*line)[i]) == 0 || (*line)[i] == '2')
			wolf3d_exit(&env, "Map need to be closed");
		++i;
	}
}

void	check_extremity(t_env *env, char **line)
{
	int	i;

	i = 0;
	if (ft_isdigit((*line)[i]) == 0 || (*line)[i] == '2')
		wolf3d_exit(&env, "Map need to be closed");
	while ((*line)[i] != '\0')
		++i;
	--i;
	if (ft_isdigit((*line)[i]) == 0 || (*line)[i] == '2')
		wolf3d_exit(&env, "Map need to be closed");
}
