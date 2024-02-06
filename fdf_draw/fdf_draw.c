/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:08:30 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/06 20:39:40 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	my_mlx_pixel_put(int x, int y, t_fdf *fdf)
{
	int	*addr;

	addr = (int *)fdf->img->addr;
	if (x < WIDTH && x > 0 && y < HEIGHT && y > 0)
		addr[y * fdf->img->line_bytes + x] = fdf->color;
}

// void	draw_line(t_fdf *fdf)
// {
// 	set_coordinnates(fdf);
//     if (abs(fdf->line->y2 - fdf->line->y1) > abs(fdf->line->x2 - fdf->line->x1)) {
//         swap_(fdf->line);
//     }

//     if (fdf->line->x1 > fdf->line->x2) {
// 		swap_2(fdf->line);
//     }

//     int dx = fdf->line->x2 - fdf->line->x1;
//     int dy = fdf->line->y2 - fdf->line->y1;
//     float gradient = (float)dy / (float)dx;

//     float error = -0.5;

//     for (int x = fdf->line->x1; x <= fdf->line->x2; x++) {
//         int y = (int)(fdf->line->y1 + error);
//         my_mlx_pixel_put(x, y, fdf);
//         error += gradient;
//     }
// }

void	draw_line(t_fdf *fdf)
{
	float	x_step;
	float	y_step;
	float	max;
	int		x_bool;
	int		y_bool;
	
	set_coordinnates(fdf);
	x_bool = 0;
	y_bool = 0;
	x_step = fdf->b->x - fdf->a->x;
	if (x_step == 0)
		x_bool = 1;
	y_step = fdf->b->y - fdf->a->y;
	if (y_step == 0)
		y_bool = 1;
	max = max_value(abs_float_value(x_step), abs_float_value(y_step));
	x_step /= max;
	y_step /= max;
	printf("(%d, %d) => (%d, %d)\n", (int)fdf->a->x, (int)fdf->a->y, (int)fdf->b->x, (int)fdf->b->x);
	while (1)
	{
		my_mlx_pixel_put(fdf->a->x, fdf->a->y, fdf);
		if (!x_bool)
			if ((int)fdf->a->x == (int)fdf->b->x)
				break ;
		if (!y_bool)
			if ((int)fdf->a->y == (int)fdf->b->y)
				break ;
		fdf->a->x += x_step;
		fdf->a->y += y_step;
	}
}

void	set_point(int x, int y, t_fdf *fdf)
{
	fdf->a->x = x;
	fdf->a->y = y;
	fdf->a->z = fdf->map[y][x];
	fdf->b->x = x;
	fdf->b->y = y;
	fdf->b->z = fdf->map[y][x];
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
			addr[i * WIDTH + j] = 0x050A10;
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

void	make_it_3d(t_fdf *fdf)
{
	t_img	img;
	void	*image;
	int		i_h;
	int		i_w;

	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		(free_struct(fdf), ft_putstr_fd(MLX_INIT, 2), exit(EXIT_FAILURE));
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "fdf");
	if (!fdf->win)
		(free_struct(fdf), ft_putstr_fd(MLX_WIN, 2), exit(EXIT_FAILURE));
	image = mlx_xpm_file_to_image(fdf->mlx, "assets/fdf.xpm", &i_h, &i_w);
	img.img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!img.img)
		(free_struct(fdf), ft_putstr_fd(MLX_IMG, 2), exit(EXIT_FAILURE));
	fdf->img = &img;
	fill_image(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, img.img, 0, 0);
	mlx_put_image_to_window(fdf->mlx, fdf->win, image, 0, 0);
	// mlx_string_put(fdf->mlx, fdf->win, 120, 120, 0xFFFFFF, "Zoom : + / -");
	// mlx_string_put(fdf->mlx, fdf->win, 120, 140, 0xFFFFFF, "Move : Arrow keys");
	mlx_key_hook(fdf->win, &handle_key, fdf);
	// mlx_mouse_hook(fdf->win, &handle_mouse, NULL);
	mlx_loop(fdf->mlx);
}