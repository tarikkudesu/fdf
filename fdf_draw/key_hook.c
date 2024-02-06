/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:47:34 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/05 18:03:01 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	handle_key(int key, void *f)
{
	t_fdf *fdf;

	fdf = f;
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
	if (key == 53)
		exit(0);
	if (key == 69)
	{
		fdf->x_zoom += 1;
		fdf->y_zoom += 1;
		fdf->z_zoom += 1;
	}
	if (key == 78)
	{
		fdf->x_zoom -= 1;
		fdf->y_zoom -= 1;
		fdf->z_zoom -= 1;
	}
	if (key == 126)
		fdf->y_offset -= 10;
	if (key == 125)
		fdf->y_offset += 10;
	if (key == 124)
		fdf->x_offset += 10;
	if (key == 123)
		fdf->x_offset -= 10;
	if (key == 6)
		fdf->gamma += 0.1;
	if (key == 7)
		fdf->gamma -= 0.1;
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
	draw_map(fdf);
	(void)fdf;
	printf("%d key is pressed\n", key);
	return (0);
}
