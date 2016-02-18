/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 08:03:34 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/18 09:28:37 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	main(int ac, char **av)
{
	t_env	*env;

	if (ac == 2)
		if (!(env = (t_env*)malloc(sizeof(t_env))))
			wolf3d_exit(&env, "Error: malloc for t_env.");
		else
		{
			env->ac = ac;
			env->av = av;
			wolf3d_init(env);
			wolf3d_exit(&env, "Exit, everything is ok ! :D");
		}
	else
		wolf3d_exit(&env, "Usage:\n./wolf3d path/to/map");
	return (0);
}
