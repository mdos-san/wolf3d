#include "wolf3d.h"

void	wolf3d_render(t_env *env, int col, double dist)
{
	img_putline(env, (t_2d_pnt){col, HEIGHT / 2}, (t_2d_pnt){col, (HEIGHT / 2) + HEIGHT / dist}, 0x0000ff);
	img_putline(env, (t_2d_pnt){col, HEIGHT / 2}, (t_2d_pnt){col, HEIGHT / 2 - HEIGHT / dist}, 0xff0000);
}
