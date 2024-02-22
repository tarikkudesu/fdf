/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:03:02 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/22 12:09:20 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	handle_mouse_release(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (button == 1)
		fdf->pressed = 0;
	return (0);
}

int	handle_mouse_move(int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	(void)y;
	if (fdf->pressed == 1 && fdf->iso)
	{
		fdf->gamma += (fdf->x - x) * 0.0002;
		fdf->alpha += (fdf->y - y) * 0.0002;
		draw_map(fdf);
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
		if (fdf->iso)
			mlx_put_image_to_window(fdf->mlx, fdf->win, \
			fdf->ui->iso_panel, 0, 0);
		else
			mlx_put_image_to_window(fdf->mlx, fdf->win, \
			fdf->ui->ortho_panel, 0, 0);
	}
	return (0);
}

int	handle_mouse(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (button == 1 && x > 100 && x < 300 && y > 980 && y < 1030)
		reset_view(fdf);
	if (button == 1 && x > 200 && x < 400 && y > 350 && y < 400)
		isometric_view(fdf);
	else if (button == 1 && x > 0 && x < 200 && y > 350 && y < 400)
		orthographic_view(fdf);
	if (button == 4)
		zoom(ZOOM_IN, fdf);
	if (button == 5)
		zoom(ZOOM_OUT, fdf);
	fdf->x = x;
	fdf->y = y;
	if (button == 1)
		fdf->pressed = 1;
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
	if (fdf->iso)
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->ui->iso_panel, 0, 0);
	else
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->ui->ortho_panel, 0, 0);
	return (0);
}
