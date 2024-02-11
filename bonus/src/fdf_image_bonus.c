/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:08:30 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/11 16:18:02 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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
	int	j;
	int	*addr;

	i = -1;
	addr = (int *)fdf->img->addr;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			addr[i * WIDTH + j] = 0x071021;
	}
	if (!fdf->iso)
	{
		i = 399;
		while (++i < WIDTH)
			addr[(HEIGHT / 2) * WIDTH + i] = 0xe2f3f5;
		i = -1;
		while (++i < HEIGHT)
			addr[i * WIDTH + 400 + (WIDTH - 400) / 2] = 0xe2f3f5;
	}
}

void	draw_map(t_fdf *fdf)
{
	t_point	a;
	t_point	b;
	int		x;
	int		y;

	design_img(fdf);
	fdf->a = &a;
	fdf->b = &b;
	x = -1;
	while (++x < fdf->width)
	{
		y = -1;
		while (++y < fdf->height)
		{
			fdf->color = fdf->color_map[y][x];
			set_point(x - fdf->width / 2, y - fdf->height / 2, fdf);
			b.x += 1;
			if (x + 1 < fdf->width)
				draw_line(fdf);
			set_point(x - fdf->width / 2, y - fdf->height / 2, fdf);
			b.y += 1;
			if (y + 1 < fdf->height)
				draw_line(fdf);
		}
	}
}

void	fill_image(t_fdf *fdf)
{
	fdf->img->addr = mlx_get_data_addr(fdf->img->img, &fdf->img->pixel_bits, \
	&fdf->img->line_bytes, &fdf->img->endian);
	if (!fdf->img->addr)
		(destroy(fdf), ft_putendl_fd(MLX_ADD, 2), exit(EXIT_FAILURE));
	fdf->img->line_bytes /= 4;
	draw_map(fdf);
}

void	panel(t_fdf *fdf)
{
	t_p	iso;
	t_p	ortho;
	t_p	intro;

	fdf->ui->iso_panel = mlx_xpm_file_to_image(fdf->mlx, "bonus/assets/iso_panel.xpm", &iso.h, &iso.w);
	fdf->ui->ortho_panel = mlx_xpm_file_to_image(fdf->mlx, "bonus/assets/ortho_panel.xpm", &ortho.h, &ortho.w);
	fdf->ui->intro = mlx_xpm_file_to_image(fdf->mlx, "bonus/assets/fdf.xpm", &intro.h, &intro.w);
}
