/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:08:30 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/09 17:42:13 by tamehri          ###   ########.fr       */
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
			addr[(HEIGHT / 2) * WIDTH + i] = 0xffffff;
		i = -1;
		while (++i < HEIGHT)
			addr[i * WIDTH + 400 + (WIDTH - 400) / 2] = 0xffffff;
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
	t_p	iso;
	t_p	ortho;
	t_p	intro;

	fdf->ui->intro = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->ui->intro)
		(free_struct(fdf), ft_putstr_fd(MLX_IMG, 2), exit(EXIT_FAILURE));
	fdf->ui->iso_panel = mlx_new_image(fdf->mlx, 400, HEIGHT);
	if (!fdf->ui->iso_panel)
		(free_struct(fdf), ft_putstr_fd(MLX_IMG, 2), exit(EXIT_FAILURE));
	fdf->ui->ortho_panel = mlx_new_image(fdf->mlx, 400, HEIGHT);
	if (!fdf->ui->ortho_panel)
		(free_struct(fdf), ft_putstr_fd(MLX_IMG, 2), exit(EXIT_FAILURE));
	fdf->ui->iso_panel  = mlx_xpm_file_to_image(fdf->mlx, "assets/iso_panel.xpm", &iso.h, &iso.w);
	fdf->ui->ortho_panel  = mlx_xpm_file_to_image(fdf->mlx, "assets/ortho_panel.xpm", &ortho.h, &ortho.w);
	fdf->ui->intro  = mlx_xpm_file_to_image(fdf->mlx, "assets/fdf.xpm", &intro.h, &intro.w);
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
	mlx_hook(fdf->win, 2, 0, &handle_key, fdf);
	mlx_mouse_hook(fdf->win, &handle_mouse, fdf);
	mlx_loop(fdf->mlx);
}
