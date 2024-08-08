#include "../headers/fdf.h"

int	key_up(int key, t_fdf *fdf) {
	// puts("key release");
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
	return (0);
}

int	key_down(int key, t_fdf *fdf) {
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
	return (0);
}