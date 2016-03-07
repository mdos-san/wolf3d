#include "wolf3d.h"

void	wolf3d_render(t_env *env, int col, unsigned int color)
{
	double	up;
	double	down;

	if (env->dist != 0)
	{
		up = (HEIGHT / 2) - HEIGHT * 4 / *env->dist;
		down = (HEIGHT / 2) + HEIGHT * 4 / *env->dist;
		(up <= 0) ? (up = -1) : 0;
		(down > HEIGHT) ? (down = HEIGHT) : 0;
		img_putline(env, (t_2d_pnt){col, HEIGHT / 2}, (t_2d_pnt){col, up}, color);
		img_putline(env, (t_2d_pnt){col, HEIGHT / 2}, (t_2d_pnt){col, down}, color);
	}
}
