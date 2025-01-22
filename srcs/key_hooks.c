#include "../headers/fdf.h"

int key_up(int key, t_fdf *fdf)
{
	if (key == RIGHT_KEY)
		fdf->keys.right = false;
	if (key == LEFT_KEY)
		fdf->keys.left = false;
	if (key == UP_KEY)
		fdf->keys.up = false;
	if (key == DOWN_KEY)
		fdf->keys.down = false;
	if (key == KEY_1)
		fdf->keys.rrx = false;
	if (key == KEY_2)
		fdf->keys.dz = false;
	if (key == KEY_3)
		fdf->keys.rx = false;
	if (key == KEY_4)
		fdf->keys.rry = false;
	if (key == KEY_6)
		fdf->keys.ry = false;
	if (key == KEY_7)
		fdf->keys.rrz = false;
	if (key == KEY_8)
		fdf->keys.ez = false;
	if (key == KEY_9)
		fdf->keys.rx = false;
	if (key == T_KEY)
		fdf->keys.t = false;
	if (key == R_KEY)
		fdf->keys.r = false;
	if (key == F_KEY)
		fdf->keys.f = false;
	if (key == I_KEY)
		fdf->keys.zoom_in = false;
	if (key == O_KEY)
		fdf->keys.zoom_out = false;
	return (0);
}

int key_down(int key, t_fdf *fdf)
{
	if (key == ESC)
		exit_program(fdf);
	if (key == RIGHT_KEY)
		fdf->keys.right = true;
	if (key == LEFT_KEY)
		fdf->keys.left = true;
	if (key == UP_KEY)
		fdf->keys.up = true;
	if (key == DOWN_KEY)
		fdf->keys.down = true;
	if (key == KEY_1)
		fdf->keys.rrx = true;
	if (key == KEY_2)
		fdf->keys.dz = true;
	if (key == KEY_3)
		fdf->keys.rx = true;
	if (key == KEY_4)
		fdf->keys.rry = true;
	if (key == KEY_6)
		fdf->keys.ry = true;
	if (key == KEY_7)
		fdf->keys.rrz = true;
	if (key == KEY_8)
		fdf->keys.ez = true;
	if (key == KEY_9)
		fdf->keys.rx = true;
	if (key == T_KEY)
		fdf->keys.t = true;
	if (key == R_KEY)
		fdf->keys.r = true;
	if (key == F_KEY)
		fdf->keys.f = true;
	if (key == I_KEY)
		fdf->keys.zoom_in = true;
	if (key == O_KEY)
		fdf->keys.zoom_out = true;
	return (0);
}

void update_hooks(t_fdf *fdf)
{
	if (fdf->keys.up)
		fdf->y_translate -= 4;
	if (fdf->keys.down)
		fdf->y_translate += 4;
	if (fdf->keys.right)
		fdf->x_translate += 4;
	if (fdf->keys.left)
		fdf->x_translate -= 4;
	if (fdf->keys.zoom_in)
		fdf->zoom += 1;
	if (fdf->keys.zoom_out && fdf->zoom > 1)
		fdf->zoom -= 1;
	if (fdf->isoView && fdf->keys.rz)
		fdf->gamma += 0.05;
	if (fdf->isoView && fdf->keys.rrz)
		fdf->gamma -= 0.05;
	if (fdf->isoView && fdf->keys.rx)
		fdf->alpha += 0.05;
	if (fdf->isoView && fdf->keys.rrx)
		fdf->alpha -= 0.05;
	if (fdf->isoView && fdf->keys.ry)
		fdf->tetha += 0.05;
	if (fdf->isoView && fdf->keys.rry)
		fdf->tetha -= 0.05;
	if (fdf->keys.ez)
		fdf->z_incr += 0.05;
	if (fdf->keys.dz)
		fdf->z_incr -= 0.05;
	if (!fdf->isoView)
	{
		if (fdf->keys.t)
		{
			fdf->gamma = 0;
			fdf->tetha = 0;
			fdf->alpha = 0;
		}
		if (fdf->keys.r)
		{
			fdf->gamma = 0;
			fdf->tetha = 0;
			fdf->alpha = 1.5708;
		}
		if (fdf->keys.f)
		{
			fdf->gamma = -1.5708;
			fdf->tetha = 1.5708;
			fdf->alpha = 0;
		}
	}
}
