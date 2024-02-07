/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:47:34 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/07 20:02:36 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	translate(int key, t_fdf *fdf)
{
	if (key == UP)
		fdf->y_offset -= 1;
	if (key == DOWN)
		fdf->y_offset += 1;
	if (key == RIGHT)
		fdf->x_offset += 1;
	if (key == LEFT)
		fdf->x_offset -= 1;
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == R_Z)
		fdf->gamma += 0.01;
	if (key == RR_Z)
		fdf->gamma -= 0.01;
	if (key == R_X)
		fdf->alpha += 0.01;
	if (key == RR_X)
		fdf->alpha -= 0.01;
	if (key == R_Y)
		fdf->tetha += 0.01;
	if (key == RR_Y)
		fdf->tetha -= 0.01;
}

void	zoom(int key, t_fdf *fdf)
{
	if (key == ZOOM_IN)
	{
		fdf->zoom += 1;
		fdf->z_zoom += 1;
		fdf->x_offset = 300 + WIDTH / 2 - (fdf->width / 2) * fdf->zoom;
		fdf->y_offset = HEIGHT / 2 - (fdf->height / 2) * fdf->zoom;
	}
	if (key == ZOOM_OUT)
	{
		fdf->zoom -= 1;
		fdf->z_zoom -= 1;
		fdf->x_offset = 300 + WIDTH / 2 - (fdf->width / 2) * fdf->zoom;
		fdf->y_offset = HEIGHT / 2 - (fdf->height / 2) * fdf->zoom;
	}
}

int	handle_key(int key, void *f)
{
	t_fdf *fdf;

	fdf = f;
	if (key == 53)
		exit(0);
	if (key == ZOOM_IN || key == ZOOM_OUT)
		zoom(key, fdf);
	if (key == UP || key == DOWN || key == RIGHT || key == LEFT)
		translate(key, fdf);
	if (key == R_X || key == RR_X || key == R_Z || key == RR_Z || key == R_Y || key == RR_Y)
		rotate(key, fdf);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->ui->panel, 0, 0);
	printf("%d\n", key);
	return (0);
}
