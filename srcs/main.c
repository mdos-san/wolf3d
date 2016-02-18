/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 08:03:34 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/18 08:13:55 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	main(void)
{
	t_env	*env;

	if (!(env = (t_env*)malloc(sizeof(env))))
		wolf3d_exit(&env, "Error: malloc for t_env.");
	else
	{
		wolf3d_init(env);
		wolf3d_exit(&env, "Exit, everything is ok ! :D");
	}
	return (0);
}
