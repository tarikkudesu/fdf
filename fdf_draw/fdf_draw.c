/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:08:30 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/06 20:27:14 by tamehri          ###   ########.fr       */
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

void	rotate_z(t_fdf *fdf)
{
	float	tmp;

	tmp = fdf->a->x;
	fdf->a->x = tmp * cos(fdf->gamma) - fdf->a->y * sin(fdf->gamma);
	fdf->a->y = tmp * sin(fdf->gamma) + fdf->a->y * cos(fdf->gamma);
	tmp = fdf->b->x;
	fdf->b->x = tmp * cos(fdf->gamma) - fdf->b->y * sin(fdf->gamma);
	fdf->b->y = tmp * sin(fdf->gamma) + fdf->b->y * cos(fdf->gamma);
}

void	rotate_y(t_fdf *fdf)
{
	float	tmp;

	tmp = fdf->a->x;
	fdf->a->x = tmp * cos(fdf->tetha) - fdf->a->z * sin(fdf->tetha);
	fdf->a->z = - tmp * sin(fdf->tetha) + fdf->a->z * cos(fdf->tetha);
	tmp = fdf->b->x;
	fdf->b->x = tmp * cos(fdf->tetha) - fdf->b->z * sin(fdf->tetha);
	fdf->b->z = - tmp * sin(fdf->tetha) + fdf->b->z * cos(fdf->tetha);
}

void	rotate_x(t_fdf *fdf)
{
	float	tmp;

	tmp = fdf->a->y;
	fdf->a->y = tmp * cos(fdf->alpha) - fdf->a->z * sin(fdf->alpha);
	fdf->a->z = tmp * sin(fdf->alpha) + fdf->a->z * cos(fdf->alpha);
	tmp = fdf->b->y;
	fdf->b->y = tmp * cos(fdf->alpha) - fdf->b->z * sin(fdf->alpha);
	fdf->b->z = tmp * sin(fdf->alpha) + fdf->b->z * cos(fdf->alpha);
}

void	isometric(t_fdf *fdf)
{
	float	tmp;

	tmp = fdf->a->x;
	fdf->a->x = (tmp - fdf->a->y) * cos(0.523599);
	fdf->a->y = (tmp + fdf->a->y) * sin(0.523599);
	tmp = fdf->b->x;
	fdf->b->x = (tmp - fdf->b->y) * cos(0.523599);
	fdf->b->y = (tmp + fdf->b->y) * sin(0.523599);
}

void	set_coordinnates(t_fdf *fdf)
{
	(void)fdf;
	fdf->a->x *= fdf->x_zoom;
	fdf->b->x *= fdf->x_zoom;
	fdf->a->y *= fdf->y_zoom;
	fdf->b->y *= fdf->y_zoom;
	rotate_z(fdf);
	rotate_y(fdf);
	rotate_x(fdf);
	isometric(fdf);
	fdf->a->x += fdf->x_offset;
	fdf->b->x += fdf->x_offset;
	fdf->a->y += fdf->y_offset;
	fdf->b->y += fdf->y_offset;
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
			a.x = x;
			a.y = y;
			a.z = fdf->map[y][x];
			b.x = x + 1;
			b.y = y;
			b.z = fdf->map[y][x];
			if (x + 1 < fdf->width)
				draw_line(fdf);
			a.x = x;
			a.y = y;
			a.z = fdf->map[y][x];
			b.x = x;
			b.y = y + 1;
			b.z = fdf->map[y][x];
			if (y + 1 < fdf->height)
				draw_line(fdf);
		}
	}
}

// void	draw_map(t_fdf *fdf)
// {
// 	t_line	line;
// 	int		x;
// 	int		y;

// 	design_img(fdf);
// 	fdf->line = &line;
// 	x = -1;
// 	while (++x < fdf->width)
// 	{
// 		y = -1;
// 		while (++y < fdf->height)
// 		{
// 			line.x1 = x;
// 			line.y1 = y;
// 			line.z1 = fdf->map[y][x];
// 			if (x + 1 < fdf->width)
// 				draw_line(x + 1, y, fdf);
// 			line.x1 = x;
// 			line.y1 = y;
// 			line.z1 = fdf->map[y][x];
// 			if (y + 1 < fdf->height)
// 				draw_line(x, y + 1, fdf);
// 		}
// 	}
// }

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
	// interface(fdf);
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