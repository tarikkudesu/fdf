/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:00:52 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/10 10:11:44 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	reset_view(t_fdf *fdf)
{
	fdf->gamma = 0;
	fdf->alpha = 0;
	fdf->tetha = 0;
	fdf->z_zoom = 1;
	fdf->zoom = (WIDTH / fdf->width) / 3;
	fdf->x_offset = 400 + (WIDTH - 400) / 2;
	fdf->y_offset = HEIGHT / 2;
	fdf->x_translate = 0;
	fdf->y_translate = 0;
	fdf->color = 0x76EFF0;
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
	if (fdf->iso)
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->ui->iso_panel, 0, 0);
	else
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->ui->ortho_panel, 0, 0);
}

void	isometric_view(t_fdf *fdf)
{
	fdf->iso = 1;
	reset_view(fdf);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
	if (fdf->iso)
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->ui->iso_panel, 0, 0);
	else
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->ui->ortho_panel, 0, 0);
}

void	orthographic_view(t_fdf *fdf)
{
	fdf->iso = 0;
	reset_view(fdf);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
	if (fdf->iso)
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->ui->iso_panel, 0, 0);
	else
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->ui->ortho_panel, 0, 0);
}

int	handle_mouse(int button, int x, int y, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf *)param;
	if (button == 1 && x > 100 && x < 300 && y > 980 && y < 1030)
		reset_view(fdf);
	if (button == 1 && x > 200 && x < 400 && y > 350 && y < 400)
		orthographic_view(fdf);
	if (button == 1 && x > 0 && x < 200 && y > 350 && y < 400)
		isometric_view(fdf);
	return (0);
}
