/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:26:46 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/23 09:27:56 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put_big(int x, int y, t_fdf *fdf)
{
	char	*addr;
	int		pixel;

	addr = fdf->img->addr;
	pixel = y * fdf->img->line_bytes + x * 4;
	if (x < WIDTH && x > 0 && y < HEIGHT && y > 0)
	{
		addr[pixel + 0] = ((fdf->a->color >> 0) & 255) + \
		(((fdf->b->color >> 0) & 255) - ((fdf->a->color >> 0) \
		& 255)) * perc(fdf->a->y, fdf->b->y, y);
		addr[pixel + 1] = ((fdf->a->color >> 8) & 255) + \
		(((fdf->b->color >> 8) & 255) - ((fdf->a->color >> 8) \
		& 255)) * perc(fdf->a->y, fdf->b->y, y);
		addr[pixel + 2] = ((fdf->a->color >> 16) & 255) + \
		(((fdf->b->color >> 16) & 255) - ((fdf->a->color >> 16) \
		& 255)) * perc(fdf->a->y, fdf->b->y, y);
		addr[pixel + 3] = ((fdf->a->color >> 24) & 255) + \
		(((fdf->b->color >> 24) & 255) - ((fdf->a->color >> 24) \
		& 255)) * perc(fdf->a->y, fdf->b->y, y);
	}
}

void	my_mlx_pixel_put_less(int x, int y, t_fdf *fdf)
{
	char	*addr;
	int		pixel;

	addr = fdf->img->addr;
	pixel = y * fdf->img->line_bytes + x * 4;
	if (x < WIDTH && x > 0 && y < HEIGHT && y > 0)
	{
		addr[pixel + 0] = ((fdf->a->color >> 0) & 255) + \
		(((fdf->b->color >> 0) & 255) - ((fdf->a->color >> 0) \
		& 255)) * perc(fdf->a->x, fdf->b->x, x);
		addr[pixel + 1] = ((fdf->a->color >> 8) & 255) + \
		(((fdf->b->color >> 8) & 255) - ((fdf->a->color >> 8) \
		& 255)) * perc(fdf->a->x, fdf->b->x, x);
		addr[pixel + 2] = ((fdf->a->color >> 16) & 255) + \
		(((fdf->b->color >> 16) & 255) - ((fdf->a->color >> 16) \
		& 255)) * perc(fdf->a->x, fdf->b->x, x);
		addr[pixel + 3] = ((fdf->a->color >> 24) & 255) + \
		(((fdf->b->color >> 24) & 255) - ((fdf->a->color >> 24) \
		& 255)) * perc(fdf->a->x, fdf->b->x, x);
	}
}

void	slope_less_then_one(int p, int dx, int dy, t_fdf *fdf)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	x = fdf->a->x;
	y = fdf->a->y;
	while (++i < abs(dx))
	{
		if (dx < 0)
			x -= 1;
		else
			x += 1;
		if (p < 0)
			p = p + 2 * abs(dy);
		else
		{
			if (dy < 0)
				y -= 1;
			else
				y += 1;
			p = p + 2 * abs(dy) - 2 * abs(dx);
		}
		my_mlx_pixel_put_less(x, y, fdf);
	}
}

void	slope_bigger_than_one(int p, int dx, int dy, t_fdf *fdf)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	x = fdf->a->x;
	y = fdf->a->y;
	while (++i < abs(dy))
	{
		if (dy < 0)
			y -= 1;
		else
			y += 1;
		if (p < 0)
			p = p + 2 * abs(dx);
		else
		{
			if (dx < 0)
				x -= 1;
			else
				x += 1;
			p = p + 2 * abs(dx) - 2 * abs(dy);
		}
		my_mlx_pixel_put_big(x, y, fdf);
	}
}

void	draw_line(t_fdf *fdf)
{
	int	dx;
	int	dy;

	fdf->a->z = fdf->map[(fdf->a->y + fdf->height / 2)] \
	[(fdf->a->x + fdf->width / 2)] * fdf->z_incr;
	fdf->b->z = fdf->map[(fdf->b->y + fdf->height / 2)] \
	[(fdf->b->x + fdf->width / 2)] * fdf->z_incr;
	fdf->a->color = fdf->color_map[(fdf->a->y + fdf->height / 2)] \
	[(fdf->a->x + fdf->width / 2)];
	fdf->b->color = fdf->color_map[(fdf->b->y + fdf->height / 2)] \
	[(fdf->b->x + fdf->width / 2)];
	set_coordinnates(fdf);
	dx = fdf->b->x - fdf->a->x;
	dy = fdf->b->y - fdf->a->y;
	my_mlx_pixel_put_less(fdf->a->x, fdf->a->y, fdf);
	if (abs(dx) > abs(dy))
		slope_less_then_one(2 * abs(dy) - abs(dx), dx, dy, fdf);
	else
		slope_bigger_than_one(2 * abs(dx) - abs(dy), dx, dy, fdf);
}
