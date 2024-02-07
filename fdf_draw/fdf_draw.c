/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:08:30 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/07 18:01:02 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	set_point(int x, int y, t_fdf *fdf)
{
	fdf->a->x = x;
	fdf->a->y = y;
	fdf->b->x = x;
	fdf->b->y = y;
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
			set_point(x, y, fdf);
			b.x += 1;
			if (x + 1 < fdf->width)
				draw_line(fdf);
			set_point(x, y, fdf);
			b.y += 1;
			if (y + 1 < fdf->height)
				draw_line(fdf);
		}
	}
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
}

void	fill_image(t_fdf *fdf)
{
	fdf->img->addr = mlx_get_data_addr(fdf->img->img, &fdf->img->pixel_bits, \
	&fdf->img->line_bytes, &fdf->img->endian);
	if (!fdf->img->addr)
		(free_struct(fdf), ft_putstr_fd(MLX_ADD, 2), exit(EXIT_FAILURE));
	fdf->img->line_bytes /= 4;
	draw_map(fdf);
}

void	panel(t_fdf *fdf)
{
	int		p_h;
	int		p_w;
	int		i_h;
	int		i_w;

	fdf->ui->intro = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->ui->intro)
		(free_struct(fdf), ft_putstr_fd(MLX_IMG, 2), exit(EXIT_FAILURE));
	fdf->ui->panel = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->ui->panel)
		(free_struct(fdf), ft_putstr_fd(MLX_IMG, 2), exit(EXIT_FAILURE));
	fdf->ui->panel  = mlx_xpm_file_to_image(fdf->mlx, "assets/panel.xpm", &p_h, &p_w);
	fdf->ui->intro  = mlx_xpm_file_to_image(fdf->mlx, "assets/fdf.xpm", &i_h, &i_w);
}


void	make_it_3d(t_fdf *fdf)
{
	t_ui	ui;
	t_img	img;

	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		(free_struct(fdf), ft_putstr_fd(MLX_INIT, 2), exit(EXIT_FAILURE));
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "fdf");
	if (!fdf->win)
		(free_struct(fdf), ft_putstr_fd(MLX_WIN, 2), exit(EXIT_FAILURE));
	img.img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!img.img)
		(free_struct(fdf), ft_putstr_fd(MLX_IMG, 2), exit(EXIT_FAILURE));
	fdf->img = &img;
	fdf->ui = &ui;
	panel(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->ui->intro, 0, 0);
	fill_image(fdf);
	mlx_key_hook(fdf->win, &handle_key, fdf);
	mlx_loop(fdf->mlx);
}
