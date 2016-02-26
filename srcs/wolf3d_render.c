#include "wolf3d.h"

void	wolf3d_render(t_env *env, int col, unsigned int color)
{
	if (env->dist != 0)
	{
		img_putline(env, (t_2d_pnt){col, HEIGHT / 2}, (t_2d_pnt){col, (HEIGHT / 2) + HEIGHT * 4 / *env->dist}, color);
		img_putline(env, (t_2d_pnt){col, HEIGHT / 2}, (t_2d_pnt){col, HEIGHT / 2 - HEIGHT * 4 / *env->dist}, color);
	}
}
