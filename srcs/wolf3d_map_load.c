/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_map_load.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 08:17:34 by mdos-san          #+#    #+#             */
/*   Updated: 2016/02/18 09:29:10 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	alloc_map(t_env *env, char **line)
{
	if ((env->map.map[env->i] = ft_strdup(*line)) == NULL)
	{
		(*line != NULL) ? free(*line) : 0;
		wolf3d_exit(&env, "alloc_map: ft_strdup have failed! (map)");
	}
	(*line != NULL) ? free(*line) : 0;
	++env->i;
}

static int	get_nb_line(t_env *env)
{
	char	*line;
	int		n;
	int		ret;

	n = 0;
	line = NULL;
	if ((env->fd = open(env->av[1], O_RDWR)) == -1)
		wolf3d_exit(&env, "Error, open returned -1.");
	while ((ret = get_next_line(env->fd, &line)) > 0)
		++n;
	(ret == -1) ? wolf3d_exit(&env, "wolf3d_map_load: gnl") : 0;
	((close(env->fd)) == -1) ? wolf3d_exit(&env, "get_nb_line: close") : 0;
	return (n);
}

void		wolf3d_map_load(t_env *env)
{
	int		ret;
	int		nb_line;
	char	*line;

	env->i = 0;
	line = NULL;
	nb_line = get_nb_line(env);
	if (!(env->map.map = (char**)malloc(sizeof(char*) * (nb_line + 1))))
		wolf3d_exit(&env, "wolf3d_map_load: malloc (map)");
	env->map.map[nb_line] = NULL;
	if ((env->fd = open(env->av[1], O_RDWR)) == -1)
		wolf3d_exit(&env, "wolf3d_map_load: open");
	while ((ret = get_next_line(env->fd, &line)) > 0)
		alloc_map(env, &line);
	(ret == -1) ? wolf3d_exit(&env, "wolf3d_map_load: gnl") : 0;
	((close(env->fd)) == -1) ? wolf3d_exit(&env, "wolf3d_map_load: close") : 0;
	ft_putendl("Map:");
	env->i = -1;
	while (env->map.map[++env->i] != NULL)
		ft_putendl(env->map.map[env->i]);
}
