/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:00:52 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/23 09:28:13 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	orthographic(int key, t_fdf *fdf)
{
	if (key == T_VIEW)
	{
		fdf->gamma = 0;
		fdf->tetha = 0;
		fdf->alpha = 0;
	}
	else if (key == R_VIEW)
	{
		fdf->gamma = 0;
		fdf->tetha = 0;
		fdf->alpha = 1.5708;
	}
	else
	{
		fdf->gamma = -1.5708;
		fdf->tetha = 1.5708;
		fdf->alpha = 0;
	}
}

void	reset_view(t_fdf *fdf)
{
	fdf->gamma = 0;
	fdf->alpha = 0;
	fdf->tetha = 0;
	fdf->z_incr = 1;
	fdf->zoom = (WIDTH / fdf->width) / 3;
	fdf->x_translate = 0;
	fdf->y_translate = 0;
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
	if (fdf->iso)
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->ui->iso_panel, 0, 0);
	else
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->ui->ortho_panel, 0, 0);
}

void	isometric_view(t_fdf *fdf)
{
	fdf->iso = 0;
	reset_view(fdf);
}

void	orthographic_view(t_fdf *fdf)
{
	fdf->iso = 1;
	reset_view(fdf);
}
