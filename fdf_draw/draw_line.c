/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:26:46 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/09 20:41:57 by tamehri          ###   ########.fr       */
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

void	slope_less_then_one(int dx, int dy, t_fdf *fdf)
{
	int	p;
	int	i;

	i = -1;
	p = 2 * abs(dy) - abs(dx);
	while (++i < abs(dx))
	{
		if (dx < 0)
			fdf->a->x -= 1;
		else
			fdf->a->x += 1;
		if (p < 0)
			p = p + 2 * abs(dy);
		else
		{
			if (dy < 0)
				fdf->a->y -= 1;
			else
				fdf->a->y += 1;
			p = p + 2 * abs(dy) - 2 * abs(dx);
		}
		my_mlx_pixel_put(fdf->a->x, fdf->a->y, fdf);
	}
}

void	slope_bigger_than_one(int dx, int dy, t_fdf *fdf)
{
	int	p;
	int	i;

	i = -1;
	p = 2 * abs(dx) - abs(dy);
	while (++i < abs(dy))
	{
		if (dy < 0)
			fdf->a->y -= 1;
		else
			fdf->a->y += 1;
		if (p < 0)
			p = p + 2 * abs(dx);
		else
		{
			if (dx < 0)
				fdf->a->x -= 1;
			else
				fdf->a->x += 1;
			p = p + 2 * abs(dx) - 2 * abs(dy);
		}
		my_mlx_pixel_put(fdf->a->x, fdf->a->y, fdf);
	}
}

void	draw_line(t_fdf *fdf)
{
	int dx;
	int dy;

	fdf->a->z = fdf->map[(fdf->a->y + fdf->height / 2)][(fdf->a->x + fdf->width / 2)] * fdf->z_zoom;
	fdf->b->z = fdf->map[(fdf->b->y + fdf->height / 2)][(fdf->b->x + fdf->width / 2)] * fdf->z_zoom;
	// fdf->color = fdf->color_map[(fdf->b->y + fdf->height / 2)][(fdf->b->x + fdf->width / 2)];
	set_coordinnates(fdf);
	dx = fdf->b->x - fdf->a->x;
	dy = fdf->b->y - fdf->a->y;
	my_mlx_pixel_put(fdf->a->x, fdf->a->y, fdf);
	if (abs(dx) > abs(dy))
		slope_less_then_one(dx, dy, fdf);
	else
		slope_bigger_than_one(dx, dy, fdf);
}
