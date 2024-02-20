/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:36:28 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/20 15:16:37 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_z(t_fdf *fdf)
{
	int	tmp;

	tmp = fdf->a->x;
	fdf->a->x = tmp * cos(fdf->gamma) - fdf->a->y * sin(fdf->gamma);
	fdf->a->y = tmp * sin(fdf->gamma) + fdf->a->y * cos(fdf->gamma);
	tmp = fdf->b->x;
	fdf->b->x = tmp * cos(fdf->gamma) - fdf->b->y * sin(fdf->gamma);
	fdf->b->y = tmp * sin(fdf->gamma) + fdf->b->y * cos(fdf->gamma);
}

void	rotate_x(t_fdf *fdf)
{
	int	tmp;

	tmp = fdf->a->y;
	fdf->a->y = tmp * cos(fdf->alpha) - fdf->a->z * sin(fdf->alpha);
	fdf->a->z = tmp * sin(fdf->alpha) + fdf->a->z * cos(fdf->alpha);
	tmp = fdf->b->y;
	fdf->b->y = tmp * cos(fdf->alpha) - fdf->b->z * sin(fdf->alpha);
	fdf->b->z = tmp * sin(fdf->alpha) + fdf->b->z * cos(fdf->alpha);
}

void	set_coordinnates(t_fdf *fdf)
{
	fdf->a->x *= (WIDTH / fdf->width) / 2;
	fdf->b->x *= (WIDTH / fdf->width) / 2;
	fdf->a->y *= (WIDTH / fdf->width) / 2;
	fdf->b->y *= (WIDTH / fdf->width) / 2;
	fdf->a->z *= fdf->z_zoom;
	fdf->b->z *= fdf->z_zoom;
	rotate_z(fdf);
	rotate_x(fdf);
	fdf->a->x += WIDTH / 2;
	fdf->b->x += WIDTH / 2;
	fdf->a->y += HEIGHT / 2;
	fdf->b->y += HEIGHT / 2;
}
