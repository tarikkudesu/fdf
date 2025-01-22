
#include "../headers/fdf.h"

void	rotate_z(t_fdf *fdf)
{
	int	tmp;

	tmp = fdf->a.x;
	fdf->a.x = tmp * cos(fdf->gamma) - fdf->a.y * sin(fdf->gamma);
	fdf->a.y = tmp * sin(fdf->gamma) + fdf->a.y * cos(fdf->gamma);
	tmp = fdf->b.x;
	fdf->b.x = tmp * cos(fdf->gamma) - fdf->b.y * sin(fdf->gamma);
	fdf->b.y = tmp * sin(fdf->gamma) + fdf->b.y * cos(fdf->gamma);
}

void	rotate_y(t_fdf *fdf)
{
	int	tmp;

	tmp = fdf->a.x;
	fdf->a.x = tmp * cos(fdf->tetha) + fdf->a.z * sin(fdf->tetha);
	fdf->a.z = fdf->a.z * cos(fdf->tetha) - tmp * sin(fdf->tetha);
	tmp = fdf->b.x;
	fdf->b.x = tmp * cos(fdf->tetha) + fdf->b.z * sin(fdf->tetha);
	fdf->b.z = fdf->b.z * cos(fdf->tetha) - tmp * sin(fdf->tetha);
}

void	rotate_x(t_fdf *fdf)
{
	int	tmp;

	tmp = fdf->a.y;
	fdf->a.y = tmp * cos(fdf->alpha) - fdf->a.z * sin(fdf->alpha);
	fdf->a.z = tmp * sin(fdf->alpha) + fdf->a.z * cos(fdf->alpha);
	tmp = fdf->b.y;
	fdf->b.y = tmp * cos(fdf->alpha) - fdf->b.z * sin(fdf->alpha);
	fdf->b.z = tmp * sin(fdf->alpha) + fdf->b.z * cos(fdf->alpha);
}

void	isometric(t_fdf *fdf)
{
	int	tmp;

	tmp = fdf->a.x;
	fdf->a.x = (tmp - fdf->a.y) * cos(0.523599);
	fdf->a.y = (tmp + fdf->a.y) * sin(0.523599) - fdf->a.z;
	tmp = fdf->b.x;
	fdf->b.x = (tmp - fdf->b.y) * cos(0.523599);
	fdf->b.y = (tmp + fdf->b.y) * sin(0.523599) - fdf->b.z;
}

void	set_coordinnates(t_fdf *fdf)
{
    fdf->a.x -= fdf->width / 2;
    fdf->b.x -= fdf->width / 2;
    fdf->a.y -= fdf->height / 2;
    fdf->b.y -= fdf->height / 2;
	fdf->a.x *= fdf->zoom;
	fdf->b.x *= fdf->zoom;
	fdf->a.y *= fdf->zoom;
	fdf->b.y *= fdf->zoom;
	fdf->a.z *= fdf->zoom;
	fdf->b.z *= fdf->zoom;
	rotate_x(fdf);
	rotate_y(fdf);
	rotate_z(fdf);
	if (fdf->isoView)
		isometric(fdf);
	fdf->a.x += 400 + (WIDTH - 400) / 2 + fdf->x_translate;
	fdf->b.x += 400 + (WIDTH - 400) / 2 + fdf->x_translate;
	fdf->a.y += HEIGHT / 2 + fdf->y_translate;
	fdf->b.y += HEIGHT / 2 + fdf->y_translate;
}
