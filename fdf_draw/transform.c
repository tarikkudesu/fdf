/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:36:28 by tamehri           #+#    #+#             */
/*   Updated: 2024/02/07 20:05:27 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
	fdf->a->x = tmp * cos(fdf->tetha) + fdf->a->z * sin(fdf->tetha);
	fdf->a->z = - tmp * sin(fdf->tetha) + fdf->a->z * cos(fdf->tetha);
	tmp = fdf->b->x;
	fdf->b->x = tmp * cos(fdf->tetha) + fdf->b->z * sin(fdf->tetha);
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
	fdf->a->x = (tmp - fdf->a->y) * cos(ANGLE);
	fdf->a->y = (tmp + fdf->a->y) * sin(ANGLE) - fdf->a->z;
	tmp = fdf->b->x;
	fdf->b->x = (tmp - fdf->b->y) * cos(ANGLE);
	fdf->b->y = (tmp + fdf->b->y) * sin(ANGLE) - fdf->b->z;
}

void	set_coordinnates(t_fdf *fdf)
{
	fdf->a->x *= fdf->zoom;
	fdf->b->x *= fdf->zoom;
	fdf->a->y *= fdf->zoom;
	fdf->b->y *= fdf->zoom;
	fdf->a->z *= fdf->zoom;
	fdf->b->z *= fdf->zoom;
	rotate_z(fdf);
	rotate_y(fdf);
	rotate_x(fdf);
	isometric(fdf);
	fdf->a->x += fdf->x_offset;
	fdf->b->x += fdf->x_offset;
	fdf->a->y += fdf->y_offset;
	fdf->b->y += fdf->y_offset;
}
