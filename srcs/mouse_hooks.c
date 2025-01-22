#include "../headers/fdf.h"

int mouse_release(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	(void)fdf;
	if (button == 1)
		fdf->pressed = false;
	return (0);
}

int mouse_move(int x, int y, t_fdf *fdf)
{
	// puts("mouse move");
	(void)x;
	(void)y;
	(void)fdf;
	return (0);
}

void reset_view(t_fdf *fdf)
{
	fdf->gamma = 0;
	fdf->alpha = 0;
	fdf->tetha = 0;
	fdf->z_incr = 1;
	fdf->zoom = (WIDTH / fdf->width) / 3;
	fdf->x_translate = 0;
	fdf->y_translate = 0;
}

int mouse_press(int button, int x, int y, t_fdf *fdf)
{
	printf("%d %d\n", x, y);
	if (button == 1 && x > 100 && x < 300 && y > 1100 && y < 1150)
		reset_view(fdf);
	if (button == 1 && x > 200 && x < 400 && y > 300 && y < 350)
	{
		fdf->isoView = 0;
		reset_view(fdf);
	}
	else if (button == 1 && x > 0 && x < 200 && y > 300 && y < 350)
	{
		fdf->isoView = 1;
		reset_view(fdf);
	}
	if (button == 4)
		fdf->keys.zoom_in = false;
	if (button == 5)
		fdf->keys.zoom_out = false;
	if (button == 1)
		fdf->pressed = 1;
	fdf->x = x;
	fdf->y = y;
	if (button == 1)
		fdf->pressed = 1;
	return (0);
}