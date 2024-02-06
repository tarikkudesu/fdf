/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:08:30 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/06 11:17:19 by tamehri          ###   ########.fr       */
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

void	isometric(t_fdf *fdf)
{
	float	o_x1;
	float	o_x2;

	o_x1 = fdf->line->x1;
	fdf->line->x1 = (fdf->line->x1 - fdf->line->y1) / 2;
	fdf->line->y1 = (o_x1 + fdf->line->y1) / 2 - fdf->line->z1;
	o_x2 = fdf->line->x2;
	fdf->line->x2 = (fdf->line->x2 - fdf->line->y2) / 2;
	fdf->line->y2 = (o_x2 + fdf->line->y2) / 2 - fdf->line->z2;
}

void	set_coordinnates(t_fdf *fdf)
{
	fdf->line->x1 *= fdf->x_zoom;
	fdf->line->x2 *= fdf->x_zoom;
	fdf->line->y1 *= fdf->y_zoom;
	fdf->line->y2 *= fdf->y_zoom;
	// fdf->line->z1 *= fdf->z_zoom;
	// fdf->line->z2 *= fdf->z_zoom;
	// isometric(fdf);
	fdf->line->x1 += fdf->x_offset;
	fdf->line->x2 += fdf->x_offset;
	fdf->line->y1 += fdf->y_offset;
	fdf->line->y2 += fdf->y_offset;
}

void swap_2(t_line *line)
{
	int	x1;
	int	y1;
	
	x1 = line->x1;
	line->x1 = line->x2;
	line->x2 = x1;
	y1 = line->y1;
	line->y1 = line->y2;
	line->y2 = y1;
}
void swap_(t_line *line)
{
    int temp = line->x1;
    line->x1 = line->y1;
    line->y1 = temp;
    temp = line->x2;
    line->x2 = line->y2;
    line->y2 = temp;
}

void	draw_line(int x2, int y2, t_fdf *fdf)
{
	fdf->line->x2 = x2;
	fdf->line->y2 = y2;
	fdf->line->z2 = fdf->map[y2][x2];
	set_coordinnates(fdf);

    if (abs(fdf->line->y2 - fdf->line->y1) > abs(fdf->line->x2 - fdf->line->x1)) {
        swap_(fdf->line);
    }

    if (fdf->line->x1 > fdf->line->x2) {
		swap_2(fdf->line);
    }

    int dx = fdf->line->x2 - fdf->line->x1;
    int dy = fdf->line->y2 - fdf->line->y1;
    float gradient = (float)dy / (float)dx;

    float error = -0.5;

    for (int x = fdf->line->x1; x <= fdf->line->x2; x++) {
        int y = (int)(fdf->line->y1 + error);
        my_mlx_pixel_put(x, y, fdf);
        error += gradient;
    }
}

// void	draw_line(int x2, int y2, t_fdf *fdf)
// {
// 	float	x_step;
// 	float	y_step;
// 	float	max;
	
// 	fdf->line->x2 = x2;
// 	fdf->line->y2 = y2;
// 	fdf->line->z2 = fdf->map[y2][x2];
// 	set_coordinnates(fdf);
// 	x_step = fdf->line->x2 - fdf->line->x1;
// 	y_step = fdf->line->y2 - fdf->line->y1;
// 	max = max_value(abs_float_value(x_step), abs_float_value(y_step));
// 	x_step /= max;
// 	y_step /= max;
// 	printf("=================\n");
// 	while (1)
// 	{
// 		printf("(%.1f, %.1f) => (%.1f, %.1f)\n", fdf->line->x1, fdf->line->y1, fdf->line->x2, fdf->line->y2);
// 		my_mlx_pixel_put(fdf->line->x1, fdf->line->y1, fdf);
// 		if ((int)fdf->line->x1 == (int)fdf->line->x2)
// 			break ;
// 		if ((int)fdf->line->y1 == (int)fdf->line->y2)
// 			break ;
// 		fdf->line->x1 += x_step;
// 		fdf->line->y1 += y_step;
// 	}
// }

void	draw_map(t_fdf *fdf)
{
	t_line	line;
	int		x;
	int		y;

	design_img(fdf);
	fdf->line = &line;
	x = -1;
	while (++x < fdf->width)
	{
		y = -1;
		while (++y < fdf->height)
		{
			line.x1 = x;
			line.y1 = y;
			line.z1 = fdf->map[y][x];
			if (x + 1 < fdf->width)
				draw_line(x + 1, y, fdf);
			line.x1 = x;
			line.y1 = y;
			line.z1 = fdf->map[y][x];
			if (y + 1 < fdf->height)
				draw_line(x, y + 1, fdf);
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