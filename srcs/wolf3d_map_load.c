/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_map_load.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 08:17:34 by mdos-san          #+#    #+#             */
/*   Updated: 2016/03/28 13:55:28 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	get_color(t_env *env, int i, int j, char *line)
{
	if (line[i] == '1')
		env->map.color[j][i] = color_get(255, 0, 0, 0);
	else if (line[i] == '2')
		env->map.color[j][i] = color_get(0, 255, 0, 0);
	else if (line[i] == '3')
		env->map.color[j][i] = color_get(0, 0, 255, 0);
	else if (line[i] == '4')
		env->map.color[j][i] = color_get(255, 255, 0, 0);
	else if (line[i] == '5')
		env->map.color[j][i] = color_get(255, 0, 255, 0);
	else if (line[i] == '6')
		env->map.color[j][i] = color_get(0, 255, 255, 0);
	else if (line[i] == '7')
		env->map.color[j][i] = color_get(139, 69, 19, 0);
	else if (line[i] == '8')
		env->map.color[j][i] = color_get(42, 255, 42, 0);
	else if (line[i] == '9')
		env->map.color[j][i] = color_get(255, 255, 255, 0);
	else
		env->map.color[j][i] = color_get(0, 0, 0, 0);
}

static void	map_get_color(t_env *env, char *line, int j)
{
	int	i;
	int	lenght;

	i = 0;
	lenght = ft_strlen(line);
	while (i < lenght)
	{
		get_color(env, i, j, line);
		++i;
	}
}

static void	alloc_map(t_env *env, char **line, int j)
{
	(env->i == 0) ? check_full_line(env, line) : check_extremity(env, line);
	env->size_line = (env->size_line == -1 ||
		(int)ft_strlen(*line) == env->size_line) ? (int)ft_strlen(*line) :
		wolf3d_exit(&env, "Map error, check size of lines");
	if ((env->map.map[env->i] = ft_strdup(*line)) == NULL)
	{
		(*line != NULL) ? free(*line) : 0;
		wolf3d_exit(&env, "alloc_map: ft_strdup have failed! (map)");
	}
	if (!(env->map.color[j] =
				(t_color*)malloc(sizeof(t_color) * ft_strlen(*line))))
	{
		(*line != NULL) ? free(*line) : 0;
		wolf3d_exit(&env, "alloc_map: ft_strdup have failed! (map)");
	}
	map_get_color(env, *line, j);
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
	env->size_line = -1;
	if ((env->fd = open(env->av[1], O_RDWR)) == -1)
		wolf3d_exit(&env, "get_nb_line: open returned -1.");
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
	int		j;

	j = 0;
	env->i = 0;
	line = NULL;
	nb_line = get_nb_line(env);
	if (!(env->map.map = (char**)malloc(sizeof(char*) * (nb_line + 1))))
		wolf3d_exit(&env, "wolf3d_map_load: malloc (map)");
	if (!(env->map.color = (t_color**)malloc(sizeof(t_color*) * (nb_line))))
		wolf3d_exit(&env, "wolf3d_map_load: malloc (map)");
	env->map.map[nb_line] = NULL;
	if ((env->fd = open(env->av[1], O_RDWR)) == -1)
		wolf3d_exit(&env, "wolf3d_map_load: open");
	while ((ret = get_next_line(env->fd, &line)) > 0)
	{
		alloc_map(env, &line, j);
		++j;
	}
	(j == 0 || j == 1) ? wolf3d_exit(&env, "map need at least 3 line --'") : 0;
	check_full_line(env, &(env->map.map[j - 1]));
	env->map.size_y = j * BLOCK;
	(ret == -1) ? wolf3d_exit(&env, "wolf3d_map_load: gnl") : 0;
	((close(env->fd)) == -1) ? wolf3d_exit(&env, "wolf3d_map_load: close") : 0;
}
