/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 08:03:34 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/19 14:51:17 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	main(int ac, char **av)
{
	t_env	*env;

	if (ac == 2)
	{
		env = wolf3d_init(ac, av);
		wolf3d_start(env);
	}
	else
		wolf3d_exit(&env, "Usage:\n./wolf3d path/to/map");
	return (0);
}
