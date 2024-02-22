/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:08:30 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/21 09:48:56 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_point(int x, int y, t_fdf *fdf)
{
	fdf->a->x = x;
	fdf->a->y = y;
	fdf->b->x = x;
	fdf->b->y = y;
}

void	design_img(t_fdf *fdf)
{
	int	i;
	int	*addr;

	i = -1;
	addr = (int *)fdf->img->addr;
	while (++i < HEIGHT * WIDTH)
		addr[i] = 0x071021;
}

void	draw_map(t_fdf *fdf)
{
	int		x;
	int		y;

	design_img(fdf);
	x = -1;
	while (++x < fdf->width)
	{
		y = -1;
		while (++y < fdf->height)
		{
			set_point(x - fdf->width / 2, y - fdf->height / 2, fdf);
			fdf->b->x += 1;
			if (x + 1 < fdf->width)
				draw_line(fdf);
			set_point(x - fdf->width / 2, y - fdf->height / 2, fdf);
			fdf->b->y += 1;
			if (y + 1 < fdf->height)
				draw_line(fdf);
		}
	}
}

void	fill_image(t_fdf *fdf)
{
	t_point	a;
	t_point	b;

	fdf->a = &a;
	fdf->b = &b;
	fdf->img->addr = mlx_get_data_addr(fdf->img->img, &fdf->img->pixel_bits, \
	&fdf->img->line_bytes, &fdf->img->endian);
	if (!fdf->img->addr)
		(free_array(fdf->color_map), free_array(fdf->color_map), \
		ft_putendl_fd(MLX_ADD, 2), exit(EXIT_FAILURE));
	draw_map(fdf);
}
