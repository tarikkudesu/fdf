/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:47:34 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/11 16:18:16 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	translate(int key, t_fdf *fdf)
{
	if (key == UP)
		fdf->y_translate -= 4;
	if (key == DOWN)
		fdf->y_translate += 4;
	if (key == RIGHT)
		fdf->x_translate += 4;
	if (key == LEFT)
		fdf->x_translate -= 4;
}

void	rotate(int key, t_fdf *fdf)
{
	if (fdf->iso && key == R_Z)
		fdf->gamma += 0.05;
	if (fdf->iso && key == RR_Z)
		fdf->gamma -= 0.05;
	if (fdf->iso && key == R_X)
		fdf->alpha += 0.05;
	if (fdf->iso && key == RR_X)
		fdf->alpha -= 0.05;
	if (fdf->iso && key == R_Y)
		fdf->tetha += 0.05;
	if (fdf->iso && key == RR_Y)
		fdf->tetha -= 0.05;
}

void	zoom(int key, t_fdf *fdf)
{
	if (key == ZOOM_IN)
		fdf->zoom += 1;
	if (key == ZOOM_OUT && fdf->zoom > 1)
		fdf->zoom -= 1;
}

void	elevate(int key, t_fdf *fdf)
{
	if (key == INCR_Z)
		fdf->z_zoom += 0.1;
	else
		fdf->z_zoom -= 0.1;
}

int	handle_key(int key, void *f)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)f;
	if (key == 53)
		(destroy(fdf), exit(0));
	if (key == ZOOM_IN || key == ZOOM_OUT)
		zoom(key, fdf);
	if (key == UP || key == DOWN || key == RIGHT || key == LEFT)
		translate(key, fdf);
	if (key == R_X || key == RR_X || key == R_Z || key == RR_Z \
	|| key == R_Y || key == RR_Y)
		rotate(key, fdf);
	if (key == INCR_Z || key == DECR_Z)
		elevate(key, fdf);
	if (!fdf->iso && (key == F_VIEW || key == T_VIEW || key == R_VIEW))
		orthographic(key, fdf);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
	if (fdf->iso)
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->ui->iso_panel, 0, 0);
	else
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->ui->ortho_panel, 0, 0);
	return (0);
}
